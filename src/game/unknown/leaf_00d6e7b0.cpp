/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived name: a global array of references another thread may replace,
 * with its spin lock at 0x5989eb4; its destructor is registered by
 * FUN_00d701d0 (leaf_013bb780.cpp) */
extern Array01343a80<AtomicRef0045c470<Object016b9108>> D_5989ea0;

/* derived name: the array's unordered removal, out of line (leaf_00d703b0.cpp) */
void FUN_00d703b0(Array05943280<AtomicRef0045c470<Object016b9108>> *array, int index);

/* derived name: under the array's lock, every object the array holds the
 * last reference to and whose flag 2 at +0x16 is set is taken out of it,
 * the last element put in its place and looked at next (the index kept
 * signed: `movsxd rcx, ebx` each pass, `cmp ebx, eax; jl`; the count read
 * again after each removal) */
void FUN_00d6e7b0() /* derived name */
{
    D_5989ea0.lock.lock();
    for (int i = 0; i < int(D_5989ea0.size()); ++i) {
        Object016b9108 *object = D_5989ea0.at(i).get();
        if (object->references == 1 && (object->flags16 & 2)) {
            FUN_00d703b0(&D_5989ea0, i);
            --i;
        }
    }
    D_5989ea0.lock.unlock();
}
