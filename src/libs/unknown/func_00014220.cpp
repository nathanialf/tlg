/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

inline void ThreadMemory::freeBlock(void *pointer, int numBytes)
{
    if (pointer) {
        if (numBytes <= MAX_ROW_SIZE) {
            const int row = getRow(numBytes);
            FreeList &list = freeLists[row];
            if (list.numElem < maxNumElemsOnFreeList) {
                list.numElem++;
                *static_cast<void **>(pointer) = list.head;
                list.head = pointer;
            } else {
                FUN_000147c0(row, pointer);
            }
        } else {
            memory->blockFree(pointer, numBytes);
        }
    }
}

void ThreadMemory::blockFree(void *pointer, int numBytes)
{
    freeBlock(pointer, numBytes);
}

void *ThreadMemory::FUN_00008d90(void *pointer, int oldNumBytes, int &numBytesInOut)
{
    void *newPointer = ThreadMemory::blockAlloc(numBytesInOut);
    if (newPointer) {
        FUN_000910e0(newPointer, pointer, hkMath::min2(numBytesInOut, oldNumBytes));
    }
    freeBlock(pointer, oldNumBytes);
    return newPointer;
}
