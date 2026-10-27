/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpSolveDataTask's second vtable: the deleting
 * destructor reached through the interface, on the whole object. */
void FUN_0016ea40(hknpTaskInterface *self)
{
    hknpSolveDataTask &object = static_cast<hknpSolveDataTask &>(*self);
    FUN_0016eaa0(&object);
    freeReferencedObject(&object, sizeof(hknpSolveDataTask));
}
