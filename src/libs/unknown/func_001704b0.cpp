/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldContextPool::FUN_001704b0(Context *context, hknpEventDispatcher *dispatcher)
{
    hkPrimaryCommandDispatcher *commandDispatcher = context->world->commandDispatcher;
    for (int i = 0; i < numUsed0; i++) {
        contexts[i].commandWriter->writer.FUN_00093a10();
    }

    if (!cache) {
        BlockStreamAllocator *allocator = context->cache250->allocator;
        cache = new BlockCache(allocator);
        stream.FUN_00094750(cache, false);
    }
    hkBlockStreamWriter writer;
    writer.FUN_000938c0(cache, &stream);
    if (dispatcher) {
        dispatcher->commandWriter = &writer;
    }

    for (int i = 0; i < cellPairEntries.getSize(); i++) {
        const LinkedRange0015ea30 *range = &cellPairEntries[i];
        if (range->range.numElements == 0) {
            continue;
        }
        do {
            hkBlockStreamReader reader;
            reader.FUN_000937f0(&range->range);
            for (const hkCommand *command = static_cast<const hkCommand *>(reader.access());
                 command; command = static_cast<const hkCommand *>(
                              reader.advance(command->sizePaddedTo16))) {
                if (command->unknown2 & 1) {
                    commandDispatcher->FUN_00090830(*command);
                } else {
                    const int size = command->sizePaddedTo16;
                    void *destination = writer.reserve(size);
                    hkString::memCpy16NonEmpty(destination, command, size >> 4);
                    writer.advance(size);
                }
            }
            range = range->next;
        } while (range);
        /* The pair's commands are consumed: its range emptied. */
        LinkedRange0015ea30 &entry = cellPairEntries[i];
        entry.range.startBlock = HK_NULL;
        entry.range.numElements = 0;
        entry.next = HK_NULL;
    }

    writer.FUN_00093a10();
    if (dispatcher) {
        dispatcher->commandWriter = HK_NULL;
    }
    for (int i = 0; i < numUsed0 + numUsed4; i++) {
        contexts[i].FUN_00167f70(context->cache250, context->cache258);
    }
}
