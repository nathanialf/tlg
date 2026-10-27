/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the second vtable (0x168e888): the deleting
 * destructor reached through the interface, on the whole object. */
void FUN_00016f30(Interface168e888 *self)
{
    Class168e810 &object = static_cast<Class168e810 &>(*self);
    FUN_00016f90(&object);
    freeReferencedObject(&object, sizeof(Class168e810));
}
