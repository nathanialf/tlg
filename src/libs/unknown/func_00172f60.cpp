/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before
 * their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* What the key query times (derived names): two timers, each its name, the
 * ticks it has counted, whether it is off and how often it ran, then the
 * keys found in all. */
struct KeyQueryTimers00172f60 /* derived name */
{
    struct Timer {
        const char *name;
        u32 ticks;
        int disabled;
        int count;
    };

    Timer queryTimer;
    Timer sortTimer;
    int numKeys;
};

/* The ticks from a start to a later reading, the counter's wrap allowed
 * for (derived name). */
static inline u32 ticksBetween(u32 start, u32 now)
{
    return start > now ? ~start + now : now - start;
}

/* A timer and the caches it saw (derived names): the manifold caches'
 * walk counts each batch it is handed. */
struct CacheTimer00172c70 /* derived name */
{
    KeyQueryTimers00172f60::Timer timer;
    int numCaches;
};

/* What the walk hands its child's processing second (derived names). */
struct Shared00172c70 /* derived name */
{
    u8 unknown0[0x18];
    const void *pointer18; /* derived name */
};

/* derived name: a manifold cache's solver record processed for its two
 * bodies (0x31e70, 0x1325 bytes). */
void FUN_00031e70(hknpWorldContextPool::Context *context, const void *argument2,
                  const void *solverRecord, hknpManifoldCollisionCache *cache,
                  const hknpCdBody *cdBodyA, hknpCdBody *cdBodyB, const void *argument7,
                  hknpWorldObject380MotionPair *motionPair);

/* derived name: numCaches manifold caches consumed from the reader and
 * copied to the writer, timed when the timer is on; a copy that keeps a
 * solver record (three quads or more) has the second body take its shape
 * key and material, the motions' part filled through the world's object
 * at +0x380, its record processed and taken off the consumed block, and its
 * angular TIM lowered by the bodies' TIM angles; every copy's TIM distance
 * lowered by theirs, neither below zero. The timer is HK_RESTRICT: the
 * base tests the flag it read at the start again where no cache is copied
 * (0x172cf5 to 0x172f21) although the writer's reserve may have called
 * FUN_000939c0 in between, which could otherwise have written it (BasicAA
 * holds an uncaptured noalias argument out of every call's reach). */
