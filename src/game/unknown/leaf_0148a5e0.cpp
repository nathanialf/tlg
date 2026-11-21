/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: a joint of a model, its name's index at +0x210 (as
 * leaf_001b5840.cpp's nodes) */
struct Joint0148a5e0 { /* derived name */
    u8 unknown0[0x210];
    u32 name210; /* +0x210 */
};

/* derived names: an entry of a model's joint table: the name's index twice
 * (the key and its hash), the joint's index, the next entry of the bucket */
struct JointEntry0148a5e0 { /* derived name */
    u32 hash0;              /* +0x0 */
    u32 name4;              /* +0x4 */
    u16 index8;             /* +0x8 */
    u8 unknowna[0x6];
    JointEntry0148a5e0 *next10; /* +0x10 */
};

/* derived names: a model's joints (+0x238) and, when +0x478 is set, the
 * table of 64 buckets that finds them by name (+0x260) */
struct Model0148a5e0 { /* derived name */
    u8 unknown0[0x238];
    Array05943280<Joint0148a5e0 *> joints; /* +0x238 */
    u8 unknown250[0x10];
    JointEntry0148a5e0 *buckets[64]; /* +0x260 */
    u8 unknown460[0x18];
    int hashed; /* +0x478 */
};

struct Owner0148a5e0 { /* derived name */
    u8 unknown0[0x40];
    Model0148a5e0 *model; /* +0x40 */

    /* the index of the joint with the name, -1 without one: through the
     * table when the model has it, else each joint in turn */
    s16 jointIndex(const Name &name) const /* derived name */
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
};

/* derived names: slot 0 of the vtable at 0x16d7b80 (built by FUN_0129ea30),
 * as leaf_0148c5d0.cpp's: the object passed to FUN_013e8390, then the index
 * of its owner's joint "jt_RotAxis" kept at +0x18 */
struct Object0148a5e0 { /* derived name */
    u8 unknown0[0x8];
    Owner0148a5e0 *owner; /* +0x8 */
    u8 unknown10[0x8];
    int rotAxis; /* +0x18 */
};

void FUN_013e8390(Object0148a5e0 *object); /* derived name */

// NONMATCHING: the name's last release: the base calls FUN_00d66e30 and returns after it, this build
// jumps to it (the call is marked tail before the lookup is inlined here; in the base the lookup,
// inlined at some 20 sites, may come in only at the link, after TailCallElim)
void FUN_0148a5e0(Object0148a5e0 *self) /* derived name */
{
    FUN_013e8390(self);
    self->rotAxis = self->owner->jointIndex(Name("jt_RotAxis"));
}
