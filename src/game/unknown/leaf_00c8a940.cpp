/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: pushes a copy of an 8-byte value (two ints) as a block of 8
 * bytes FUN_00dba890 makes on the stack, then pushes the address 0x151e4ff
 * as a value of type 2 (a key: nothing at the address is read here), has
 * FUN_00db7fd0 look the key up in the table the state's global holds at
 * +0x1c8 (its type) and +0x1d0 and puts the result in the key's place,
 * type and value, by field; when the stack holds the block and the result above its base, FUN_00d971b0 joins them and
 * the result is popped. Four callers. The value's meaning is not traced. */
struct Value00c8a940 { /* derived name */
    int first;         /* +0x0 */
    int second;        /* +0x4 */
};

struct Global00c8a940 { /* derived name: the state's global, seen from here */
    u8 unknown0[0x1c8];
    int unknown1c8; /* +0x1c8: the table's type */
    u8 unknown1cc[4];
    void *unknown1d0; /* +0x1d0: the table */
};

extern const char D_151e4ff;

void *FUN_00dba890(lua_State *state, unsigned long size); /* derived name */
HksObject FUN_00db7fd0(lua_State *state, int type, void *table,
                       const HksObject *key);                             /* derived name */
void FUN_00d971b0(lua_State *state, HksObject *object, HksObject *table); /* derived name */

void FUN_00c8a940(lua_State *state, const Value00c8a940 *value) /* derived name */
{
    Value00c8a940 *copy = static_cast<Value00c8a940 *>(FUN_00dba890(state, sizeof(Value00c8a940)));
    copy->first = value->first;
    copy->second = value->second;
    HksObject *key = state->top;
    key->value.pointer = const_cast<char *>(&D_151e4ff);
    key->type = 2;
    state->top = key + 1;
    Global00c8a940 *global = reinterpret_cast<Global00c8a940 *>(state->global);
    HksObject result = FUN_00db7fd0(state, global->unknown1c8, global->unknown1d0, key);
    HksObject *slot = state->top - 1;
    slot->type = result.type;
    slot->value = result.value;
    if (state->top - 2 >= state->base) {
        FUN_00d971b0(state, state->top - 2, state->top - 1);
        state->top--;
    }
}
