/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_simd.h"

/* derived names: a tolerance of 2e-4 in all four lanes and a second vector
 * copied from it (FUN_00048b20 later stores into the second the first scaled
 * by the float at +0xe0 of its object, 0x48daf), both by this file's static initializer FUN_000aa340
 * (`_GLOBAL__I_a`). The initializer reaches them by GOT loads the linker
 * relaxed to `lea` (D10), and other files read them by address
 * (0x48db8, 0x48dc3, 0xaa0f9, 0xfd729): globals of the file. */
hkVector4 D_57c87d0 = {_mm_set1_ps(2e-4f)};
hkVector4 D_57c87e0 = D_57c87d0;
