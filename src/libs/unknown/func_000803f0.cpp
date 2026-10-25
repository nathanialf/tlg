/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkpLinMotorConstraintAtom's type
 * info (0x57c4f40): construct the atom in place from a loaded image through
 * its inline finish constructor. hkpRagdollMotorConstraintAtom's type info
 * (0x57c51c0) holds the same body, its offsets at the same places. */
void FUN_000803f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLinMotorConstraintAtom(flag);
}
