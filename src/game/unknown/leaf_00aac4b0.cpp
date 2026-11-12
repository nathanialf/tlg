/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: a script C function: reads the first argument as an object
 * through FUN_00c8c290 with a reader of the frame (as leaf_001b0970.cpp's);
 * when it is one of the class the pointer at 0x582a300 holds (the walk up
 * the parents from its class at +0x18, as leaf_0046bc50.cpp's), pushes the
 * number 1 and returns bit 2 of the flags at +0xac as its count of results;
 * 0 otherwise. Five more differ only in the bit: FUN_00aac580 (3),
 * FUN_00aac650 (9), FUN_00aac720 (8), FUN_00aac7f0 (12), FUN_00aac8c0 (10). */
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

struct Class00aac4b0 {           /* derived name */
    const Class00aac4b0 *parent; /* +0x0 */
};

struct Object00aac4b0 { /* derived name */
    u8 unknown0[0x18];
    const Class00aac4b0 *type; /* +0x18 */
    u8 unknown20[0x8c];
    u32 unknownac; /* +0xac: flags */

    bool isKindOf(const Class00aac4b0 *of) const
    {
        const Class00aac4b0 *c = type;
        while (c != of) {
            c = c->parent;
            if (!c)
                return false;
        }
        return true;
    }
};

extern const Class00aac4b0 *D_582a300; /* derived name: the class asked for */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object00aac4b0 **object); /* derived name */

// NONMATCHING: the class walk as leaf_0048fd50.cpp's (the parked loop: the base tests the
// class before the loop and keeps the object in rcx, the build enters the loop at its test)
int FUN_00aac4b0(lua_State *state) /* derived name */
{
    Object00aac4b0 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_582a300)) {
        pushNumber(state, 1);
        return (object->unknownac >> 2) & 1;
    }
    return 0;
}
