:call emcc --bind --memory-init-file 0 -std=c++11 -O2 -o ./jsox-wasm.js -Wno-address-of-packed-member -Wno-parentheses -Wno-comment -Wno-null-dereference -D__LINUX__  -s EXPORTED_FUNCTIONS="['_jsox_begin_parse','_jsox_parse_clear_state','_jsox_parse_add_data']" jsox.c

:--pre-js or --post-js

:-s EXPORTED_FUNCTIONS="[_" 

: -s EXPORT_ALL=1
:-s MAIN_MODULE=1

@set CFLAGS=
@set CFLAGS=%CFLAGS% -Wno-address-of-packed-member -Wno-parentheses -Wno-comment -Wno-null-dereference
@set CFLAGS=%CFLAGS% -D__LINUX__
:@set CFLAGS=%CFLAGS%  -s RESERVED_FUNCTION_POINTERS=20

call emcc -O2 -s WASM=1  -o ./jsox-w.js  jsox.c simple_js.c %CFLAGS% -s EXPORTED_FUNCTIONS="['_initJSOX']" 

:call emcc -o ./jsox-w0.js  --bind %CFLAGS% jsox.c simple_js.c

:call google-closure-compiler.cmd --language_out NO_TRANSPILE --formatting=pretty_print  --js=jsox-w.js --js_output_file=jsox-w-pretty.js
