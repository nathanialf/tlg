/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: a script C function (its address is not stored where a
 * table was found): with at least two arguments, reads the first as an
 * object through FUN_00c8c290 with a reader of the frame (as
 * leaf_003e7260.cpp's) and sets bit 0 of the object's flags at +0x16 to the
 * opposite of the second argument's truth (false for nil, a boolean's value,
 * true for any other type; false past the frame, as leaf_00e7cff0.cpp's
 * argumentTruth); returns 0. */
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

struct Object001b0970 { /* derived name */
    u8 unknown0[0x16];
    u16 unknown16bit0 : 1; /* +0x16 bit 0 */
};

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object001b0970 **object); /* derived name */

/* derived name: as leaf_00e7cff0.cpp's */
static inline bool argumentTruth(const HksObject &argument, const HksObject *top)
{
    const HksObject *value = &argument < top ? &argument : 0;
    if (value) {
        int type = value->type & 0xf;
        if (type == 0)
            return false;
        if (type == 1)
            return value->value.boolean != 0;
        return true;
    }
    return false;
}

// NONMATCHING: the bit store: the base keeps the 16-bit word (`movzx edx, word; and 0xfffe; or;
// xor 1; mov word`) and the truth as `setne`, the build narrows it to the byte and folds the
// negation into `sete`; registers of the truth exchanged (greedy)
int FUN_001b0970(lua_State *state) /* derived name */
{
    int count = (unsigned long)((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count < 2)
        return 0;
    ArgumentReader00c8c290 reader(state);
    Object001b0970 *object = 0;
    FUN_00c8c290(&reader, &object);
    if (!object)
        return 0;
    object->unknown16bit0 = !argumentTruth(state->base[1], state->top);
    return 0;
}
