/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hknpShapeSignals's type info
 * (0x57c24c8): destroys the struct in place, its signals in the reverse of
 * their order through their out-of-line destructor. */
void FUN_00069960(void *object) /* derived name */
{
    hknpShapeSignals *signals = static_cast<hknpShapeSignals *>(object);
    FUN_00093530(&signals->shapeDestroyed);
    FUN_00093530(&signals->shapeMutated);
}
