/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpBallGun's vtable (0x16a48d0), its deleting destructor:
 * hknpBallGun's destructor, then the object back to the thread's heap at its recorded size. */
void FUN_00157ea0(hknpBallGun *self)
{
    self->hknpBallGun::~hknpBallGun();
    freeReferencedObject(self, sizeof(hknpBallGun));
}