void FUN_00172c70(hknpWorldContextPool::Context *context, const Shared00172c70 *shared,
                  const hknpCdBody *cdBodyA, hknpCdBody *cdBodyB, int numCaches,
                  hkBlockStreamConsumer *reader, hkBlockStreamWriter *writer,
                  hkBlockStreamConsumedBlock *solverRecords,
                  hknpWorldObject380MotionPair *motionPair, CacheTimer00172c70 *HK_RESTRICT timer)
{
    u32 start;
    if (!timer->timer.disabled) {
        start = ThreadBuffer::readTimeStampCounter();
    }
    timer->numCaches += numCaches;
    const hknpManifoldCollisionCache *cache =
        static_cast<const hknpManifoldCollisionCache *>(reader->access());
    hknpManifoldCollisionCache *copy =
        static_cast<hknpManifoldCollisionCache *>(writer->reserve(0x170));
    const int timDistance = cdBodyA->body->maxTimDistance + cdBodyB->body->maxTimDistance;
    const int timAngle = cdBodyA->body->timAngle + cdBodyB->body->timAngle;
    while (numCaches > 0) {
        hkString::memCpy16NonEmpty(copy, cache, cache->sizeInQuads);
        numCaches--;
        cache = static_cast<const hknpManifoldCollisionCache *>(
            reader->consumeAndAdvance(cache->sizeInQuads * 16));
        _mm_prefetch(reinterpret_cast<const char *>(cache) + 256, _MM_HINT_NTA);
        if (copy->sizeInQuads >= 3 && copy->solverBlock) {
            u8 *const solverBlock = copy->solverBlock;
            const int angularTim = copy->angularTim;
            const int solverOffset = copy->solverOffset;
            cdBodyB->shapeKey = copy->bodyIdA;
            cdBodyB->material = &context->materials[copy->materialIdB];
            hknpWorldObject380 *object =
                static_cast<hknpWorldObject380 *>(context->modifierManager->objects4e0[0]);
            object->FUN_000311f0(motionPair, *cdBodyA->motion, cdBodyA->body, *cdBodyB->motion,
                                 cdBodyB->body);
            FUN_00031e70(context, shared->pointer18, hkAddByteOffset(solverBlock, solverOffset),
                         copy, cdBodyA, cdBodyB, HK_NULL, motionPair);
            copy->angularTim = u8(hkMath::max2(0, angularTim - timAngle));
            /* The consumed block holds the record's block. */
            hkBlockStreamBlock *const recordBlock =
                reinterpret_cast<hkBlockStreamBlock *>(solverBlock);
            if (solverRecords->block == recordBlock) {
                solverRecords->numElementsConsumed++;
            } else {
                if (solverRecords->block) {
                    solverRecords->FUN_00093bc0();
                }
                solverRecords->block = recordBlock;
                solverRecords->numElementsConsumed = 1;
            }
            solverRecords->byteOffset = solverOffset;
        }
        copy->unknownE = u16(hkMath::max2(0, copy->unknownE - timDistance));
        writer->advance(copy->sizeInQuads * 16);
        copy = static_cast<hknpManifoldCollisionCache *>(writer->reserve(0x170));
    }
    if (!timer->timer.disabled) {
        timer->timer.ticks += ticksBetween(start, ThreadBuffer::readTimeStampCounter());
        timer->timer.count++;
    }
}

/* derived name: the keys of a shape within a box, the box first made the
 * whole space, gathered by the shape's slot 25 and sorted, each step timed
 * when its timer is on; the number of keys. */
// NONMATCHING: 60 of 160 (size 584 against 604); the sort (explicitStackQuickSort) and the
// timers' arithmetic are the base's (the ticks' helper takes the reading as a parameter, so
// InstCombine's complexity rule keeps `start > now` with its operands, cmp start, now; a
// helper reading the counter itself has an argument against an instruction and swaps them).
// Left: the timers pointer, reloaded from its stack argument into r12 after the shape's call
// in the base, held in rcx here; and the sort timer's flag, loaded into ecx and tested in the
// base (both reads, 0x173029 and 0x173169), folded into `cmp [rcx+0x24], 0` here. NOTES Round
// 79A and Round 80A.
int FUN_00172f60(const void *argument1, const void *argument2, const void *argument3,
                 const hknpShape *shape, const void *argument5, const void *argument6,
                 hkArray<u32> *keys, hkAabb *aabb, KeyQueryTimers00172f60 *timers)
{
    const int queryTimerDisabled = timers->queryTimer.disabled;
    u32 queryStart;
    if (!queryTimerDisabled) {
        queryStart = ThreadBuffer::readTimeStampCounter();
    }
    aabb->FUN_0014a220();
    shape->unknownVirtual25(argument1, argument2, argument3, argument6, argument5, keys, aabb);
    if (!queryTimerDisabled) {
        timers->queryTimer.ticks += ticksBetween(queryStart, ThreadBuffer::readTimeStampCounter());
        timers->queryTimer.count++;
    }
    const int numKeys = keys->getSize();
    timers->numKeys += numKeys;
    u32 sortStart;
    if (!timers->sortTimer.disabled) {
        sortStart = ThreadBuffer::readTimeStampCounter();
    }
    hkAlgorithm::explicitStackQuickSort(keys->data, numKeys, hkAlgorithm::less<u32>());
    if (!timers->sortTimer.disabled) {
        timers->sortTimer.ticks += ticksBetween(sortStart, ThreadBuffer::readTimeStampCounter());
        timers->sortTimer.count++;
    }
    return numKeys;
}
