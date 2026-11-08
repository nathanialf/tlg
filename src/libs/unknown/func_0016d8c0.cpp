/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: 616 bytes against 680 (9 of 170 by position): the members'
 * destruction and the constraint's are the base's; the walk is not. The
 * base keeps the iterator as one 64-bit value (the id in the high half,
 * `mov r14d, r14d; or r14, rdi` at each step, SROA's integer form of the
 * struct returned in rax) and peels the first slot's test; here SROA splits
 * it into two 32-bit values. The iterator's by-value form returned through
 * the ABI's i64 is the lead (the in-place form is worse, 515 bytes). */
hknpConstraintManager::~hknpConstraintManager()
{
    for (Iterator it = getIterator(); it.constraintId != 0x7fffffff; it = getNext(it)) {
        constraints[it.constraintId].~hknpConstraint();
    }
    if (!userBuffer) {
        FUN_0000bc00(*D_16dc070->temp58, constraints);
        constraints = HK_NULL;
        capacity = 0;
    }
}
