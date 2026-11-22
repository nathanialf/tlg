/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* derived name: the vector every new element takes at +0x10, +0x30 and
 * +0x50 (`vmovaps xmm1, [0x5ad0f80]`, read again for each) */
extern Vec4 D_5ad0f80;

/* derived names: two vectors, the first cleared and the second the vector
 * at 0x5ad0f80 by the constructor; not traced */
struct Pair013fb000 { /* derived name */

    Pair013fb000() : unknown0(_mm_setzero_ps()), unknown10(D_5ad0f80) {}

    Vec4 unknown0;  /* +0x0 */
    Vec4 unknown10; /* +0x10 */
};

/* derived names: the 0x70-byte element of the array FUN_01078df0 and
 * FUN_013fac20 size: three such pairs and a word its constructor clears;
 * the fields are not traced */
struct Record013fb000 { /* derived name */

    Record013fb000() : unknown60(0) {}

    Pair013fb000 unknown0;  /* +0x0 */
    Pair013fb000 unknown20; /* +0x20 */
    Pair013fb000 unknown40; /* +0x40 */
    void *unknown60;        /* +0x60 */
};

/* FUN_013fb000: the array sized (emptied, the capacity made the count, the
 * block reallocated where it differs, then each element built) */
template void Array05943280<Record013fb000>::resize(unsigned);
