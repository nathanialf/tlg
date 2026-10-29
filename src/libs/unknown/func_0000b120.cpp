/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The three router allocators, built by this file's static initializer
 * (0xb120) and destroyed at exit. derived names. */
/* The destructor each registration names is the class's own; the linker
 * folded the three empty bodies with hkMallocAllocator's at 0x4ac0, which
 * each class's vtable still cites (D15). */
RouterAllocator50 D_57b8470;
RouterAllocator60 D_57b8478;
RouterAllocator58 D_57b8480;
