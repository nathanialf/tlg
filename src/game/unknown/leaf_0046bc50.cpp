/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: a script C function (its address is not stored where a
 * table was found): reads its first argument as an object through
 * FUN_00c8c290 with a reader of the frame (as leaf_003e7260.cpp's); when the
 * object's class chain (+0x18, each class's parent at +0) reaches the class
 * the pointer at 0x57d4a68 holds and its int at +0x30 is not 0, takes the
 * pointer at +0x28 of the record two links down (+0x350, +0x50, +0x50, null
 * when the middle one is), and pushes it (or null) through FUN_00c89360;
 * returns 1. */
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

struct Class0046bc50 { /* derived name: a class record, its parent at +0 */
    const Class0046bc50 *parent;
};

struct Leaf0046bc50 { /* derived name */
    u8 unknown0[0x28];
    void *unknown28; /* +0x28 */
};

struct Link0046bc50 { /* derived name */
    u8 unknown0[0x50];
    Leaf0046bc50 *unknown50; /* +0x50 */
};

struct Middle0046bc50 { /* derived name */
    u8 unknown0[0x50];
    Link0046bc50 *unknown50; /* +0x50 */
};

struct Object0046bc50 { /* derived name */
    u8 unknown0[0x18];
    const Class0046bc50 *type; /* +0x18 */
    u8 unknown20[0x10];
    int unknown30; /* +0x30 */
    u8 unknown34[0x31c];
    Middle0046bc50 *unknown350; /* +0x350 */

    bool isKindOf(const Class0046bc50 *of) const
    {
        const Class0046bc50 *c = type;
        while (c != of) {
            c = c->parent;
            if (!c)
                return false;
        }
        return true;
    }
};

extern const Class0046bc50 *D_57d4a68; /* derived name: the class asked for */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object0046bc50 **object); /* derived name */
void FUN_00c89360(lua_State *state, void *value);                           /* derived name */

// NONMATCHING: the class walk as leaf_0048fd50.cpp's (the parked unrotated loop) and the reader's
// stores as leaf_003e7260.cpp's (list-ilp)
int FUN_0046bc50(lua_State *state) /* derived name */
{
    ArgumentReader00c8c290 reader(state);
    Object0046bc50 *object = 0;
    FUN_00c8c290(&reader, &object);
    void *value = 0;
    if (object && object->isKindOf(D_57d4a68) && object->unknown30 != 0) {
        Link0046bc50 *link = object->unknown350->unknown50;
        if (link)
            value = link->unknown50->unknown28;
    }
    FUN_00c89360(state, value);
    return 1;
}
