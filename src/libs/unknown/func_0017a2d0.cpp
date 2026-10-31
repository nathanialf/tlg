/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpConstraintManager::ConstraintLists::FUN_0017a2d0(unsigned int constraintId,
                                                          const hknpConstraint *constraints,
                                                          int bodyId)
{
    u32 &first = firstConstraintOfBody.data[bodyId];
    u32 *link = &first;
    unsigned int previous;
    unsigned int current = 0x7fffffff;
    do {
        previous = current;
        current = *link;
        const hknpConstraint &constraint = constraints[current];
        Links &links = constraintLinks[constraint.id];
        link = constraint.bodyIdA == u32(bodyId) ? &links.nextOfBodyA : &links.nextOfBodyB;
    } while (current != constraintId);
    if (previous == 0x7fffffff) {
        first = *link;
    } else {
        u32 *previousLink = linkAt(previous, constraints, bodyId);
        *previousLink = *link;
    }
    *link = 0x7fffffff;
}
