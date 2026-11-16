/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks_string.h"

/* derived names: the script C function "Ai2VolumeIsHitVolume"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x223774): reads
 * its first argument as an object through FUN_00c8c290 with a reader of the
 * frame (as leaf_0046bc50.cpp's); when it is of the type D_57cb390 points to
 * (or one derived from it) returns a new table (FUN_00d91880 with no sizes)
 * whose field "isHit" is the object's slot 10 as a number (FUN_00db84e0 sets
 * it from the stack's top three, then the key and the value are popped),
 * else returns nothing. The C function's own name is unknown. */
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

/* derived names: an object of that type: slots 5 to 10 after the root
 * class's; slot 10 takes no argument and returns an int, the others are not
 * traced */
class Object002b0f60 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
    virtual int slot10(); /* derived name; not traced */
};

extern Type00503fb0 *D_57cb390; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

int FUN_002b0f60(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57cb390)) {
        Object002b0f60 *volume = static_cast<Object002b0f60 *>(object);
        FUN_00d91880(state, 0, 0);
        pushString(state, "isHit");
        pushNumber(state, volume->slot10());
        setTable(state);
        return 1;
    }
    return 0;
}
