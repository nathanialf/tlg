/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The collide task's destructor (slot 0 of its vtable): the array's
 * storage given back when it outgrew the object. */
BroadPhaseCollideTask::~BroadPhaseCollideTask() {}
