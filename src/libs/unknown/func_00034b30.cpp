/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpCompressedMeshShapeData's vtable (0x1692b00), its
 * deleting destructor: the destructor 0x34b80, then the object back to the
 * thread's heap at its recorded size, 256 bytes by default. */
void FUN_00034b30(hknpCompressedMeshShapeData *self)
{
    FUN_00034b80(self);
    freeReferencedObject(self, 256);
}
