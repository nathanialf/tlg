/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2ImpulseSensorDelete"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2236f0): reads
 * its first two arguments as objects through FUN_00c8c290 (readers of the
 * frame, as leaf_005f3280.cpp's); when the first is of the type D_5829020
 * points to (leaf_002c4210.cpp's) and the second of the type D_5939080
 * points to (or ones derived from them), and the first holds an owner at
 * +0x28 in which FUN_00c57870 finds a record for the 64-bit value at
 * 0x57cb848 (with 0), the sensor of the record's +0x238 whose +0x48 is the
 * second object is deleted (FUN_002da210 with its index) and 1 is returned;
 * else 0. The C function's own name is unknown. */
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

struct Sensor002dab30 /* derived name */
{
    u8 unknown0[0x48];
    Object016b9108 *target; /* +0x48 */
};

struct Sensors002dab30 /* derived name */
{
    u8 unknown0[0x140];
    Array05943280<Sensor002dab30 *> sensors; /* +0x140 */
};

struct Record002dab30 /* derived name */
{
    u8 unknown0[0x238];
    Sensors002dab30 *sensors; /* +0x238 */
};

struct Owner00c57870; /* derived name */

class Object002dab30 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[4];
    Owner00c57870 *unknown28; /* +0x28 */
};

/* derived name: an object of the second type, a soldier (the type the
 * Soldier_ C functions test); its own members are not read here */
class Soldier002dab30 : public Object016b9108 /* derived name */
{
};

extern Type00503fb0 *D_5829020; /* derived name: the first object's type */
extern Type00503fb0 *D_5939080; /* derived name: the second object's type */
extern u64 D_57cb848;           /* derived name: the key looked up */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
Record002dab30 *FUN_00c57870(Owner00c57870 *owner, u64 key, int unknown2);  /* derived name */
void FUN_002da210(Sensors002dab30 *sensors, int index);                     /* derived name */

int FUN_002dab30(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    Object016b9108 *target = 0;
    ArgumentReader00c8c290 reader(state);
    ArgumentReader00c8c290 second(state, 1);
    FUN_00c8c290(&reader, &object);
    FUN_00c8c290(&second, &target);
    if (object && target && object->isKindOf(D_5829020) && target->isKindOf(D_5939080)) {
        Soldier002dab30 *soldier = static_cast<Soldier002dab30 *>(target);
        Owner00c57870 *owner = static_cast<Object002dab30 *>(object)->unknown28;
        if (owner) {
            if (Record002dab30 *record = FUN_00c57870(owner, D_57cb848, 0)) {
                Sensors002dab30 *sensors = record->sensors;
                for (unsigned i = 0; i < sensors->sensors.size(); ++i) {
                    if (sensors->sensors.at(i)->target == soldier) {
                        FUN_002da210(sensors, i);
                        break;
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}
