/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: replaces an aligned vector in place with the value
 * FUN_013d99f0 computes from it (returned through the hidden pointer, a
 * 16-byte temporary copied back with one aligned vector move) and returns the
 * vector, as an in-place operator does; nine callers between 0xf86065 and
 * 0x12c8364 use it. FUN_013d99f0 (0x351 bytes, its only caller is this one)
 * is not traced. */
Float4A FUN_013d99f0(const Float4A &value); /* derived name */

Float4A &FUN_013d99a0(Float4A &value) /* derived name */
{
    value = FUN_013d99f0(value);
    return value;
}
