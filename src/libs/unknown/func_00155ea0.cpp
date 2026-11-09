/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ShapeWatcherOwner::FUN_00155ea0(const hknpBody *body)
{
    int index = -1;
    const int numWatchers = watchers.getSize();
    for (int i = 0; i < numWatchers; i++) {
        if (watchers[i]->shape == body->shape) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        if (otherWatchers.getSize()) {
            watchers.pushBack(otherWatchers[otherWatchers.getSize() - 1]);
            otherWatchers.popBack();
        } else {
            watchers.pushBack(new ShapeWatcher(this));
        }
        ShapeWatcher *watcher = watchers[numWatchers];
        watcher->shape = body->shape;
        watcher->changeFlags.clear();
        hknpShapeSignals *signals = watcher->shape->unknownVirtual8();
        new MemberSlot00155b00(&signals->shapeMutated, watcher, &ShapeWatcher::FUN_00155b00);
        new MemberSlot00155b10(&signals->shapeDestroyed, watcher, &ShapeWatcher::FUN_00155b10);
        index = numWatchers;
    }
    watchers[index]->bodyIds.pushBack(body->id);
}
