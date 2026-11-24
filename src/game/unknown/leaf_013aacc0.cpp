/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* pushes a string of a given length: the VM's string for the text and its
 * hash, tag 4 (string) on the stack's top */
void FUN_013aacc0(lua_State *state, const char *string, size_t length)
{
    void *made = FUN_00db9de0(state, string, length, hashString(string, length));
    HksObject *top = state->top;
    top->type = 4;
    top->value.pointer = made;
    state->top = top + 1;
}
