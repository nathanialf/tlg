/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: 107 of 187, 671 bytes against 679: every block in the base's
 * order and form but the registers. The base keeps the pair's ids in
 * r10d/r11d, the first body's offset in r8, and the chosen bodies in r9 and
 * r10 across the entry's recording (copied into rsi and rdx at the call,
 * the recording's own temporaries in esi and edx); here the chosen bodies
 * go straight into rsi and rdx and the recording uses edi, eax and r8.
 * Each entry is written through one data load after its count is cleared,
 * the array's data read again for the start point (0x174240, the base). */
/* Each new pair of the range given its caches: a pair with a broad phase
 * trigger material gets a trigger cache when either body raises trigger
 * events; a pair of two static or keyframed bodies none unless either has
 * one of the dispatcher's keep flags; any other the creator of its shapes'
 * dispatch types, the body of the lower type (or of the lower id) first.
 * With an entries array each pair's caches are recorded as a range of the
 * writer. */
void FUN_00174100(const hknpCollisionDispatcher *dispatcher, const hknpWorld *world,
                  const hkBlockStreamRange *range, hkBlockStreamWriter *writer,
                  hkArray<hkBlockStreamRange> *entries)
{
    const hknpMaterial *materials = world->materialLibrary->entries.elements.data;
    hkBlockStreamReader reader;
    reader.FUN_000937f0(range);
    if (entries) {
        entries->reserveExactly(entries->getSize() + range->numElements);
    }
    for (const BodyPair00174100 *pair = static_cast<const BodyPair00174100 *>(reader.access());
         pair;
         pair = static_cast<const BodyPair00174100 *>(reader.advance(sizeof(BodyPair00174100)))) {
        const hknpBody *bodies = world->bodyManager.bodies.data;
        const hknpBody *bodyA = &bodies[int(pair->bodyIdA)];
        const hknpBody *bodyB = &bodies[int(pair->bodyIdB)];
        if (materials[bodyA->materialId.value].triggerType ==
                hknpMaterial::TRIGGER_TYPE_BROAD_PHASE ||
            materials[bodyB->materialId.value].triggerType ==
                hknpMaterial::TRIGGER_TYPE_BROAD_PHASE) {
            if (!((bodyA->flags | bodyB->flags) & hknpBody::RAISE_TRIGGER_EVENTS)) {
                continue;
            }
            hkBlockStreamRange *entry = HK_NULL;
            if (entries) {
                const int index = entries->getSize();
                entries->setSizeUnchecked(index + 1);
                (*entries)[index].numElements = 0;
                entry = &(*entries)[index];
                entry->setStartPoint(writer);
            }
            if (pair->bodyIdA < pair->bodyIdB) {
                FUN_001785a0(world, bodyA, bodyB, writer);
            } else {
                FUN_001785a0(world, bodyB, bodyA, writer);
            }
            if (entry) {
                entry->FUN_00092220(writer);
            }
            continue;
        }
        if ((bodyA->flags & 5) && (bodyB->flags & 5) &&
            !(dispatcher->keepCacheFlags & (bodyB->flags | bodyA->flags))) {
            continue;
        }
        const u8 typeA = bodyA->shape->dispatchType;
        const u8 typeB = bodyB->shape->dispatchType;
        const hknpBody *first = bodyA;
        const hknpBody *second = bodyB;
        if (typeB < typeA || (typeB == typeA && pair->bodyIdB < pair->bodyIdA)) {
            first = bodyB;
            second = bodyA;
        }
        hkBlockStreamRange *entry = HK_NULL;
        if (entries) {
            const int index = entries->getSize();
            entries->setSizeUnchecked(index + 1);
            (*entries)[index].numElements = 0;
            entry = &(*entries)[index];
            entry->setStartPoint(writer);
        }
        dispatcher->dispatchTable[typeA][typeB](world, first, second, writer);
        if (entry) {
            entry->FUN_00092220(writer);
        }
    }
}
