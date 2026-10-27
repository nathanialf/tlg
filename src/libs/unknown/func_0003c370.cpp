/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpSphereShape's vtable (0x1695c10) and of
 * hknpConvexShape's (0x1697d90), the deleting destructor of both:
 * hknpShape's destructor (0x6fb50), then the object back to the thread's
 * heap at its recorded size. */
void FUN_0003c370(hknpSphereShape *self)
{
    self->hknpShape::~hknpShape();
    freeReferencedObject(self, sizeof(hknpSphereShape));
}
