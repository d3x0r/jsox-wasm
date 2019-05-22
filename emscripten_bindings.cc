#include <stdint.h>
#include <cmath> 
#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace emscripten;
#include "global.h"
#include "jsox.h"

struct a {
};


//#define MODE NewStringType::kInternalized

static inline val makeValue( struct jsox_value_container *val, struct reviver_data *revive ) {

	class val result(NULL);
	switch( val->value_type ) {
	case JSOX_VALUE_UNDEFINED:
		result = val::undefined();
		break;
	default:
		if( val->value_type >= JSOX_VALUE_TYPED_ARRAY && val->value_type <= JSOX_VALUE_TYPED_ARRAY_MAX ) {
			class val ab = emscripten::val::global("ArrayBuffer").new_( val->stringLen );			
			//Local<ArrayBuffer> ab = ArrayBuffer::New( revive->isolate, val->string, val->stringLen, ArrayBufferCreationMode::kExternalized );
			switch( val->value_type - JSOX_VALUE_TYPED_ARRAY ) {
			case 0:
				result = ab;
				break;
			case 1: // "u8"
				result = emscripten::val::global("Uint8Array").new_(ab);
				break;
			case 2:// "cu8"
				result = emscripten::val::global("Uint8ClampedArray").new_(ab);
				break;
			case 3:// "s8"
				result = emscripten::val::global("Int8Array").new_(ab);
				break;
			case 4:// "u16"
				result = emscripten::val::global("Uint16Array").new_(ab);
				break;
			case 5:// "s16"
				result = emscripten::val::global("Int16Array").new_(ab);
				break;
			case 6:// "u32"
				result = emscripten::val::global("Uint32Array").new_(ab);
				break;
			case 7:// "s32"
				result = emscripten::val::global("Int32Array").new_(ab);
				break;
			//case 8:// "u64"
			//	result = Uint64Array::New( ab, 0, val->stringLen );
			//	break;
			//case 9:// "s64"
			//	result = Int64Array::New( ab, 0, val->stringLen );
			//	break;
			case 10:// "f32"
				result = emscripten::val::global("Float32Array").new_(ab);
				break;
			case 11:// "f64"
				result = emscripten::val::global("Float64Array").new_(ab);
				break;
			default:
				result = emscripten::val::undefined();
			}
		}
		else {
			lprintf( "Parser faulted; should never have a uninitilized value." );
			result = emscripten::val::undefined();
		}
		break;
	case JSOX_VALUE_NULL:
		result = emscripten::val::null();
		break;
	case JSOX_VALUE_TRUE:
		result = emscripten::val(true);
		break;
	case JSOX_VALUE_FALSE:
		result = emscripten::val(false);
		break;
	case JSOX_VALUE_EMPTY:
		result = emscripten::val::undefined();
		break;
	case JSOX_VALUE_STRING:
		result = emscripten::val( std::string( val->string, val->stringLen ) );
		break;
	case JSOX_VALUE_NUMBER:
		if( val->float_result )  {
			result = emscripten::val( val->result_d );
		} else {
			result = emscripten::val( (int)val->result_n );
		}
		break;
	case JSOX_VALUE_ARRAY:
		result = emscripten::val::array();
		break;
	case JSOX_VALUE_OBJECT:
		if( val->className )
		result = emscripten::val::object();
		break;
	case JSOX_VALUE_NEG_NAN:
		result = emscripten::val(-nan(""));
		break;
	case JSOX_VALUE_NAN:
		result = emscripten::val(nan(""));
		break;
	case JSOX_VALUE_NEG_INFINITY:
		result = emscripten::val(-INFINITY);
		break;
	case JSOX_VALUE_INFINITY:
		result = emscripten::val(INFINITY);
		break;
	case JSOX_VALUE_BIGINT:
		{
		class val bigint = emscripten::val::global("BigInt");
		//if( bigint ) {
			result = bigint.new_( std::string( val->string, val->stringLen-1 ) );
		//}
		}
		break;
	case JSOX_VALUE_DATE:
		{
		class val date = emscripten::val::global("Date");
		result = date.new_( std::string( val->string, val->stringLen ) );
		}
		//result = Date::New( revive->isolate, 0 );
		break;
	}
	if( revive->revive ) {
		//result = revive->reviver.call<val>( revive->value, result );
	}
	return result;
}

