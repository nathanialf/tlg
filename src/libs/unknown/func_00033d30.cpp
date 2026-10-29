/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

inline bool
hknpCompoundShapeInternalsKeyMask::isInstanceEnabled(hknpShapeInstanceId instanceId) const
{
    const int index = shape->instances.elements[instanceId.value].getIndex();
    return (filter[index / 32] & (1 << (index & 31))) != 0;
}

inline void hknpCompoundShapeInternalsKeyMask::setInstanceEnabled(hknpShapeInstanceId instanceId,
                                                                  bool enabled)
{
    const int index = shape->instances.elements[instanceId.value].getIndex();
    filter[index / 32] =
        (filter[index / 32] & ~(1 << (index % 32))) | (u32(enabled) << (index % 32));
}

int hknpCompoundShapeInternalsKeyMask::FUN_00033d30(hknpShapeInstanceId instanceId) const
{
    return isInstanceEnabled(instanceId);
}

/* Slot 5 (0x33ca0): the key's top bits pick the instance; an instance with
 * a mask of its own asks it with the rest of the key, any other answers as
 * slot 7 does. */
bool hknpCompoundShapeInternalsKeyMask::FUN_000381f0(u32 key) const /* derived name */
{
    const int numBits = shape->numShapeKeyBits;
    hknpShapeInstanceId instanceId;
    instanceId.value = short(key >> (32 - numBits));
    const hknpShapeKeyMask *instanceMask = instanceMasks[instanceId.value];
    if (instanceMask) {
        return instanceMask->FUN_000381f0(key << numBits);
    }
    return isInstanceEnabled(instanceId);
}

/* Slot 3 (0x33a90): the key's top bits pick the instance; an instance with
 * a mask of its own sets the rest of the key in it, any other has its bit
 * in the filter set or cleared. */
void hknpCompoundShapeInternalsKeyMask::FUN_000381b0(u32 key, bool enabled) /* derived name */
{
    const int numBits = shape->numShapeKeyBits;
    hknpShapeInstanceId instanceId;
    instanceId.value = short(key >> (32 - numBits));
    hknpShapeKeyMask *instanceMask = instanceMasks[instanceId.value];
    if (instanceMask) {
        instanceMask->FUN_000381b0(key << numBits, enabled);
        return;
    }
    setInstanceEnabled(instanceId, enabled);
}

/* Slot 0 (0x338d0): every instance's own mask deleted, then the filter and
 * the masks' array given back. The deleting destructor (0x33990, slot 1)
 * holds this body and the class delete's null test. */
hknpCompoundShapeInternalsKeyMask::~hknpCompoundShapeInternalsKeyMask()
{
    for (int i = 0; i < instanceMasks.size; i++) {
        delete instanceMasks[i];
    }
}
