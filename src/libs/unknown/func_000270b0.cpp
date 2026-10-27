/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the element count first, then that many elements, the
 * count read again from the source once its copy is stored. */
void FUN_000270b0(hkVertexFormat *self, const hkVertexFormat *other) /* derived name */
{
    self->numElements = other->numElements;
    const int numElements = other->numElements;
    const hkVertexFormat::Element *src = other->elements;
    hkVertexFormat::Element *dst = self->elements;
    for (int i = 0; i < numElements; i++, src++, dst++) {
        *dst = *src;
    }
}
