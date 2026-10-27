/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpStaticCompoundShapeInternals's vtable (0x1692830),
 * its deleting destructor: hknpStaticCompoundShape's destructor (0x386c0),
 * then the object back to the thread's heap at its recorded size. */
void FUN_00033f40(hknpStaticCompoundShapeInternals *self)
{
    self->hknpStaticCompoundShape::~hknpStaticCompoundShape();
    freeReferencedObject(self, sizeof(hknpStaticCompoundShapeInternals));
}
