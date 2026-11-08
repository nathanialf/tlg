/* hkFreeListArray's out-of-class members (derived name: Havok's .cxx for a
 * container's template members, included by the units that instantiate
 * them; the class is in tlg_hk_reflect.h). */
#ifndef TLG_HK_FREELIST_H
#define TLG_HK_FREELIST_H

#include "tlg_hk_reflect.h"

/* Room for at least growBy more elements, the storage at least doubled,
 * each new element built and put on the free list in order ahead of the old
 * free ones (0x410a0 for the compound shapes' instances; the material
 * library's constructor 0x77450): each made free by the operations'
 * setEmpty, which builds the element. */
template <typename T, typename Id, int N, typename Ops>
void hkFreeListArray<T, Id, N, Ops>::grow(int growBy)
{
    const int oldCapacity = elements.getSize();
    const int newCapacity = hkMath::max2(oldCapacity + growBy, oldCapacity ? 2 * oldCapacity : 1);
    const int numNew = newCapacity - oldCapacity;
    elements.reserveExactly(newCapacity);
    elements.expandByUnchecked(numNew);
    const int last = newCapacity - 1;
    for (int i = oldCapacity; i <= last; i++) {
        Id id;
        id.value = i;
        T &element = elements[id.value];
        const int next = i < last ? i + 1 : firstFree;
        Ops::setEmpty(element, next);
    }
    firstFree = oldCapacity;
}

#endif
