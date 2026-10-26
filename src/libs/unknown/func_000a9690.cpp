/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_simd.h"

/* derived name: a tolerance of 1e-4 in all four lanes, set by this file's
 * static initializer FUN_000a9690 (`_GLOBAL__I_a`). The initializer reaches
 * it by a GOT load the linker relaxed to `lea` (D10), and no code of the
 * executable reads it by address: a global of the file, not file-local. */
Vec4 D_57c87b0 = _mm_set1_ps(1e-4f);
