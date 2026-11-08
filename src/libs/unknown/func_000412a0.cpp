/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The bits a key needs to tell n values apart, at least one (inlined: its
 * own counter, so the loop's exit value is compared and stored through one
 * register counting down, 0x41330 to 0x41342; the same loop written in the
 * constructor counts up). derived name. */
static inline u8 numBitsFor(int n) /* derived name */
{
    u8 numBits = 0;
    for (; n != 0; n >>= 1) {
        numBits++;
    }
    return numBits ? numBits : 1;
}

/* A compound shape over a description: room for the larger of its two
 * counts, the shape keys wide enough to index it, every instance copied in
 * with its id written out (to the description's array, or to a block of
 * the thread's stack given back after), mutable as described, its AABB
 * empty. */
hknpCompoundShape::hknpCompoundShape(const hknpCompoundShapeCinfo &cinfo) : hknpCompositeShape()
{
    const int capacity = hkMath::max2(cinfo.numInstances, cinfo.instanceCapacity);
    numShapeKeyBits = numBitsFor(capacity);
    if (capacity > 0) {
        instances.grow(capacity);
    }

    if (cinfo.numInstances > 0) {
        hknpShapeInstanceId *ids = cinfo.instanceIdsOut;
        if (!ids) {
            ids = stackAllocate<hknpShapeInstanceId>(cinfo.numInstances);
        }
        for (int i = 0; i < cinfo.numInstances; i++) {
            ids[i] = instances.allocate(cinfo.instances[i]);
        }
        if (!cinfo.instanceIdsOut) {
            stackBlockFree(ids, LocalBuffer<hknpShapeInstanceId>::roundedSize(cinfo.numInstances));
        }
    }

    isMutable = cinfo.isMutable;
    aabb.setEmpty();
}
