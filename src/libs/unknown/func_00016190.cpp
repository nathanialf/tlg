/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The ready queue's entry at an index removed, the heap restored: the last
 * entry moved into the hole and sifted up or down by its key (0x16190).
 * derived name. */
void FUN_00016190(hkArray<ReadyEntry00017540> *readyQueue, int index)
{
    hkArray<ReadyEntry00017540> &heap = *readyQueue;
    const int last = heap.getSize() - 1;
    if (index == last) {
        heap.setSizeUnchecked(index);
        return;
    }
    const int removedKey = heap[index].key;
    const int movedKey = heap[last].key;
    heap[index] = heap[last];
    heap.setSizeUnchecked(heap.getSize() - 1);
    if (movedKey > removedKey) {
        int child = index;
        for (int parent = (child - 1) >> 1; parent >= 0; parent = (child - 1) >> 1) {
            if (heap[parent].key > heap[child].key) {
                break;
            }
            hkAlgorithm::swap(heap[child], heap[parent]);
            child = parent;
        }
    } else {
        const int size = heap.getSize();
        int parent = index;
        int child = 2 * parent + 1;
        if (2 * parent + 2 < size && heap[child].key <= heap[2 * parent + 2].key) {
            child = 2 * parent + 2;
        }
        while (child < size) {
            if (heap[child].key <= heap[parent].key) {
                break;
            }
            hkAlgorithm::swap(heap[parent], heap[child]);
            parent = child;
            child = 2 * parent + 1;
            if (2 * parent + 2 < heap.getSize() && heap[child].key <= heap[2 * parent + 2].key) {
                child = 2 * parent + 2;
            }
        }
    }
}
