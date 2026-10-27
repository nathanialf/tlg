/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the vtable 0x168e800, the deleting destructor of the
 * object with the work interface at +0x10: the destructor 0x16f90, then
 * the object back to the thread's heap at its recorded size. */
void FUN_00016ee0(Class168e810 *self)
{
    FUN_00016f90(self);
    freeReferencedObject(self, sizeof(Class168e810));
}
