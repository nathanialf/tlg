/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "PlayerAcceptInstruction"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x22366c): reads
 * its first argument as an object through FUN_00c8c290 with a reader of the
 * frame (as leaf_0046bc50.cpp's); when it is of the type D_57d35a8 points to
 * (or one derived from it) sets the int at +0x72c of the record at its
 * +0x570 to 1 and the float after it to 1 and returns 1, else returns 0.
 * The C function's own name is unknown. */
struct ArgumentReader00c8c290 { /* derived name */

    explicit ArgumentReader00c8c290(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index =
            -(int)((unsigned long)((char *)state_->top - (char *)state_->base) / sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

struct Record00421840 { /* derived name */
    u8 unknown0[0x72c];
    int unknown72c;   /* +0x72c */
    float unknown730; /* +0x730 */
};

class Object00421840 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x54c];
    Record00421840 *record; /* +0x570 */
};

extern Type00503fb0 *D_57d35a8; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

int FUN_00421840(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57d35a8)) {
        Record00421840 *record = static_cast<Object00421840 *>(object)->record;
        record->unknown72c = 1;
        record->unknown730 = 1.0f;
        return 1;
    }
    return 0;
}