static void buildObject( PDATALIST msg_data, class val o, struct reviver_data *revive ) {
	val thisVal(NULL);
	std::string stringKey;
	class val thisKey(NULL);
	LOGICAL saveRevive = revive->revive;
	struct jsox_value_container *value;
	class val sub_o(NULL);
	INDEX idx;
	int index = 0;
	DATA_FORALL( msg_data, idx, struct jsox_value_container*, value )
	{
		//lprintf( "value name is : %d %s", value->value_type, value->name ? value->name : "(NULL)" );
		switch( value->value_type ) {
		default:
			if( value->name ) {				
				thisKey = val(stringKey=std::string( value->name, value->nameLen ));
				revive->value = thisKey;
				o.set( stringKey, makeValue( value, revive ) );
			}
			else {
				if( value->value_type == JSOX_VALUE_EMPTY )
					revive->revive = FALSE;
				if( revive->revive )
					revive->value = val( index );
				o.set( index++, thisVal = makeValue( value, revive ) );
				if( value->value_type == JSOX_VALUE_EMPTY )
					;//o.delete( revive->context, index - 1 );
			}
			revive->revive = saveRevive;
			break;
		case JSOX_VALUE_ARRAY:
			if( value->name ) {
				o.set( stringKey = std::string( value->name, (int)value->nameLen )
					, sub_o = val::array() );
				thisKey = val(stringKey);
			}
			else {
				if( revive->revive )
					thisKey = val( index );
				o.set( index++, sub_o = val::array() );
			}
			buildObject( value->contains, sub_o, revive );
			if( revive->revive ) {
				//Local<Value> args[2] = { thisKey, sub_o };
				//revive->reviver.call<val>( revive->_this, thisKey, sub_o );
			}
			break;
		case JSOX_VALUE_OBJECT:
			if( value->name ) {
				stringKey = std::string( value->name, value->nameLen );
				o.set( stringKey, sub_o = val::object() );
				thisKey = val(stringKey);
			}
			else {
				if( revive->revive )
					thisKey = val( index );
				o.set( index++, sub_o = val::object() );
			}

			buildObject( value->contains, sub_o, revive );
			if( revive->revive ) {
				//Local<Value> args[2] = { thisKey, sub_o };
				//revive->reviver->Call( revive->_this, 2, args );
			}
			break;
		}
	}
}

val convertMessageToJS2( PDATALIST msg, struct reviver_data *revive ) {
	val o(NULL);
	val v(NULL);// = Object::New( revive->isolate );

	struct jsox_value_container *value = (struct jsox_value_container *)GetDataItem( &msg, 0 );
	if( value && value->contains ) {
		if( value->value_type == JSOX_VALUE_OBJECT )
			o = val::object();
		else if( value->value_type == JSOX_VALUE_ARRAY )
			o = val::array();
		else
			lprintf( "Value has contents, but is not a container type?!" );
		buildObject( value->contains, o, revive );
		return o;
	}
	if( value )
		return makeValue( value, revive );
	return val::undefined();
}


val ParseJSOX(  const char *utf8String, size_t len, struct reviver_data *revive ) {
	printf( "received somethign? %d %s\n", len, utf8String );

	PDATALIST parsed = NULL;


	if( !jsox_parse_message( (char*)utf8String, len, &parsed ) ) {
		//PTEXT error = jsox_parse_get_error( parser->state );
		//lprintf( "Failed to parse data..." );
		printf( "THROWING AN ERROR\n" );
		PTEXT error = jsox_parse_get_error( NULL );
		if( error )      {
			printf( "ERROR:%s\n", GetText( error ) );
			throw GetText( error );
		}
		else {
			printf( "Not actually an error?\n" );
			throw "No Error Text";
		}
		LineRelease( error );
		return val::undefined();
	}
	if( parsed && parsed->Cnt > 1 ) {
		lprintf( "Multiple values would result, invalid parse." );
		return val::undefined();
		// outside should always be a single value
	}
        //logTick(3);
	val value = convertMessageToJS2( parsed, revive );
        //logTick(4);

	jsox_dispose_message( &parsed );
        //logTick(5);

	return value;
	//return val::undefined();
}


val jsox_parse( emscripten::val string, emscripten::val reviver ) {
	//logTick(0);
	struct reviver_data *r = new reviver_data();

//.._malloc and stringToUTF8()
//If you need a string to live forever, you can create it, for example, using _malloc and stringToUTF8(). However, you must later delete it manually!
printf( "convertin to string...\n" );
	std::string s = string.as<std::string>();
printf( "confted string:%s", s.c_str() );
	if( reviver.as<bool>() ) {
		//r._this = args.Holder();
		r->value = val( "" );
		r->revive = TRUE;
		r->reviver = reviver;
	}
	else {
		r->revive = FALSE;
	}

	return ParseJSOX( s.c_str(), s.length(), r );
}


EMSCRIPTEN_BINDINGS(my_module) {
    function("JSOXParse", jsox_parse );
}

