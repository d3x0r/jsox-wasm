#include <stdint.h>


#include <stdint.h>
#include <emscripten.h>

//using namespace emscripten;

//#include "global.h"
#include "jsox.h"

//
// Pointer_stringify for transforming a char * containing a UTF8 string to a  JS string, and intArrayFromString t
//

struct reviver_data {
	
	LOGICAL revive;
	//int index;
	int value;
	int _this;
	int reviver_func;
	int rootObject;
	//class JSOXObject *parser;
};



struct objectStates {
	PDATALIST pldObjects;
	
};

enum buildinTypes {
	JS_VALUE_UNDEFINED,
	JS_VALUE_FALSE,
	JS_VALUE_TRUE,
	JS_VALUE_NULL,
	JS_VALUE_NEG_INFINITY,
	JS_VALUE_INFINITY,
	JS_VALUE_NAN,
};

static void throwError( char *error ){
	EM_ASM( {
		const string = UTF8ToString( $0 );
		throw new Error( str );
	},error);
}

void initJSOX() {
	EM_ASM( (
		Module.this_ = {
			types : new Map(),
			objects : [undefined,false,true,null,-Infinity,Infinity,NaN],
			reset() {
				this.objects.length = 7;
			}
		};

		Module.begin = function(cb) {
			return {
				this_ : {
					objects : [],
					parser : Module._jsox_begin_parse(),
					prototypes : null
				},
				write(data){
					var s;
					var i = allocate(s = intArrayFromString(str), 'i8', ALLOC_NORMAL);
					Module._jsox_write( i, s.length );
					//console.log( "Got strg:", str, cb, s );
				},
				registerFromJSOX(typeName,fromCb) {

				}
			}
		};
		Module.escape = function() {

		};
		Module.registerToJSOX = function(typeName,prototype,cb)  {
			//var types = 
		};
		Module.registerFromJSOX = function(typeName,fromCb) {

		};
		Module.registerToFrom = function(name,prototype,toCb, fromCb) {

		};
		Module.makeFunction = function(cb){
			return Module.this_.objects.push(cb) -1
		};
		Module.makeString = function(str){
			return Module.this_.objects.push(str)-1
		};

		// static buffer state; removing this reallocation saved 10%
		var buf_heap;
		var buf;
		var buf_len = 0;
		Module.parse = function( str, cb ) {
			var s;
			var len = str.length*4;
			var outpos = 0;
			if( len > buf_len ) {
				if( buf_heap )
			        	Module._free( buf_heap );
				 buf_heap = Module._malloc( len );
				 buf = new Uint8Array( Module.HEAPU8.buffer, buf_heap, len );
				buf_len = len;
			}
			for (var i=0; i < str.length; i++) {
				var charcode = str.charCodeAt(i);
				if (charcode < 0x80) buf[outpos++] = (charcode);
				else if (charcode < 0x800) {
					buf[outpos++] = 0xc0 | (charcode >> 6);
					buf[outpos++] = 0x80 | (charcode & 0x3f);
				}
				else if ( ( charcode < 0xd800 ) || ( charcode >= 0xe000 ) ) {
					buf[outpos++] = 0xe0 | (charcode >> 12);
					buf[outpos++] = 0x80 | ((charcode>>6) & 0x3f);
					buf[outpos++] = 0x80 | (charcode & 0x3f);
				}
				else {
					i++;
					// UTF-16 encodes 0x10000-0x10FFFF by
					// subtracting 0x10000 and splitting the
					// 20 bits of 0x0-0xFFFFF into two halves
					charcode = 0x10000 + (((charcode & 0x3ff)<<10)
							  | (str.charCodeAt(i) & 0x3ff));
					buf[outpos++] = 0xf0 | (charcode >>18);
					buf[outpos++] = 0x80 | ((charcode>>12) & 0x3f);
					buf[outpos++] = 0x80 | ((charcode>>6) & 0x3f);
					buf[outpos++] = 0x80 | (charcode & 0x3f);
				}
			}
			//console.log( "Got strg:", str, cb, s );
			var result = Module.this_.objects[ Module._jsox_parse( buf_heap, outpos, Module.makeFunction(cb) ) ];
			Module.this_.objects.length = 0;
		        return result;
		};
		console.log( "Module should have gotten methods?");
	), 0 );
}


