/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 13: every block the free lists keep given back to the allocator the
 * thread draws from, the last row first, four at a time. */
void ThreadMemory::FUN_00014690()
{
    for (int row = 16 - 1; row >= 0; row--) {
        FreeList &list = freeLists[row];
        int numElem = list.numElem;
        if (numElem) {
            const int blockSize = rowToSize[row];
            while (numElem > 0) {
                const int numBlocks = numElem > 4 ? 4 : numElem;
                void *blocks[4];
                for (int i = 0; i < numBlocks; i++) {
                    blocks[i] = list.pop();
                }
                memory->blockFreeBatch(blocks, numBlocks, blockSize);
                numElem -= numBlocks;
            }
        }
    }
}

/* Slot 2 (0x140e0), the class's first out-of-line virtual: a request of a
 * row's size from its row's free list, refilled with up to four blocks from
 * the allocator the thread draws from when it is empty (the first handed
 * out, the others kept); a larger request, or any when the lists keep
 * nothing, from that allocator directly. */
void *ThreadMemory::blockAlloc(int numBytes)
{
    if (numBytes <= MAX_ROW_SIZE) {
        const int row = getRow(numBytes);
        FreeList &list = freeLists[row];
        if (void *block = list.pop()) {
            return block;
        }
        const int maxNumElems = maxNumElemsOnFreeList;
        if (!maxNumElems) {
            return memory->blockAlloc(rowToSize[row]);
        }
        const int numBlocks = maxNumElems < 4 ? maxNumElems : 4;
        void *blocks[4];
        memory->blockAllocBatch(blocks, numBlocks, rowToSize[row]);
        for (int i = 1; i < numBlocks; i++) {
            list.push(blocks[i]);
        }
        return blocks[0];
    }
    return memory->blockAlloc(numBytes);
}

/* A block onto a full row's list (0x147c0, called by slot 3's free): when
 * the lists keep blocks, the list first emptied down to half its limit, up
 * to four blocks a batch back to the allocator the thread draws from, then
 * the block pushed; when they keep none, the block straight back to that
 * allocator at the row's size. */
void ThreadMemory::FUN_000147c0(int row, void *pointer)
{
    const int blockSize = rowToSize[row];
    if (maxNumElemsOnFreeList) {
        FreeList &list = freeLists[row];
        const int maxNumElems = maxNumElemsOnFreeList / 2;
        int numElem = list.numElem;
        while (numElem > maxNumElems) {
            const int numExcess = numElem - maxNumElems;
            const int numBlocks = numExcess > 4 ? 4 : numExcess;
            void *blocks[4];
            for (int i = 0; i < numBlocks; i++) {
                blocks[i] = list.pop();
            }
            memory->blockFreeBatch(blocks, numBlocks, blockSize);
            numElem -= numBlocks;
        }
        list.push(pointer);
    } else {
        memory->blockFree(pointer, blockSize);
    }
}
