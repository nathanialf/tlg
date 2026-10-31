/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the constraint's link at that body's end takes the body's first
 * constraint, and the constraint becomes the body's first. */
void hknpConstraintManager::ConstraintLists::FUN_0017a290(unsigned int constraintId,
                                                          const hknpConstraint *constraints,
                                                          int bodyId)
{
    const hknpConstraint &constraint = constraints[constraintId];
    Links &links = constraintLinks[constraint.id];
    const int bodyIdA = constraint.bodyIdA;
    u32 *next = bodyIdA == bodyId ? &links.nextOfBodyA : &links.nextOfBodyB;
    u32 &first = firstConstraintOfBody.data[bodyId];
    *next = first;
    first = constraintId;
}
