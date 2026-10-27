/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpScaledConvexShapeBase's vtable (0x16a5390), its deleting destructor:
 * hknpShape's destructor (0x6fb50; the classes between add nothing to destroy), then the object back to the thread's heap at its recorded size. */
void FUN_0016a640(hknpScaledConvexShapeBase *self)
{
    self->hknpShape::~hknpShape();
    freeReferencedObject(self, sizeof(hknpScaledConvexShapeBase));
}
