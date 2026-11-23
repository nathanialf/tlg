/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: a record of three points, a copy of an array of vectors and
 * an int, built by FUN_0051b980 (not written). The
 * points are copied lane by lane (Float4's copy, `mov eax, [rsi]; mov [rbx],
 * eax` four times each), the array through its copy constructor (one memcpy
 * of the count read again, `shl edx, 4`), the int last. What they mean is not
 * traced. */
struct Record01354830 { /* derived name */
    Record01354830(const Float4 &first, const Float4 &second, const Float4 &third,
                   const Array01343a80<Vec4> &vectors, int value);

    Float4 unknown0;             /* +0x0 */
    Float4 unknown10;            /* +0x10 */
    Float4 unknown20;            /* +0x20 */
    Array01343a80<Vec4> vectors; /* +0x30 */
    int unknown48;               /* +0x48 */
};

/* FUN_01354830 */
Record01354830::Record01354830(const Float4 &first, const Float4 &second, const Float4 &third,
                               const Array01343a80<Vec4> &vectors, int value)
    : unknown0(first), unknown10(second), unknown20(third), vectors(vectors), unknown48(value)
{
}
