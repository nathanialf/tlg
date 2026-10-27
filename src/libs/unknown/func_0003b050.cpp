/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpDecoratorShape's vtable (0x16958d0), its deleting
 * destructor: hknpShape's destructor (0x6fb50), then the object back to the
 * thread's heap at its recorded size, 64 bytes by default. */
void FUN_0003b050(hknpDecoratorShape *self)
{
    self->hknpShape::~hknpShape();
    freeReferencedObject(self, 64);
}
