:::
:   
:   ../../include/jsox_parser.h 
:   ../../src/netlib/html5.websocket/json/jsox_parser.c 
:   ../../src/netlib/html5.websocket/json/jsox.h 
:   ../../src/deadstart/deadstart_core.c 
:   ../../src/memlib/sharemem.c 
:   ../../src/memlib/memory_operations.c 
:   ../../src/typelib/typecode.c 
:   ../../src/typelib/text.c 
:   ../../src/typelib/sets.c
:   ../../src/typelib/binarylist.c 
:   
:   

mkdir c
del jsox.h
:c:\tools\ppc.exe -c -K -once -ssio -sd -I../../include -p -oc/jsox.cc -DINCLUDE_LOGGING ../../include/jsox_parser.h ../../src/netlib/html5.websocket/json/jsox_parser.c ../../src/netlib/html5.websocket/json/jsox.h ../../src/deadstart/deadstart_core.c ../../src/memlib/sharemem.c ../../src/memlib/memory_operations.c ../../src/typelib/typecode.c ../../src/typelib/text.c ../../src/typelib/sets.c ../../src/typelib/binarylist.c 
c:\tools\ppc.exe -c -K -once -ssio -sd -I../../include -p -oc/jsox.cc -DINCLUDE_LOGGING ../../include/jsox_parser.h ../../src/netlib/html5.websocket/json/jsox_parser.c ../../src/netlib/html5.websocket/json/jsox.h ../../src/deadstart/deadstart_core.c ../../src/memlib/sharemem.c ../../src/memlib/memory_operations.c ../../src/typelib/typecode.c ../../src/typelib/text.c ../../src/typelib/sets.c ../../src/typelib/binarylist.c 
copy c\jsox.cc c\jsox.c
mkdir h
cd h
c:\tools\ppc.exe -c -K -once -ssio -sd -I../../../include -p -ojsox.h ../../../include/jsox_parser.h 

cd ..
copy c\*
copy h\jsox.h

gcc -g -o a jsox_parser.c jsox.c
gcc -O3 -o a-opt jsox_parser.c jsox.c
copy jsox_parser.c jsox_parser.cc
gcc -g -o c jsox_parser.cc jsox.cc

:_CRT_NONSTDC_NO_DEPRECATE;NO_OPEN_MACRO;_DEBUG;NO_OPEN_MACRO;__STATIC__;USE_SQLITE;USE_SQLITE_INTERFACE;FORCE_COLOR_MACROS;NO_OPEN_MACRO;__STATIC__;NO_FILEOP_ALIAS;_CRT_SECURE_NO_WARNINGS;NEED_SHLAPI;NEED_SHLOBJ;JSON_PARSER_MAIN_SOURCE;SQLITE_ENABLE_LOCKING_STYLE=0;MINIMAL_JSON_PARSE_ALLOCATE