/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* The solver factory task's destructor: the vtables restored, the arrays
 * destroyed (a tail call of RefArrays's destructor, 0x48040). Its thunk
 * from the task interface at +0x10 (0x14e7b0) has this body inlined.
 * NONMATCHING: the vtable 0x16a4080 has no row (D14); the instructions are
 * equal. */
hknpSolverFactoryTask::~hknpSolverFactoryTask() {}
