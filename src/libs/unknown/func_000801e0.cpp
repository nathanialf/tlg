/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkpAngMotorConstraintAtom's type
 * info (0x57c4920): construct the atom in place from a loaded image through
 * its inline finish constructor (the two adjacent offsets merge into one
 * 32-bit store, cookbook 13). */
void FUN_000801e0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpAngMotorConstraintAtom(flag);
}
