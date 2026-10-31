/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkSkinnedRefMeshShape's vtable (0x16a38b0), its deleting destructor:
 * the destructor 0xaa6d0 (func_000aa6d0.cpp), then the object back to the thread's heap at its
 * recorded size. */
void FUN_000aa680(hkSkinnedRefMeshShape *self)
{
    self->hkSkinnedRefMeshShape::~hkSkinnedRefMeshShape();
    freeReferencedObject(self, sizeof(hkSkinnedRefMeshShape));
}
