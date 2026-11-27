/* src/game/joints.cpp: the lookup of a model's joint by name, out of line.
 * It has no address of its own in the base: the link inlines it at each
 * caller (tlg_game_joints0148a5e0.h). The file's name is derived. */
#include "tlg_game_joints0148a5e0.h"

s16 Skeleton0148a5e0::jointIndex(const Name &name) const
{
    const Model0148a5e0 *joints = model;
    if (joints->hashed) {
        for (const JointEntry0148a5e0 *entry = joints->buckets[name.index & 63]; entry;
             entry = entry->next10)
            if (entry->hash0 == name.index && entry->name4 == name.index)
                return entry->index8;
        return -1;
    }
    for (unsigned i = 0; i < joints->joints.size(); ++i)
        if (joints->joints.at(i)->name210 == name.index)
            return i;
    return -1;
}
