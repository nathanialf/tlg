/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The class allocator's delete: the object goes back to the calling
 * thread's heap at its size. */
inline void Runner00016350::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

/* Slot 3, the class's key function: its vtable 0x168e7d0 and the deleting
 * destructor (0x13e50, slot 1; the body the linker kept for ten other
 * 16-byte classes) are emitted here. */
void Runner00016350::FUN_00091af0(hkStringBuf &name, hkStringBuf *attributes) const
{
    FUN_000116c0(&name, "Unnamed");
    if (attributes) {
        FUN_000116c0(attributes, "");
    }
}
