/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2VolumePrepareRestart"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2236ae): reads its
 * first argument as an object through FUN_00c8c290 (as leaf_002c4210.cpp's);
 * when it is of the type D_5829020 points to (or one derived from it) and
 * holds an owner at +0x28 in which FUN_00c57870 finds a record for the
 * 64-bit value at 0x57cb848 (with 0), sets 1 at +0x120, 10 at +0x128 and 0
 * at +0x11c of the object at the record's +0x238; with two arguments the
 * second is read as an integer (FUN_00c8d080) and +0x11c set to whether it
 * is not 0. Returns 1 when a record was found, else 0. */
struct ArgumentReader00c8c290 { /* derived name */

    /* a reader at an argument of the frame (0 the first), its index taken
     * from the top: the argument less the count of arguments */
    explicit ArgumentReader00c8c290(lua_State *state_, int argument = 0)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = argument - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                                 sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

struct Restart002c40a0 /* derived name */
{
    u8 unknown0[0x11c];
    int unknown11c; /* +0x11c */
    int unknown120; /* +0x120 */
    u8 unknown124[4];
    int unknown128; /* +0x128 */
};

struct Record002c40a0 /* derived name */
{
    u8 unknown0[0x238];
    Restart002c40a0 *sensors; /* +0x238 */
};

struct Owner00c57870; /* derived name */

class Object002c40a0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[4];
    Owner00c57870 *unknown28; /* +0x28 */
};

extern Type00503fb0 *D_5829020; /* derived name: the object's type */
extern u64 D_57cb848;           /* derived name: the key looked up */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8d080(ArgumentReader00c8c290 *reader, long *value);             /* derived name */
Record002c40a0 *FUN_00c57870(Owner00c57870 *owner, u64 key, int unknown2);  /* derived name */

int FUN_002c40a0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5829020)) {
        Object002c40a0 *volume = static_cast<Object002c40a0 *>(object);
        if (volume->unknown28) {
            if (Record002c40a0 *record = FUN_00c57870(volume->unknown28, D_57cb848, 0)) {
                record->sensors->unknown120 = 1;
                record->sensors->unknown128 = 10;
                record->sensors->unknown11c = 0;
                if (argumentCount(state) == 2) {
                    long value = 0;
                    ArgumentReader00c8c290 second(state, 1);
                    FUN_00c8d080(&second, &value);
                    record->sensors->unknown11c = value != 0;
                }
                return 1;
            }
        }
    }
    return 0;
}
