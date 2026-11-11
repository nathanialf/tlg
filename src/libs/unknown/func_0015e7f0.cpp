/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The pairs task's file: slot 5, the work (0x15ea30), is the class's key
 * function, so its vtable and its implicit destructor are emitted here: the
 * base destructor 0x15dee0, the complete 0x15dc50 and deleting 0x15dc60, the
 * interface's thunks 0x15dcb0 and 0x15dcc0, and the stream set's destructor
 * 0x15dd10 they call for each set; the work's thunk 0x15fa40 with it. */

/* derived name: the task's name for the dumps, its timer's (by the kind at
 * +0xd0), in the first state's fill colour. The interface's thunk of it
 * (0x15e850, slot 3 of the second vtable) is emitted beside it with the body
 * inlined. */
void hknpCollidePairsTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    FUN_000116c0(name, pairsKind == 1 ? "Collide/Existing Pairs" : "Collide/New Pairs");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(0));
    }
}

// NONMATCHING: a draft written to give the class its key function; the
// structure follows the base (the batches taken atomically, the existing
// pairs by grid cell, the new pairs by batch, each output range linked into
// its list) but the frame, the consumers' places and the per-batch output
// object at -0x550 are not worked yet.
void hknpCollidePairsTask::process()
{
    if (streamSets.getSize() == 0 || bool(flag133) != bool(flag132)) {
        return;
    }
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBeginList("LtNarrowPhase", "StInit");
    hknpWorldContextPool *pool = contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    hkBlockStream *sharedStreams = shared->elements[context->index].slots;
    StepStreams0015e980 &set = streamSets[context->index - firstContextIndex];
    if (!set.inUse) {
        set.FUN_0015e8b0(context, pairsKind);
    }
    CollideWriters0015e030 writers;
    writers.FUN_014aff90(context, sharedStreams, &set, pairsKind);
    void *const countedWriters[3] = {&writers.writerA0, &writers.writerD0, &writers.writer178};
    hknpWorldObject380 *object380 =
        static_cast<hknpWorldObject380 *>(context->modifierManager->objects4e0[0]);
    object380->FUN_000311b0(context->records268, countedWriters, pairsKind == 1 ? 3 : 2);
    const int numBatches = pairsKind == 1 ? cells.getSize() : batches.getSize();
    u8 output[0x420];
    for (int i = __sync_fetch_and_add(nextBatch, 1); i < numBatches;
         i = __sync_fetch_and_add(nextBatch, 1)) {
        stream.timerSplitList("StSubTask");
        hkBlockStreamWriter &commandWriter = context->commandWriter->writer;
        if (pairsKind == 1) {
            Entry20 &cell = cells[i];
            const int cellA = cell.cellA;
            const int cellB = cell.cellB;
            CacheRange000331a0 rangeA;
            rangeA.setStartPoint(&writers.writerA0);
            writers.writerA0.stats.totalSize = 0;
            writers.writerA0.stats.maxCount = 0;
            CacheRange000331a0 rangeB;
            rangeB.setStartPoint(&writers.writerD0);
            writers.writerD0.stats.totalSize = 0;
            writers.writerD0.stats.maxCount = 0;
            cell.range.setStartPoint(&writers.writer178);
            hkBlockStreamConsumer consumer;
            consumer.FUN_00093ab0(context->cache258, stream120,
                                  static_cast<hkBlockStream *>(unknown68), &ranges138[cellB]);
            hkBlockStreamConsumer newPairs;
            if (ranges140) {
                newPairs.FUN_00093ab0(context->cache258, stream148,
                                      static_cast<hkBlockStream *>(unknown70), &ranges140[cellB]);
            } else {
                newPairs.currentByteLocation = HK_NULL;
            }
            hkBlockStreamRange range0;
            range0.setStartPoint(&writers.writer0);
            hkBlockStreamRange range50;
            range50.setStartPoint(&writers.writer50);
            context->commandRange.range.setStartPoint(&commandWriter);
            FUN_0015c5f0(context, shared20, cellB, &consumer, unknown128, unknown78, &newPairs,
                         unknown150, unknown80, &writers.writer0, &writers.writer28,
                         &writers.writer50, &writers.writer78, &writers.writer128,
                         &writers.writer150, &writers.writer100, context->records268[0],
                         context->records268[1], context->records268[2], output);
            context->commandRange.range.FUN_00092220(&commandWriter);
            if (context->commandRange.range.numElements != 0) {
                appendLinkedRange((*context->commandRanges)[cellB], context->commandRange,
                                  commandWriter);
            }
            context->commandRange.range.setStartPoint(&commandWriter);
            range0.FUN_00092220(&writers.writer0);
            range50.FUN_00092220(&writers.writer50);
            rangesOut158[cellB] = range0;
            rangesOut160[cellB] = range50;
            object380->unknownVirtual11(context->records268, 3);
            rangeA.FUN_00092220(&writers.writerA0);
            rangeA.stats.totalSize = writers.writerA0.stats.totalSize;
            rangeA.stats.maxCount = writers.writerA0.stats.maxCount;
            rangeB.FUN_00092220(&writers.writerD0);
            rangeB.stats.totalSize = writers.writerD0.stats.totalSize;
            rangeB.stats.maxCount = writers.writerD0.stats.maxCount;
            cell.range.FUN_00092220(&writers.writer178);
            if (rangeA.numElements != 0) {
                appendLinkedRange(shared->cacheGrid[cellB], rangeA, writers.writerA0);
            }
            if (cellA != 0xff && rangeB.numElements != 0) {
                appendLinkedRange(shared->array20[cellA], rangeB, writers.writerD0);
            }
        } else {
            Entry70 &batch = batches[i];
            hkBlockStreamRange range50;
            range50.setStartPoint(&writers.writer50);
            CacheRange000331a0 rangeA;
            rangeA.setStartPoint(&writers.writerA0);
            writers.writerA0.stats.totalSize = 0;
            writers.writerA0.stats.maxCount = 0;
            CacheRange000331a0 rangeB;
            rangeB.setStartPoint(&writers.writerD0);
            writers.writerD0.stats.totalSize = 0;
            writers.writerD0.stats.maxCount = 0;
            hkBlockStreamConsumer consumer;
            consumer.FUN_00093ab0(context->cache258, stream120,
                                  static_cast<hkBlockStream *>(unknown68), &batch.range);
            hkBlockStreamConsumer noPairs;
            noPairs.currentByteLocation = HK_NULL;
            context->commandRange.range.setStartPoint(&commandWriter);
            FUN_0015c5f0(context, shared20, 0, &consumer, unknown128, unknown78, &noPairs, HK_NULL,
                         HK_NULL, &writers.writer0, &writers.writer28, &writers.writer50,
                         &writers.writer78, HK_NULL, HK_NULL, &writers.writer100,
                         context->records268[0], context->records268[1], HK_NULL, output);
            context->commandRange.range.FUN_00092220(&commandWriter);
            batch.commands = context->commandRange;
            context->commandRange.range.setStartPoint(&commandWriter);
            object380->unknownVirtual11(context->records268, 2);
            rangeA.FUN_00092220(&writers.writerA0);
            rangeA.stats.totalSize = writers.writerA0.stats.totalSize;
            rangeA.stats.maxCount = writers.writerA0.stats.maxCount;
            rangeB.FUN_00092220(&writers.writerD0);
            rangeB.stats.totalSize = writers.writerD0.stats.totalSize;
            rangeB.stats.maxCount = writers.writerD0.stats.maxCount;
            if (rangeA.numElements != 0) {
                batch.output = rangeA;
            } else if (rangeB.numElements != 0) {
                batch.output = rangeB;
            } else {
                batch.output.startBlock = HK_NULL;
                batch.output.numElements = 0;
                batch.output.next = HK_NULL;
            }
            range50.FUN_00092220(&writers.writer50);
        }
    }
    stream.timerSplitList("StFinalizeWriters");
    writers.FUN_0015e030();
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
    stream.timerEndList("lt");
}
