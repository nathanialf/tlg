/* src/include/tlg_game_joints0148a5e0.h: a model's joints and the lookup of
 * a joint by name (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_JOINTS0148A5E0_H
#define TLG_GAME_JOINTS0148A5E0_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_math.h"

/* derived names: a joint of a model, its position at +0x120 (copied by
 * FUN_0045e2c0) and its name's index at +0x210 (as leaf_001b5840.cpp's
 * nodes) */
struct Joint0148a5e0 { /* derived name */
    u8 unknown0[0x120];
    Float4 position; /* +0x120 */
    u8 unknown130[0xe0];
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

/* derived names: the member at +0x40 of a model's owner that holds the
 * model: the lookups of joints by name are its own (FUN_013cde10 is given
 * its address, `lea rdi, [r13+0x40]` at 0xf301eb, and reads the model at
 * +0x0 of it) */
struct Skeleton0148a5e0 { /* derived name */
    Model0148a5e0 *model; /* +0x0 */

    /* the index of the joint with the name, -1 without one: through the
     * table when the model has it, else each joint in turn. Out of line
     * (src/game/joints.cpp): the base has no copy of it, and 136 functions
     * hold its body (the test of +0x478 and the bucket `and ecx, 0x3f`), so
     * the link inlines it at every call. At the unit stage it is a call that
     * takes the name's address: the name's last release after it is then
     * not a sibling call (FUN_0148a5e0: `call 0xd66e30` before the
     * epilogue; TailCallElim runs in the unit's pipeline only). */
    s16 jointIndex(const Name &name) const; /* derived name */

    /* FUN_013cde10 (leaf_013cde10.cpp): the joints' indices of a list of
     * names */
    int findJoints(Array05943280<int> &indices, const char *const *names,
                   int count) const; /* derived name */
};

struct Owner0148a5e0 { /* derived name */
    u8 unknown0[0x40];
    Skeleton0148a5e0 skeleton; /* +0x40 */
};

#endif
