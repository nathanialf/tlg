/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8fd0.h"

/* FUN_00c822d0: an object being destroyed (Object016b8828's destructor,
 * leaf_00cb32e0.cpp) taken out of the registry under its mutex: out of the
 * objects it holds, the others kept in order, and, when it has a place in a
 * list, out of the list that holds it (the last of each list searched that
 * has it), the list's last object put in its place and given that place.
 * derived name */
void FUN_00c822d0(Registry0593a938 *registry, Object016b8828 *object)
{
    registry->mutex.lock();
    const int index = registry->objects.indexOf(object);
    if (index >= 0)
        registry->objects.removeAt(index);
    if (object->slot != -1) {
        unsigned list = ~0u;
        unsigned found = ~0u;
        for (unsigned k = 0; k < 2; ++k) {
            for (unsigned i = 0; i < registry->listCounts[k]; ++i) {
                if (registry->lists[k][i] == object) {
                    list = k;
                    found = i;
                    break;
                }
            }
        }
        if (found < registry->listCounts[list] - 1) {
            registry->lists[list][found] = registry->lists[list][registry->listCounts[list] - 1];
            registry->lists[list][registry->listCounts[list] - 1]->slot = object->slot;
        }
        --registry->listCounts[list];
    }
    registry->mutex.unlock();
}
