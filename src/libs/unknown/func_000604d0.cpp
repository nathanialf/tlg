/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_lib_unknown.h"

/* The class allocator's delete: the splitter goes back to the calling
 * thread's heap at its size. */
inline void hknpSpaceSplitter::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

/* The space splitter's destructor (slot 0 of its vtable): the array's
 * storage given back. The flagged-points splitter's implicit destructors,
 * emitted here with its vtable (its slot 3 below is the class's first
 * out-of-line virtual), inline it: its deleting destructor (0x60450)
 * frees its 0x170 bytes, its complete one is the same body as this one
 * (0x604d0). */
hknpSpaceSplitter::~hknpSpaceSplitter() {}

/* derived name: every flagged point moved by the offset. */
void FlaggedPoints00060c70::FUN_00061280(const Vec4 &offset)
{
    for (int i = 0; i < numCells; i++) {
        if (flags[i]) {
            points[i] = _mm_add_ps(points[i], offset);
        }
    }
}
