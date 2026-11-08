/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

ShapeWatcherOwner::~ShapeWatcherOwner()
{
    const int numWatchers = watchers.getSize();
    for (int i = 0; i < numWatchers; i++) {
        delete watchers[i];
    }
    const int numOtherWatchers = otherWatchers.getSize();
    for (int i = 0; i < numOtherWatchers; i++) {
        delete otherWatchers[i];
    }
}
