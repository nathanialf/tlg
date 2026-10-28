/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the stream emptied, then the warning value when the memory
 * system has a debug interface and the thread's stream has room. */
void ThreadBuffer::FUN_0000eca0()
{
    end = start;
    if (FUN_00006c50()->getDebugInterface()) {
        ThreadBuffer *stream = D_16dc078;
        if (stream->end < stream->capacityMinus16) {
            AddValueCommand *command = reinterpret_cast<AddValueCommand *>(stream->end);
            command->commandAndMonitor =
                "MfUsing a debug (slow?) memory system, possibly the hkCheckingMemorySystem.";
            command->value = 0.0f;
            stream->end = reinterpret_cast<char *>(command + 1);
        }
    }
}
