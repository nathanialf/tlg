/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script's "keys_array" userdata, whose registration
 * string says what it is: "keys_array() - userdata to input->keyRepeats".
 * The C function registered as "new_keys_array" (FUN_00c880f0, lea at
 * 0xc85850, through FUN_00c87e30) makes an 8-byte userdata (FUN_00dba890)
 * holding the address of the int array at +0x220 of the object the pointer
 * at 0x5938c40 holds, gives it the metatable registered under "keys_array"
 * (FUN_00dd4020, then FUN_00d971b0 joins the two and the table is popped)
 * and returns it. The metatable's one method, "__index" (FUN_00c87db0, the
 * library table at 0x16b89f0 that FUN_00ddc6b0 registers at 0xc8583f),
 * checks its first argument is such a userdata (FUN_00dd3dd0) and pushes the
 * entry the second argument's integer (FUN_00dbf960) selects as a number, 0
 * for a nil key. The array's extent is not traced. */
struct Object05938c40 { /* derived name */
    u8 unknown0[0x220];
    int keyRepeats[1]; /* +0x220; its extent not traced */
};

extern Object05938c40 *D_5938c40;

void *FUN_00dba890(lua_State *state, unsigned long size);                 /* derived name */
void FUN_00dd4020(lua_State *state, const char *name);                    /* derived name */
void FUN_00d971b0(lua_State *state, HksObject *object, HksObject *table); /* derived name */
void *FUN_00dd3dd0(lua_State *state, const char *type);                   /* derived name */
int FUN_00dbf960(lua_State *state, int argument);                         /* derived name */

/* derived name: whether an argument is nil (tag 0 in the low four bits);
 * one past the frame's top is not */
static inline bool isNil(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    return value < state->top && (value->type & 0xf) == 0;
}

int FUN_00c87db0(lua_State *state) /* derived name */
{
    int **keys = static_cast<int **>(FUN_00dd3dd0(state, "keys_array"));
    if (isNil(state, 2))
        pushInteger(state, 0);
    else
        pushInteger(state, (*keys)[FUN_00dbf960(state, 2)]);
    return 1;
}

int FUN_00c880f0(lua_State *state) /* derived name */
{
    int **keys = static_cast<int **>(FUN_00dba890(state, sizeof(int *)));
    *keys = D_5938c40->keyRepeats;
    FUN_00dd4020(state, "keys_array");
    if (state->top - 2 >= state->base) {
        FUN_00d971b0(state, state->top - 2, state->top - 1);
        state->top--;
    }
    return 1;
}
