/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2RefreshStaticVolSensor"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x22215e): reads
 * its first argument as an object through FUN_00c8c290 with a reader of the
 * frame (as leaf_0046bc50.cpp's); when it is of the type D_5829020 points to
 * (or one derived from it) calls slot 10 of the object at its +0x310 with
 * it and returns 1, else returns 0. The C function's own name is unknown. */
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

/* derived names: the object at +0x310: slot 10 is given the object (`mov
 * rsi` kept from the test), the others are not traced */
class Sensor00296ed0 /* derived name */
{
  public:
    virtual void slot0();                        /* derived name; not traced */
    virtual void slot1();                        /* derived name; not traced */
    virtual void slot2();                        /* derived name; not traced */
    virtual void slot3();                        /* derived name; not traced */
    virtual void slot4();                        /* derived name; not traced */
    virtual void slot5();                        /* derived name; not traced */
    virtual void slot6();                        /* derived name; not traced */
    virtual void slot7();                        /* derived name; not traced */
    virtual void slot8();                        /* derived name; not traced */
    virtual void slot9();                        /* derived name; not traced */
    virtual void slot10(Object016b9108 *object); /* derived name; not traced */
};

class Object00296ed0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x2ec];
    Sensor00296ed0 *sensor; /* +0x310 */
};

extern Type00503fb0 *D_5829020; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

int FUN_00296ed0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5829020)) {
        static_cast<Object00296ed0 *>(object)->sensor->slot10(object);
        return 1;
    }
    return 0;
}