void defineFunction( cb ){

}

#define  makeObject() EM_ASM_INT( { return Module.this_.objects .push( {} )-1; })

#define  makeArray() EM_ASM_INT( { return Module.this_.objects .push( [] )-1; })



static inline int makeString( char *string, int stringlen ) {
	int x = EM_ASM_INT( {
		const string = UTF8ToString( $0, $1 );
		return Module.this_.objects.push( string )-1;
	},string, stringlen);
	return x;
}

static inline int makeArrayBuffer(int len) {
	return EM_ASM_INT( {
		return Module.this_.objects .push( new ArrayBuffer($0) )-1;
	},len);
}

static inline int makeBigInt( char *s, int n ) {
	return EM_ASM_INT( {
		const string = UTF8ToString( $0, $1 );
		return Module.this_.objects .push( BigInt(string) )-1;
	},n);
}

static inline int makeDate( char *s, int n ) {
	return EM_ASM_INT( {
		const string = UTF8ToString( $0, $1 );
		return Module.this_.objects .push( new Date(string) )-1;
	},n);
}


static inline int makeNumber( int n ) {
	return EM_ASM_INT( {
		return Module.this_.objects .push( $0 )-1;
	},n);
}

static inline int makeNumberf( double n ) {
	return EM_ASM_INT( {
		return Module.this_.objects .push( $0 )-1;
	},n);
}

