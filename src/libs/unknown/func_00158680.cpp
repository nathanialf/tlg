/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpCompressedMeshShape's vtable (0x16a4990), its deleting destructor:
 * the destructor 0x1586d0, then the object back to the thread's heap at its recorded size. */
void FUN_00158680(hknpCompressedMeshShape *self)
{
    FUN_001586d0(self);
    freeReferencedObject(self, sizeof(hknpCompressedMeshShape));
}
