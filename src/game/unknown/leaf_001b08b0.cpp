/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: a reader of the frame's arguments (leaf_002c4210.cpp's) */
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

/* derived names: the object's type as the function reads it: its flag at
 * +0x2c */
struct Kind001b08b0 { /* derived name */
    u8 unknown0[0x2c];
    u8 flags2c; /* +0x2c: bit 0 set for a type whose objects are not saved */
};

/* derived names: the object the first argument names: its flags at +0x16
 * (the root class's) and its type at +0x18 */
struct Object001b08b0 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16;        /* +0x16: bit 0 set for an object not saved */
    Kind001b08b0 *type; /* +0x18 */
};

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object001b08b0 **object); /* derived name */

/* derived names: the script C function "IsSerializable" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db178): reads its first
 * argument as an object through FUN_00c8c290; with one, pushes whether
 * neither the object nor its type has bit 0 of its flags set (false for an
 * object with no type) and returns 1; else returns 0. */
int FUN_001b08b0(lua_State *state) /* derived name */
{
    Object001b08b0 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (!object)
        return 0;
    pushBoolean(state, !(object->flags16 & 1) && object->type && !(object->type->flags2c & 1));
    return 1;
}
