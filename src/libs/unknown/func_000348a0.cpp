/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: one vector per entry of the record, by FUN_00031740 from
 * another file with the record's count. */
void FUN_000348a0(const Pair08Owner *self, const hknpMotion *motionA, const hknpMotion *motionB,
                  const void *argument4, Vec4 *out)
{
    FUN_00031740(self, self->count, motionA, motionB, out);
}
