/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

bool hknpWorldObject4f8::FUN_00064db0(const hknpBodyId *bodyIds, int numBodyIds, int &groupOut)
{
    groupOut = 0x7fffffff;
    bool activate = false; /* derived name */
    for (int i = 0; i < numBodyIds; i++) {
        const hknpBody &body = world->bodyManager.bodies[bodyIds[i].value];
        const int index = body.indexIntoActiveListOrDeactivatedIslandId;
        if (index == 0x7fffffff) {
            continue;
        }
        if (body.flags & hknpBody::IS_STATIC) {
            continue;
        }
        if (body.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) {
            activate = true;
            continue;
        }
        const Entry18 *first = unknown18[unknown18[index]->firstId];
        if (first->flag61) {
            activate = true;
        }
        if (groupOut == 0x7fffffff) {
            groupOut = first->firstId;
        } else {
            const int firstA = unknown18[groupOut]->firstId; /* derived name */
            const int firstB = first->firstId;               /* derived name */
            if (firstA != firstB) {
                Entry18 *last; /* derived name */
                int id = firstA;
                do {
                    last = unknown18[id];
                    id = last->nextId;
                } while (id != 0x7fffffff);
                last->nextId = firstB;

                setGroupFirstId(firstB, firstA);
            }
        }
    }
    if (groupOut != 0x7fffffff && activate) {
        activateGroup(unknown18[groupOut]);
    }
    return !activate;
}
