# JSOX C/C++ Amalgam

[JSOX](github.com/d3x0r/JSOX) implementation in C.

This project is an attempt to build a Web Assembly version.

The C Code - jsox.cc and jsox.h can be used as standalone parser.  jsox.cc can be renamed as .c to compile as a C external file.  

jsox_parser.c is a simple user of jsox.cc



This example code will parse a single message.

```
	// data is a pointer to utf8 data, and size is the number of bytes to process.
	r = jsox_parse_message( data, size, &pdl );
	if( r > 0 )
		DumpMessage( pdl );

```


This will handle multiple values returned from a stream.
```
	// data is a pointer to utf8 data, and size is the number of bytes to process.
	int r;
	struct jsox_parse_state *parser;
	parser = jsox_begin_parse();

	for( r = jsox_parse_add_data( parser, data, size );
	     r > 0;
	     r = jsox_parse_add_data( parser, NULL, 0 ) ) {
		pdl = jsox_parse_get_data( parser );
		DumpMessage( pdl );
		jsox_dispose_message( &pdl );
	}

	if( r < 0 )
		printf( "Error:%s", GetText( jsox_parse_get_error( NULL ) ) );

```

