/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 12 of the pool: clear every worker's timers, its
 * monitor stream emptied. */
void Pool00007880::FUN_00007850() /* derived name */
{
    for (int i = 0; i < count; i++) {
        workers[i].monitorStreamEnd = workers[i].monitorStreamBegin;
        workers[i].timersCleared = true;
    }
}
