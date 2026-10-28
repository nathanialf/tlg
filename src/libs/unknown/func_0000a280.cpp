/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

Object0000a280::Object0000a280(hkReferencedObject *object, bool flag)
{
    if (object) {
        object->addReference();
    }
    this->object = object;
    this->flag = flag;
}
