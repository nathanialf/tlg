/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A body's key: its byte at +0x7f and its id (derived name). */
static inline u64 keyOf(const hknpBody &body)
{
    BodyKeyPair00175010::Key key;
    key.byte7f = body.byte7f;
    key.id = body.id;
    return *reinterpret_cast<const u64 *>(&key);
}

/* A body is still the one a key names when it is added, in the broad phase,
 * and its byte and id make the key, compared as one word (derived name). */
static inline bool isSameBody(const hknpBody &body, const BodyKeyPair00175010::Key &key)
{
    return (body.flags & 3) && body.broadPhaseId != 0xffffffff &&
           keyOf(body) == *reinterpret_cast<const u64 *>(&key);
}

void FUN_00175010(hknpWorld *world, BlockCache *cache, const hkArray<BodyKeyPair00175010> &pairs,
                  hkBlockStream *stream) /* derived name */
{
    hkBlockStreamWriter writer;
    writer.FUN_000938c0(cache, stream);
    const int numPairs = pairs.getSize();
    for (int i = 0; i < numPairs; i++) {
        const BodyKeyPair00175010 &pair = pairs[i];
        const hknpBody &bodyA = world->bodyManager.bodies[pair.a.id];
        if (!isSameBody(bodyA, pair.a)) {
            continue;
        }
        const hknpBody &bodyB = world->bodyManager.bodies[pair.b.id];
        if (!isSameBody(bodyB, pair.b)) {
            continue;
        }
        const u32 idA = bodyA.id;
        const u32 idB = bodyB.id;
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
    writer.FUN_00093a10();
}
