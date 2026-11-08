/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A body's key: its byte at +0x7f and its id (derived name). */
static inline u64 keyOf(const hknpBody &body)
{
    BodyKey0005c120 key;
    key.byte7f = body.byte7f;
    key.bodyId = body.id;
    return *reinterpret_cast<const u64 *>(&key);
}

/* A body is still the one a key names when it is added, in the broad phase,
 * and its byte and id make the key, compared as one word (derived name). */
static inline bool isSameBody(const hknpBody &body, const BodyKey0005c120 &key)
{
    return (body.flags & 3) && body.broadPhaseId != 0xffffffff &&
           keyOf(body) == *reinterpret_cast<const u64 *>(&key);
}

/* Two bodies' ids written to the end of a stream (derived name). */
static inline void writeIds(hkBlockStreamWriter &writer, u32 idA, u32 idB)
{
    u32 *ids = static_cast<u32 *>(writer.reserve(2 * sizeof(u32)));
    ids[0] = idA;
    ids[1] = idB;
    /* Counted in this file with the offset first: GVN widens the
     * offset's load (8-byte aligned in the local writer) over the count
     * beside it (`mov rax, [offset]; ...; shr rax, 32`), where advance()
     * reads the count first. */
    writer.currentByteOffset += 2 * sizeof(u32);
    writer.currentNumElements++;
}

void FUN_00175010(hknpWorld *world, BlockCache *cache, const hkArray<BodyKeyPair0005c120> &pairs,
                  hkBlockStream *stream) /* derived name */
{
    hkBlockStreamWriter writer;
    writer.FUN_000938c0(cache, stream);
    const int numPairs = pairs.getSize();
    for (int i = 0; i < numPairs; i++) {
        const BodyKeyPair0005c120 &pair = pairs[i];
        const hknpBody &bodyA = world->bodyManager.bodies[pair.bodyA.bodyId];
        if (!isSameBody(bodyA, pair.bodyA)) {
            continue;
        }
        const hknpBody &bodyB = world->bodyManager.bodies[pair.bodyB.bodyId];
        if (!isSameBody(bodyB, pair.bodyB)) {
            continue;
        }
        writeIds(writer, bodyA.id, bodyB.id);
    }
    writer.FUN_00093a10();
}

// NONMATCHING: the inline-cost margin (654 bytes against 869): the base inlines 0x175010 for the
// flag's other arm, which 3.3 prices at 230 against 225 (`-debug-only=inline`, a85/inl.sh); the
// sixth witness of the class. Inlined for a diagnostic (`-inline-threshold=1000`) the function is 869
// bytes as the base with 19 lines apart: the inactive body's index chosen in 32 bits and then
// extended (`cmovne r14d, eax; movsxd`) where the base chooses between the two extended ids (`cmove
// r14, [rbp-0x78]`), the index of the first body kept in a register rather than its extension
// spilled, and the island's writer test compiled `cmp 0xfe0; jg` where the base has `cmp 0xfe1; jge`.
void hknpWorldStreams260::FUN_00175160(hknpWorldContextPool::Context *context,
                                       hkBlockStream *stream)
{
    BlockCache *cache = context->cache250;
    hknpWorld *world = context->world;
    if (world->enabled4f0) {
        hkBlockStreamWriter writer;
        writer.FUN_000938c0(cache, stream);
        const int numPairs = arrayC00.getSize();
        for (int i = 0; i < numPairs; i++) {
            const BodyKeyPair0005c120 &pair = arrayC00[i];
            const int indexA = pair.bodyA.bodyId;
            const hknpBody *bodies = world->bodyManager.bodies.begin();
            const hknpBody &bodyA = bodies[indexA];
            if (!isSameBody(bodyA, pair.bodyA)) {
                continue;
            }
            const int indexB = pair.bodyB.bodyId;
            const hknpBody &bodyB = bodies[indexB];
            if (!isSameBody(bodyB, pair.bodyB)) {
                continue;
            }
            const u32 idA = bodyA.id;
            const u32 idB = bodyB.id;
            const int flagsA = bodyA.flags;
            const int flagsB = bodyB.flags;
            /* A pair with an inactive dynamic body and no active one is
             * kept with that body's island; the rest go to the stream. */
            if ((!(flagsA & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) &&
                 !(flagsB & hknpBody::IS_ACTIVE)) ||
                (!(flagsA & hknpBody::IS_ACTIVE) &&
                 !(flagsB & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)))) {
                world->object4f8->FUN_000655b0(idA, idB);
                const hknpBody &inactiveBody =
                    bodies[(bodyA.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) ? indexB
                                                                                       : indexA];
                hknpWorldObject4f8::Entry18 *island =
                    world->object4f8
                        ->unknown18[inactiveBody.indexIntoActiveListOrDeactivatedIslandId];
                hknpBodyIdPair &kept = *island->bodyPairs.expandBy(1);
                kept.bodyIdA.value = idA;
                kept.bodyIdB.value = idB;
            } else {
                writeIds(writer, idA, idB);
            }
        }
        writer.FUN_00093a10();
    } else {
        FUN_00175010(world, cache, arrayC00, stream);
    }
    arrayC00.size = 0;
}
