/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_array.h"
#include "tlg_game_string01342e50.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (leaf_00b10e30.cpp's and leaf_00301db0.cpp's;
 * type 2 a string, 3 an int) */
struct ScriptArgument00a2efa0 {
    void set(int type_, int value_) /* derived name */
    {
        type = type_;
        value.integer = value_;
    }

    void set(int type_, const char *string) /* derived name */
    {
        type = type_;
        value.string = string;
    }

    int type;
    u8 unknown4[4];

    union {
        int integer;
        const char *string;
    } value;
};

/* calls the script function its name gives with count arguments, its int
 * result through the last pointer; nonzero on success (FUN_00b10da0). */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: an entry of the list the pointer at 0x581bd00 holds: its
 * state at +0x24, its name at +0x2c, two arrays of the names of objects at
 * +0x50 and +0x80 (FUN_0082f340 walks them), an array of a value for each
 * name of the first at +0x68, an int at +0xfc and at +0x118
 * the object it belongs to */
struct Region0082f550 { /* derived name */
    u8 unknown0[0x24];
    /* +0x24: the state (3 connected, the callback's test); volatile: the
     * region functions' reads compared with a nonzero constant are never
     * folded into the compare (`mov eax, [r+0x24]; cmp eax, 3` at 0x82e319,
     * 0x82ec5d, 0x82ef6a, 0x82f0af, 0x82f371 and here, eleven such reads
     * from 0x82e319 to 0x82f56c); stores at 0x82e3bc and 0x82e5c8 */
    volatile int unknown24;
    u8 unknown28[0x4];
    Name name; /* +0x2c */
    u8 unknown30[0x20];
    Array05943280<Name> names50; /* +0x50 */
    Array05943280<int> values68; /* +0x68: one for each name at +0x50 */
    Array05943280<Name> names80; /* +0x80 */
    u8 unknown98[0x64];
    int unknownfc; /* +0xfc: cleared by FUN_0082f340 */
    u8 unknown100[0x18];
    Object016b9108 *unknown118; /* +0x118 */
};

/* derived names: a callback FUN_00202800 hands FUN_00cb8490 for each entry
 * of the list the pointer at 0x581bd00 holds (lea at 0x202f17, the context
 * null): an entry in state 3 calls the script function
 * "RegionSetting.<its name>.OnConnect" with the int 1, the name of the
 * object at +0x118 and its own name; returns 1 */
int FUN_0082f550(Region0082f550 *region, void *) /* derived name */
{
    if (region->unknown24 == 3) {
        ScriptArgument00a2efa0 arguments[3];
        arguments[0].set(3, 1);
        arguments[1].set(2, D_17ac870[region->unknown118->name.index].string0);
        arguments[2].set(2, D_17ac870[region->name.index].string0);
        String01342e50 function;
        function.format("RegionSetting.%s.OnConnect", D_17ac870[region->name.index].string0);
        FUN_00a2efa0(function.text, 3, arguments, 0);
    }
    return 1;
}

/* derived names: the objects the region's lists name: of the type the
 * pointer at 0x5939080 holds, with a flag at +0x24 (bit 0 tested by
 * FUN_0082f340); not traced further */
class Object0082f340 : public Object016b9108 /* derived name */
{
  public:
    int unknown24; /* +0x24 */
};

extern Type00503fb0 *D_5939080; /* derived name: the objects' type */

/* the object a name names when this thread may use it and it is of that
 * type, else null */
static Object0082f340 *regionObject(const Name &name) /* derived name */
{
    Object0082f340 *object = static_cast<Object0082f340 *>(D_17ac870[name.index].record18);
    if (object && ((object->flags16 & 4) || threadMayUse()) && object->isKindOf(D_5939080))
        return object;
    return 0;
}

int FUN_0082abe0(Object0082f340 *object, int *value);                        /* derived name */
void FUN_00c55dd0(Object0082f340 *object, Object016b9108 *owner, int flags); /* derived name */
void FUN_00c57220(Object0082f340 *object);                                   /* derived name */

/* derived names: the callback FUN_00202800 hands FUN_00cb8490 next to
 * FUN_0082f550 (lea at 0x202f2b): the int at +0xfc cleared; an entry in
 * state 3 calls the script function "RegionSetting.<its name>.OnDisconnect"
 * with no argument, hands each object of its first list whose flag at
 * +0x24 is clear and that FUN_0082abe0 accepts with its value to
 * FUN_00c55dd0 with the entry's object, and each object of its second list
 * to FUN_00c57220; returns 1.
 * NONMATCHING: the stack guard's address: the base holds it in r12 from the
 * entry and loads it again into r12 between the two loops (live across the
 * second), the build loads it at the entry and again in the return block;
 * the rest is the base's (greedy's split of the guard's live range). */
int FUN_0082f340(Region0082f550 *region, void *) /* derived name */
{
    region->unknownfc = 0;
    if (region->unknown24 == 3) {
        String01342e50 function;
        function.format("RegionSetting.%s.OnDisconnect", D_17ac870[region->name.index].string0);
        FUN_00a2efa0(function.text, 0, 0, 0);
        const unsigned count = region->names50.size();
        for (unsigned i = 0; i < count; ++i) {
            Object0082f340 *object = regionObject(region->names50.at(i));
            if (object && !(object->unknown24 & 1) && FUN_0082abe0(object, &region->values68.at(i)))
                FUN_00c55dd0(object, region->unknown118, 0);
        }
        const unsigned count2 = region->names80.size();
        for (unsigned i = 0; i < count2; ++i) {
            if (Object0082f340 *object = regionObject(region->names80.at(i)))
                FUN_00c57220(object);
        }
    }
    return 1;
}
