/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Object00176420::FUN_00177130(hkReferencedObject *object)
{
    if (object) {
        object->addReference();
    }
    if (object20) {
        object20->removeReference();
    }
    object20 = object;
}
