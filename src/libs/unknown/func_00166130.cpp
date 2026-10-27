/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpExternMeshShape's vtable (0x16a5170), its deleting destructor:
 * the destructor 0x166180, then the object back to the thread's heap at its recorded size. */
void FUN_00166130(hknpExternMeshShape *self)
{
    FUN_00166180(self);
    freeReferencedObject(self, sizeof(hknpExternMeshShape));
}
