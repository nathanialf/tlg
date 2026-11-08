/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 78 of 193 (81 under LocalArray's SDK order), 728 bytes against 760: the base
// stores the bit field's words in the SDK's order (data, capacity, local copy: 0x37333,
// 0x37340, 0x37343, a fifth storing witness for D41), its reserve kept as a call; past that,
// the base spills `this` at the entry (0x372b7) and the release's next free index and flag
// address in the loop (0x374a6, 0x374ae), where this keeps them in callee-saved registers:
// greedy's splits, the frame 16 bytes smaller here.
void hknpMotionPropertiesLibrary::FUN_000372a0(const hknpWorld *worlds, int numWorlds)
{
    LocalBitField usedIds(entries.elements.getSize(), 0);
    for (int i = 0; i < numWorlds; i++) {
        for (hknpMotionManager::MotionIterator it(worlds[i].motionManager); it.index != 0x7fffffff;
             it.next()) {
            usedIds.set(it.getMotion().motionPropertiesId);
        }
    }
    for (int i = 5; i < entries.elements.getSize(); i++) {
        if (!usedIds.get(i)) {
            hknpMotionPropertiesId id;
            id.value = u16(i);
            if (!hknpMotionPropertiesFreeListArrayOperations::isEmpty(entries[id])) {
                entries.release(id);
            }
        }
    }
}
