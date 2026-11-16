/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "CharacterUpdateProxyEventSubscribe"
 * ("update the character proxy event subscribe"; FUN_001c4670's
 * registration, lea at 0x1c4707): reads its first argument as an object
 * through FUN_00c8c290 with a reader of the frame (as leaf_0046bc50.cpp's)
 * and, when it is of the type D_5814e08 points to (or one derived from it),
 * hands it to FUN_00712b60; returns 0 (no results). The C function's own
 * name is unknown. */
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

class Character007d8be0 : public Object016b9108 /* derived name; not traced */
{
};

extern Type00503fb0 *D_5814e08; /* derived name: the character's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00712b60(Character007d8be0 *character);                            /* derived name */

// NONMATCHING: the second type walk (the cast's): the base enters it past the type itself, the
// type's own compare threaded away, and keeps "not found" in dl (`mov dl, 1` in the loop, `cmovne
// rdi, 0`); this build compares the type again at 0x7f and keeps "found" in cl (`cmovne rdi, rax`);
// 19/59 equal. Byte-identical copies: 0xa08af0, 0xcf2930, 0xcf29f0 (RBSnooper_Suspend, _Resume).
int FUN_007d8be0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5814e08))
        FUN_00712b60(object->isKindOf(D_5814e08) ? static_cast<Character007d8be0 *>(object) : 0);
    return 0;
}
