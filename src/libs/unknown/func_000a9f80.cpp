/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_simd.h"

/* derived names: a vector of the file, copied by its static initializer
 * FUN_000a9f80 (`_GLOBAL__I_a`) from a constant of another file, the
 * {15, 15, 15, 0} at 0x14c6be0. Both are reached by GOT loads the linker
 * relaxed to `lea` (D10): globals, and the functions at 0x33ded, 0xa8ffd,
 * 0xa9dda and 0xd0623 read this one by address. */
extern const Vec4 D_14c6be0;

Vec4 D_57c87c0 = D_14c6be0;
