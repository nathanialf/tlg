/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the body is the base's (the vtable, then the null pointer),
// but _ZTV17Allocator0000ed40 (0x168da00) is in neither vtable table: the
// class has no type info, so its vtable waits for a ruling (D14).
Allocator0000ed40::Allocator0000ed40() : pointer8(0) {}
