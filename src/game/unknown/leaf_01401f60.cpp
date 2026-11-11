/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: copies into out the vector FUN_013d0100 computes into an
 * aligned local, read back through the reference FUN_013d0100 returns (one
 * unaligned vector move); the second and third arguments are passed through
 * unchanged. FUN_013d0100 writes its result with an aligned move and returns
 * its first argument; most of its 43 callers read their own temporary, these
 * three (0x1401f60, 0x140b340, 0x1435fd0) read through the returned address.
 * The vector's meaning is not traced. */
const Float4 &FUN_013d0100(Float4A &result, const void *object,
                           const Float4 &value); /* derived name */

void FUN_01401f60(Float4 &out, const void *object, const Float4 &value) /* derived name */
{
    Float4A result;
    out = FUN_013d0100(result, object, value);
}
