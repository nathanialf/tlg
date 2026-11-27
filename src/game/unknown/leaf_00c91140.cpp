/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_property00e78f90.h"
#include "tlg_game_string01331840.h"
#include "tlg_hks.h"

/* derived names: a reader of one argument of the frame (as
 * leaf_003e7260.cpp's): the state, a null pointer, the argument as an index
 * from the top and two ints cleared. 0x20 bytes. */
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

/* derived names: reads the reader's argument as a Name into `name`: nil
 * empties it, a number is named by its "%g" text, a string is interned, and
 * a user value (full or light) holding an object handle gives the object's
 * own name. Any other type leaves the name as it is. 86 calls in 65
 * functions, each with a reader of its frame and a Name of its own (0x641e40).
 * The text is the function's (the frame keeps it apart from the string's
 * HashedString: 0x1020 bytes); the user value's cases tested light first */
void FUN_00c91140(ArgumentReader00c8c290 *reader, Name *name)
{
    String01331840 text;
    HksObject *value;
    if (indexToHksObjectUnchecked(reader->state, reader->index, &value))
        return;
    int type = value->type & 0xf;
    if (type == 9 || type == 10)
        type = 6;
    switch (type) {
    case 0:
        name->release();
        break;
    case 3: {
        lua_State *state = reader->state;
        float number = indexToHksObjectUnchecked(state, reader->index, &value)
                           ? 0
                           : FUN_00db6f40(state, value);
        FUN_01331840(&text, "%g", number);
        *name = Name(text);
        break;
    }
    case 4:
        *name = nameArgument(reader->state, reader->index);
        break;
    case 7: {
        if (indexToHksObjectUnchecked(reader->state, reader->index, &value))
            return;
        const PropertyHandle00c91760 *pair;
        switch (value->type & 0xf) {
        case 7:
            pair = reinterpret_cast<const PropertyHandle00c91760 *>(
                static_cast<HksUserdata *>(value->value.pointer) + 1);
            break;
        case 2:
            pair = static_cast<const PropertyHandle00c91760 *>(value->value.pointer);
            if (!pair)
                return;
            break;
        default:
            return;
        }
        *name = pair->object->name;
        break;
    }
    }
}
