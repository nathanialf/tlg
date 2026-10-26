/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkpWheelFrictionConstraintAtom's
 * type info (registered at 0x81f73): construct the atom in place from a
 * loaded image through its inline finish constructor. */
void FUN_00080660(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpWheelFrictionConstraintAtom(flag);
}