static inline int makeTypedArray(int ab, int type ) {
	return EM_ASM_INT( {
		var ab = Module.this_.objects[$0];
		//console.log( "This:", Module.this_, Object.getPrototypeOf( Module.this_ ) );
			switch( $1 ) {
			case 0:
				result = $0;
				break;
			case 1: // "u8"
				Module.this_.objects .push( new Uint8Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			case 2:// "cu8"
				Module.this_.objects .push( new Uint8ClampedArray(ab) );
				result = Module.this_.objects.length-1;
				break;
			case 3:// "s8"
				Module.this_.objects .push( new Int8Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			case 4:// "u16"
				Module.this_.objects .push( new Uint16Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			case 5:// "s16"
				Module.this_.objects .push( new Int16Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			case 6:// "u32"
				Module.this_.objects .push( new Uint32Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			case 7:// "s32"
				Module.this_.objects .push( new Int32Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			//case 8:// "u64"
			//	result = Uint64Array::New( ab, 0, val->stringLen );
			//	break;
			//case 9:// "s64"
			//	result = Int64Array::New( ab, 0, val->stringLen );
			//	break;
			case 10:// "f32"
				Module.this_.objects .push( new Float32Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			case 11:// "f64"
				Module.this_.objects .push( new Float64Array(ab) );
				result = Module.this_.objects.length-1;
				break;
			default:
				result = 0; // undefined constant
			}
		return result;
	}, ab, type );
}


static inline void setObject( int object, int field, int value ) {
	EM_ASM_( {
		const fieldName = Module.this_.objects[$1];
		Module.this_.objects[$0][fieldName] = Module.this_.objects[$2]; 
		//console.log( "We Good?", Module.this_.objects )
	}, object, field, value);
}

static void setObjectByIndex( int object, int index, int value ) {
	EM_ASM_( {
		Module.this_.objects[$0][$1] = Module.this_.objects[$2]; 
	}, object, index, value);
}

static void setObjectByName( int object, char*field, int value ) {
	EM_ASM_( {
		const fieldName = Pointer_stringify( $1 );
		Module.this_.objects[$0][fieldName] = Module.this_.objects[$2]; 
		//console.log( "We Good?", Module.this_.objects )
	}, object, field, value);
}


//#define MODE NewStringType::kInternalized

static inline int makeValue( struct jsox_value_container *val, struct reviver_data *revive ) {

	int result = -1;
	switch( val->value_type ) {
	case JSOX_VALUE_UNDEFINED:
		result = JS_VALUE_UNDEFINED;
		break;
	default:
		if( val->value_type >= JSOX_VALUE_TYPED_ARRAY && val->value_type <= JSOX_VALUE_TYPED_ARRAY_MAX ) {
			int ab = makeArrayBuffer( val->stringLen );			
			makeTypedArray( ab, val->value_type - JSOX_VALUE_TYPED_ARRAY );
			//Local<ArrayBuffer> ab = ArrayBuffer::New( revive->isolate, val->string, val->stringLen, ArrayBufferCreationMode::kExternalized );
		}
		else {
			lprintf( "Parser faulted; should never have a uninitilized value." );
			result = 0;
		}
		break;
	case JSOX_VALUE_NULL:
		result = JS_VALUE_NULL;
		break;
	case JSOX_VALUE_TRUE:
		result = JS_VALUE_TRUE;
		break;
	case JSOX_VALUE_FALSE:
		result = JS_VALUE_FALSE;
		break;
	case JSOX_VALUE_EMPTY:
		result = JS_VALUE_UNDEFINED;
		break;
	case JSOX_VALUE_STRING:
		result = makeString( val->string, val->stringLen );
		break;
	case JSOX_VALUE_NUMBER:
		if( val->float_result )  {
			result = EM_ASM_INT( { return Module.this_.objects .push( $0 )-1; },val->result_d);
		} else {
			result = EM_ASM_INT( { return Module.this_.objects .push( $0 )-1; },(int)val->result_n);
		}
		break;
	case JSOX_VALUE_ARRAY:
		result = makeArray();
		break;
	case JSOX_VALUE_OBJECT:
		if( val->className )
			result = makeObject();
		break;
	case JSOX_VALUE_NEG_NAN:
		result = JS_VALUE_NAN;
		break;
	case JSOX_VALUE_NAN:
		result = JS_VALUE_NAN;
		break;
	case JSOX_VALUE_NEG_INFINITY:
		result = JS_VALUE_NEG_INFINITY;
		break;
	case JSOX_VALUE_INFINITY:
		result = JS_VALUE_INFINITY;
		break;
	case JSOX_VALUE_BIGINT:
		result = makeBigInt( val->string, val->stringLen-1 ); // cannot convert with 'n' suffix.
		break;
	case JSOX_VALUE_DATE:
		result =makeDate( val->string, val->stringLen );
		break;
	}
	if( revive->revive ) {
		//result = revive->reviver.call<val>( revive->value, result );
	}
	return result;
}

static void buildObject( PDATALIST msg_data, int o, struct reviver_data *revive ) {
	int thisVal = JS_VALUE_NULL;
	//std::string stringKey;
	int thisKey = JS_VALUE_NULL;
	LOGICAL saveRevive = revive->revive;
	struct jsox_value_container *value;
	int sub_o = JS_VALUE_NULL;
	INDEX idx;
	int index = 0;
	DATA_FORALL( msg_data, idx, struct jsox_value_container*, value )
	{
		//lprintf( "value name is : %d %s", value->value_type, value->name ? value->name : "(NULL)" );
		switch( value->value_type ) {
		default:
			if( value->name ) {				
				thisKey = makeString( value->name, value->nameLen );
				revive->value = thisKey;
				setObject( o, thisKey, makeValue( value, revive ) );
			}
			else {
				if( value->value_type == JSOX_VALUE_EMPTY )
					revive->revive = FALSE;
				if( revive->revive )
					revive->value = makeNumber( index );
				setObjectByIndex( o, index++, thisVal = makeValue( value, revive ) );
				if( value->value_type == JSOX_VALUE_EMPTY )
					;//o.delete( revive->context, index - 1 );
			}
			revive->revive = saveRevive;
			break;
		case JSOX_VALUE_ARRAY:
			if( value->name ) {
				setObjectByName( o, value->name, sub_o = makeArray() );
			}
			else {
				if( revive->revive )
					thisKey = makeNumber( index );
				setObjectByIndex( o, index++, sub_o = makeArray() );
			}
			buildObject( value->contains, sub_o, revive );
			if( revive->revive ) {
				//Local<Value> args[2] = { thisKey, sub_o };
				//revive->reviver.call<val>( revive->_this, thisKey, sub_o );
			}
			break;
		case JSOX_VALUE_OBJECT:
			if( value->name ) {
				//if( revive->revive )
				//	revive->value = makeString( value->name, value->nameLen );
				setObjectByName( o, value->name, sub_o = makeObject() );
			}
			else {
				//if( revive->revive )
				//	revive->value = makeNumber( index );
				setObjectByIndex( o, index++, sub_o = makeObject() );
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

int convertMessageToJS2( PDATALIST msg, struct reviver_data *revive ) {
	int o = JS_VALUE_NULL;
	int v = JS_VALUE_NULL;// = Object::New( revive->isolate );

	struct jsox_value_container *value = (struct jsox_value_container *)GetDataItem( &msg, 0 );
	if( value && value->contains ) {
		if( value->value_type == JSOX_VALUE_OBJECT )
			o = makeObject();
		else if( value->value_type == JSOX_VALUE_ARRAY )
			o = makeArray();
		else
			lprintf( "Value has contents, but is not a container type?!" );
		buildObject( value->contains, o, revive );
		return o;
	}
	if( value )
		return makeValue( value, revive );
	return JS_VALUE_UNDEFINED;
}


int ParseJSOX(  const char *utf8String, size_t len, struct reviver_data *revive ) {
	//printf( "received somethign? %d %s\n", len, utf8String );

	PDATALIST parsed = NULL;


	if( !jsox_parse_message( (char*)utf8String, len, &parsed ) ) {
		//PTEXT error = jsox_parse_get_error( parser->state );
		//lprintf( "Failed to parse data..." );
		//printf( "THROWING AN ERROR\n" );
		PTEXT error = jsox_parse_get_error( NULL );
		if( error )      {
			//printf( "ERROR:%s\n", GetText( error ) );
			throwError( GetText( error ) );
		}
		else {
			//printf( "Not actually an error?\n" );
			throwError( "No Error Text" );
		}
		LineRelease( error );
		return JS_VALUE_UNDEFINED;
	}
	if( parsed && parsed->Cnt > 1 ) {
		lprintf( "Multiple values would result, invalid parse." );
		return JS_VALUE_UNDEFINED;
		// outside should always be a single value
	}
        //logTick(3);
	int value = convertMessageToJS2( parsed, revive );
        //logTick(4);

	jsox_dispose_message( &parsed );
        //logTick(5);

	return value;
	//return val::undefined();
}

int jsox_parse( char * string, size_t stringLen, int reviver ) EMSCRIPTEN_KEEPALIVE;

int jsox_parse( char * string, size_t stringLen, int reviver )
{
	//logTick(0);
	struct reviver_data *r = New( struct reviver_data );
	r->reviver_func = reviver;

	//.._malloc and stringToUTF8()
	//If you need a string to live forever, you can create it, for example, using _malloc and stringToUTF8(). However, you must later delete it manually!
	//printf( "convertin to string...%p %s\n", string, string );
	//printf( "confted string:%s" );

	if( reviver == JS_VALUE_NULL ) {
		//r._this = args.Holder();
		r->value = makeString( "", 0 );
		r->revive = TRUE;
		r->reviver_func = reviver;
	}
	else {
		r->revive = FALSE;
	}
	return ParseJSOX( string, stringLen, r );

} 

int jsox_write( struct jsox_parser *parser, char *string, size_t stringLen ) {
	lprintf( "write string, invoke callback on results..." );
}


//allocateUTF8