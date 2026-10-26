/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The stack tracer's constructor: nothing to set up but the vtable. Called
 * for the static instance at 0x57b7b80 (0x6bf0, destroyed at exit through
 * 0xd940) and for the one the error report at 0xb680 builds on its stack. */
// NONMATCHING: the vtable 0x168d840 is not in config/vtables.base.txt (no type-info registration names the class)
StackTracer::StackTracer() {}
