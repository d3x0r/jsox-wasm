:call emcc --bind --memory-init-file 0 -std=c++11 -O2 -o ./jsox-wasm.js -Wno-address-of-packed-member -Wno-parentheses -Wno-comment -Wno-null-dereference -D__LINUX__  -s EXPORTED_FUNCTIONS="['_jsox_begin_parse','_jsox_parse_clear_state','_jsox_parse_add_data']" jsox.c

:--pre-js or --post-js
call emcc -O2 -o ./jsox-w.js -std=c++11 --bind -Wno-address-of-packed-member -Wno-parentheses -Wno-comment -Wno-null-dereference -D__LINUX__ -s RESERVED_FUNCTION_POINTERS=20  jsox.cc emscripten_bindings.cc --post-js jsoxParse.js

