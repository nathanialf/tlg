/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_log.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016c7d08.h"
#include "tlg_game_object05945a38.h"

/* PointingCamera (the class's name from its message
 * "PointingCamera(%s)::Init"; derived names otherwise), its vtable at
 * 0x16ac538 (config/vtables.derived.base.txt). Slot 5 of the vtable (its
 * pointer at 0x16ac570), written as a free function as FollowCamera's
 * (leaf_0061c420.cpp): an object of the type at 0x5813f48 is made under the
 * empty name (FUN_00cbc5a0, mode 0) and the reference at +0x60 set to it,
 * FUN_00afded0 called with 4 and 2, the int at +0x4 of the record at +0x50
 * set to 0x400, then the Init message with the name's string. The other
 * fields are not traced. The name at +0xc is the root class's, through
 * Object016c7d08 (tlg_game_object016c7d08.h). */
class PointingCamera : public Object016c7d08
{
  public:
    virtual ~PointingCamera();

    AtomicRef0045c470<Object016b9108> held60; /* +0x60 */
};

/* derived name: the type of the object Init makes (`mov rsi, [0x5813f48]`) */
extern Type00503fb0 *D_5813f48;

/* derived name: the made object's class, one over the reference's (the new
 * pointer compared first after the exchange), with the making as its own
 * inline function: the name's temporary ends inside it, so its release is
 * gone once the call is known not to change it (as Value00d48670's,
 * tlg_game_object016ba510.h); not traced otherwise */
struct Value006910d0 : Object016b9108 {
    static Value006910d0 *make()
    {
        return static_cast<Value006910d0 *>(FUN_00cbc5a0(D_5945a38, D_5813f48, Name(), 0));
    }
};

extern const char D_158d67e[]; /* "PointingCamera(%s)::Init\n" */

void FUN_00afded0(PointingCamera *self, int unknown, int kind); /* derived name */

void FUN_006910d0(PointingCamera *self) /* derived name */
{
    self->held60.set(Value006910d0::make());
    FUN_00afded0(self, 4, 2);
    self->unknown50->unknown4 = 0x400;
    FUN_00c831d0(self, D_158d67e, D_17ac870[self->name.index].string0);
}
