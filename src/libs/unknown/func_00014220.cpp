/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ThreadMemory::blockFree(void *pointer, int numBytes)
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
