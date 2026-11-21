/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_animationcamera.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016c7d08.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object Init makes (`mov rsi, [0x5939080]`) */
extern Type00503fb0 *D_5939080;

/* derived name: the made object's class, one over the reference's (the new
 * pointer compared first after the exchange), with the making as its own
 * inline function: the name's temporary ends inside it, so its release is
 * gone once the call is known not to change it (as Value00d48670's,
 * tlg_game_object016ba510.h); not traced otherwise */
struct Value00afa950 : Object016b9108 {
    static Value00afa950 *make()
    {
        return static_cast<Value00afa950 *>(FUN_00cbc5a0(D_5945a38, D_5939080, Name(), 0));
    }
};

extern const char D_15ab50a[]; /* "AnimationCamera(%s)::Init\n" */

/* Slot 5 of AnimationCamera's vtable (its pointer at 0x16b4700), written
 * as a free function as FollowCamera's (leaf_0061c420.cpp): an object of
 * the type at 0x5939080 is made under the empty name (FUN_00cbc5a0, mode 0)
 * and the reference at +0x1b8 set to it, then the Init message with the
 * name's string. */
void FUN_00afa950(AnimationCamera *self) /* derived name */
{
    self->held1b8.set(Value00afa950::make());
    FUN_00c831d0(self, D_15ab50a, D_17ac870[self->name.index].string0);
}
