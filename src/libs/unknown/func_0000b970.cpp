/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 11, an id pushed on the array under the critical
 * section. */
void Object0000b330::FUN_0000b970(int id)
{
    criticalSection.enter();
    array.pushBack(id);
    criticalSection.leave();
}

/* derived name: slot 12, the last id dropped under the critical section. */
void Object0000b330::FUN_0000ba70()
{
    criticalSection.enter();
    array.popBack();
    criticalSection.leave();
}
