/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ShapeWatcherOwner::FUN_00156110(const hknpBody *body)
{
    int index = -1;
    const int numWatchers = watchers.getSize();
    for (int i = 0; i < numWatchers; i++) {
        if (watchers[i]->shape == body->shape) {
            index = i;
            break;
        }
    }
    ShapeWatcher *watcher = watchers[index];
    watcher->bodyIds.removeAt(watcher->bodyIds.indexOf(body->id));
    if (watcher->bodyIds.getSize() == 0) {
        hknpShapeSignals *signals = watcher->shape->unknownVirtual8();
        signals->shapeMutated.unsubscribe(watcher, &ShapeWatcher::FUN_00155b00);
        signals->shapeDestroyed.unsubscribe(watcher, &ShapeWatcher::FUN_00155b10);
        watcher->shape = HK_NULL;
        watchers.removeAt(index);
        otherWatchers.pushBack(watcher);
    }
}
