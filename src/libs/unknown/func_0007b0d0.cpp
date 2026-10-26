/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkpWheelFrictionConstraintData::Atoms'
 * type info (registered at 0x7b2c7): construct the atoms in place from a
 * loaded image through their inline finish constructor. */
void FUN_0007b0d0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpWheelFrictionConstraintData::Atoms(flag);
}
