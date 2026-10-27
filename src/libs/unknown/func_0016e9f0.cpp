/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpSolveDataTask's vtable (0x16a5680), its deleting destructor:
 * the destructor 0x16eaa0, then the object back to the thread's heap at its recorded size. */
void FUN_0016e9f0(hknpSolveDataTask *self)
{
    FUN_0016eaa0(self);
    freeReferencedObject(self, sizeof(hknpSolveDataTask));
}
