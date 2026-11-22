/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names throughout: FUN_00614eb0, called three times by
 * FUN_00645d80 (0x64eebb, 0x64f41d, 0x64f83d) with the object at +0x28 of
 * its owner. None of the fields is traced beyond what it reads. */
struct Node00614eb0 { /* derived name */
    u8 unknown0[0x210];
    Name name; /* +0x210 */
};

class Target00614eb0 : public Object016b9108 /* derived name */
{
  public:
    Node00614eb0 *node28; /* +0x28 */
    int unknown30;        /* +0x30 */
};

extern Type00503fb0 *D_5946a58; /* derived name: the target's class */

/* derived name: a 64-byte clip: a time at +0x20 and its target at +0x38 */
struct Clip00614eb0 {
    u8 unknown0[0x20];
    float time; /* +0x20 */
    u8 unknown24[0x14];
    Target00614eb0 *target; /* +0x38 */
};

struct Player00614eb0 { /* derived name */
    u8 unknown0[0x50];
    Clip00614eb0 clip; /* +0x50 */
    u8 unknown90[0x50];
    Array05943280<Clip00614eb0> clips; /* +0xe0 */
    u8 unknownf8[0xcc];
    int clipCount; /* +0x1c4 */
    u8 unknown1c8[0x10];
    int clipIndex; /* +0x1d8 */

    /* whether a clip plays: one of the list by a set index, else the
     * clip of its own with a time from 0 to 1 and a live target */
    bool playing() const
    {
        if (clipCount)
            return clipIndex >= 0;
        return !(clip.time < 0.0f) && !(clip.time > 1.0f) && clip.target &&
               clip.target->unknown30 != 0;
    }

    const Clip00614eb0 &current() const
    {
        if (clipCount)
            return clips.at(clipIndex);
        return clip;
    }
};

struct Owner00614eb0 { /* derived name */
    u8 unknown0[0x1068];
    Array05943280<Name> names; /* +0x1068 */
};

/* derived name: whether the player's current clip has a target of the
 * class at 0x5946a58 whose node's name is one of the owner's names */
// NONMATCHING: the base keeps whether a clip plays as a value (`shr edx, 0x1f; xor edx, 1`,
// the own clip's tests ending in `movzx edx, al`) tested after the join, and reads the count
// again for the current clip; the build threads every arm into the test
bool FUN_00614eb0(const Owner00614eb0 *owner, const Player00614eb0 *player)
{
    if (!player->playing())
        return false;
    const Target00614eb0 *target = player->current().target;
    if (!target || !target->isKindOf(D_5946a58))
        return false;
    const Node00614eb0 *node = target->node28;
    if (!node)
        return false;
    for (unsigned i = 0; i < owner->names.size(); ++i)
        if (owner->names.at(i) == node->name)
            return true;
    return false;
}
