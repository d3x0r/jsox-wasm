# JSOX C/C++ Amalgam

[JSOX](github.com/d3x0r/JSOX) implementation in C.

This project is an attempt to build a Web Assembly version.

The C Code - jsox.cc and jsox.h can be used as standalone parser.  jsox.cc can be renamed as .c to compile as a C external file.  

jsox_parser.c is a simple user of jsox.cc



```

	r = jsox_parse_message( data, size, &pdl );
	if( r > 0 )
		DumpMessage( pdl );

	

```

