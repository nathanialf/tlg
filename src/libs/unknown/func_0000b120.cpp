/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The three router allocators, built by this file's static initializer
 * (0xb120) and destroyed at exit. derived names. */
// NONMATCHING: equal in quick_diff (29 instructions, 127 bytes) but for the
// three destructors registered with __cxa_atexit: the base registers 0x4ac0
// for each (the linker's one copy of the empty allocator destructors, the
// row _ZN17hkMallocAllocatorD1Ev), the compile each class's own complete
// destructor, which no row names (docs/NOTES.md, Round 49).
RouterAllocator50 D_57b8470;
RouterAllocator60 D_57b8478;
RouterAllocator58 D_57b8480;
