/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived name: gives the calling thread its stream, a ThreadBuffer
 * value-initialised from the router's heap and kept in the thread's slot,
 * its fields then cleared from the flag down. Called by FUN_00009a60 and
 * FUN_000098d0 after the router is made the thread's. */
// NONMATCHING: the stores. The base clears the new stream as five qword
// stores (+0x20 down to +0) and its fields after the slot's store as a byte
// and four qwords; this compile lowers the value-initialisation's memset to a
// ymm and a qword store and merges the four cleared pointers into one ymm
// store. Both are what a function with no implicit vector use gives
// (getOptimalMemOpType and MergeConsecutiveStores refuse vectors under
// NoImplicitFloat): with FUN_014aff90 this is the last object of the text,
// whose flags are not traced (a region question, not this source's).
void FUN_014aff00()
{
    ThreadBuffer *stream = new ThreadBuffer();
    D_16dc078 = stream;
    stream->isBufferAllocatedOnTheHeap = false;
    stream->capacityMinus16 = 0;
    stream->capacity = 0;
    stream->end = 0;
    stream->start = 0;
}
