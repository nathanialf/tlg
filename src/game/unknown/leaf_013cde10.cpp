/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_joints0148a5e0.h"

/* derived names: the indices of the joints a list of names names, one for
 * each name in the array (its block emptied, then made the count exactly);
 * 1 at the first name the model has no joint for (its index stored as -1),
 * else 0. The names come as C strings (each interned as a copy, the empty
 * name for a null or empty one). 27 callers, each passing its owner's
 * skeleton (`lea rdi, [r13+0x40]` at 0xf301eb) and a list of names it made
 * from Names (`_Znam` of the count's pointers, 0xf301ac). */
int Skeleton0148a5e0::findJoints(Array05943280<int> &indices, const char *const *names,
                                 int count) const
{
    indices.clear();
    indices.resize(count);
    for (int i = 0; i < count; ++i) {
        const Name name(Name::intern(names[i]));
        const s16 index = jointIndex(name);
        indices.at(i) = index;
        if (index < 0)
            return 1;
    }
    return 0;
}
