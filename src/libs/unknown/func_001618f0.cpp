/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the record's constructor: no body, on no list, no flags. */
hknpBodyManager::ScheduledBodyChange::ScheduledBodyChange()
    : bodyId(0x7fffffff), listIndex(0x7fffffff)
{
    flags = 0;
}
