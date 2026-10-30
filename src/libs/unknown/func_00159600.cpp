/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpProjectileGun's vtable (0x16a4b30), its deleting destructor:
 * the destructor 0x159650, then the object back to the thread's heap at its recorded size. */
void FUN_00159600(hknpProjectileGun *self)
{
    self->hknpProjectileGun::~hknpProjectileGun();
    freeReferencedObject(self, sizeof(hknpProjectileGun));
}
