/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A pair of bodies the reader's stream holds (derived names). */
struct BodyPair00063ec0 /* derived name */
{
    int bodyIdA;
    int bodyIdB;
};

/* A body neither static nor active adds its group's entries not yet
 * flagged, each flagged and its id appended. derived name. */
inline void hknpWorldObject4f8::addGroupIds(const hknpBody &body, hkArray<int> &ids)
{
    if (!(body.flags & 9)) {
        int id = unknown18[body.indexIntoActiveListOrDeactivatedIslandId]->firstId;
        do {
            Entry18 *entry = unknown18[id];
            if (!entry->flag61) {
                entry->flag61 = true;
                ids.pushBack(id);
            }
            id = entry->nextId;
        } while (id != 0x7fffffff);
    }
}

/* Each pair's two bodies' groups. */
void hknpWorldObject4f8::FUN_00063ec0(hkBlockStreamReader &reader, hkArray<int> &ids)
{
    const hknpWorld *const theWorld = world;
    for (const BodyPair00063ec0 *pair = static_cast<const BodyPair00063ec0 *>(reader.access());
         pair;
         pair = static_cast<const BodyPair00063ec0 *>(reader.advance(sizeof(BodyPair00063ec0)))) {
        const hknpBody &bodyA = theWorld->bodyManager.bodies[pair->bodyIdA];
        const hknpBody &bodyB = theWorld->bodyManager.bodies[pair->bodyIdB];
        addGroupIds(bodyA, ids);
        addGroupIds(bodyB, ids);
    }
}
