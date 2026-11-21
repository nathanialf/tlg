/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_object016b9108.h"

/* derived names: the value FUN_0059ddc0's node keeps: two records of 0x58
 * bytes, each made by FUN_00c13820 (not traced). */
struct Record59ddc0 /* derived name */
{
    u8 unknown0[0x58];
};

struct Value59ddc0 /* derived name */
{
    Record59ddc0 first;  /* +0x0 */
    Record59ddc0 second; /* +0x58 */
};

extern Type00503fb0 *D_59453d8; /* derived name: the type FUN_0059ddc0 looks for */

void *FUN_00ca2f80(Object016b9108 *object); /* derived name */
void FUN_00c13820(Record59ddc0 *record, void *unknown18, void *source, int unknown3, int unknown4,
                  int unknown5); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52582e): makes its argument the owner's current node; the state 0
 * becomes 1 and the two records of the node's value are made by
 * FUN_00c13820 from the owner's +0x18 and what FUN_00ca2f80 gives for the
 * owner's +0x28 when that is an object of the type D_59453d8 points to (or
 * derives from it), else null; in the state 0 or 1 the state is then copied
 * to the owner's +0xd8. Returns 0. Handler unknown. */
int FUN_0059ddc0(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    Value59ddc0 *value =
        self->cursor.select(node) ? reinterpret_cast<Value59ddc0 *>(self->cursor.value()) : 0;
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0: {
        *state = 1;
        Object016b9108 *owner = static_cast<Object016b9108 *>(self->unknown28);
        Object016b9108 *found = owner ? kindOf(owner, D_59453d8) : 0;
        void *source = found ? FUN_00ca2f80(found) : 0;
        FUN_00c13820(&value->first, self->unknown18, source, 0, 0, 1);
        FUN_00c13820(&value->second, self->unknown18, source, 0, 0, 1);
    }
    case 1:
        self->unknownd8 = *state;
        break;
    }
    return 0;
}
