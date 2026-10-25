/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: forwards to FUN_0002b3b0 from another file, the record
 * first here and second there (FUN_0003d7d0 and its neighbours at 0x3d8ee,
 * 0x3db43 and 0x3dcbc pass the two motions of a body pair). */
void FUN_00034920(Pair08Owner *self, const Info0002b180 *info, const hknpMotion *motionA,
                  const hknpMotion *motionB, Output0002b3b0 *out) /* derived name */
{
    FUN_0002b3b0(info, self, motionA, motionB, out);
}
