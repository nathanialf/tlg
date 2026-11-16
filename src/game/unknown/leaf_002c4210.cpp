/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2VolumeRefreshSensors"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2236c4): reads its first
 * argument as an object through FUN_00c8c290 with a reader of the frame (as
 * leaf_0046bc50.cpp's); when it is of the type D_5829020 points to (or one
 * derived from it, leaf_00296ed0.cpp's) and holds an owner at +0x28, looks
 * the 64-bit value at 0x57cb848 up in it through FUN_00c57870 with 0 and,
 * when a record is found, calls slot 10 of the object at the record's +0x238
 * with the object and the record and returns 1; else returns 0. The C
 * function's own name is unknown. */
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

struct Record002c4210; /* derived name */

/* derived names: the object at +0x238 of the record: slot 10 is given the
 * object and the record, the others are not traced */
class Sensors002c4210 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
    virtual void slot10(Object016b9108 *object,
                        Record002c4210 *record); /* derived name; not traced */
};

struct Record002c4210 /* derived name */
{
    u8 unknown0[0x238];
    Sensors002c4210 *sensors; /* +0x238 */
};

struct Owner00c57870; /* derived name */

class Object002c4210 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[4];
    Owner00c57870 *unknown28; /* +0x28 */
};

extern Type00503fb0 *D_5829020; /* derived name: the object's type */
extern u64 D_57cb848;           /* derived name: the key looked up */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
Record002c4210 *FUN_00c57870(Owner00c57870 *owner, u64 key, int unknown2);  /* derived name */

int FUN_002c4210(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5829020)) {
        Object002c4210 *volume = static_cast<Object002c4210 *>(object);
        if (volume->unknown28) {
            if (Record002c4210 *record = FUN_00c57870(volume->unknown28, D_57cb848, 0)) {
                record->sensors->slot10(volume, record);
                return 1;
            }
        }
    }
    return 0;
}
