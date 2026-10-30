/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The finish constructor: the name finished, the listeners (not
 * serialized) an empty array, and a finished gun's type reset (each
 * derived gun's finish constructor then sets its own). */
hknpFirstPersonGun::hknpFirstPersonGun(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), name(flag)
{
    if (flag.finishing) {
        type = WEAPON_TYPE_INVALID;
    }
}

/* Every listener released, then the members. */
inline hknpFirstPersonGun::~hknpFirstPersonGun()
{
    for (int i = 0; i < listeners.getSize(); i++) {
        listeners[i]->removeReference();
    }
}

/* Slot 5, the class's key function: empty (the shared body 0xadd50 the
 * linker keeps for it and for slots 6, 7 and 10). */
void hknpFirstPersonGun::unknownVirtual5() {}
