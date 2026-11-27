/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"
#include "tlg_hks_string.h"

/* derived name: Lua's lua_tolstring by its value (luaV_tostring folded
 * in): a number formatted "%0.8g" (0x15c1086), made a string of the VM's
 * table with its hash inline and stored in the value's slot in its place;
 * a string's text, and its length when asked; else null and the length 0.
 * The call timed. The number's case is written first: the base tests the
 * string's tag (4) before it (SelectionDAGBuilder's small-switch order) */
// NONMATCHING: the number's float-to-double conversion from memory (round 578E's class: the build
// loads it, then converts the register), and the length pointer's spill: the base stores r12 at the
// tag-3 test (rbp-0x138) and reloads it into r12 on the other path and after FUN_00dd06f0; the build
// stores it in the number's block (rbp-0x148), keeps r12 on the other path and reloads it into rax.
// Under cvtzero-01 (e578/sc/vB, whole module) only the spill differs.
const char *FUN_00db6b20(lua_State *state, HksObject *value, size_t *length)
{
    HksApiTimer timer(state);
    switch (value->type & 0xf) {
    case 3: {
        char text[256];
        const size_t size = FUN_00d95b60(text, sizeof(text), "%0.8g", value->value.number);
        HksString *string = static_cast<HksString *>(
            FUN_00dd06f0(state->global->strings, state, 0, text, size, hashString(text, size)));
        if (length)
            *length = string->length();
        value->value.pointer = string;
        value->type = 4;
        return string->data;
    }
    case 4: {
        HksString *string = static_cast<HksString *>(value->value.pointer);
        if (length)
            *length = string->length();
        return string->data;
    }
    default:
        if (length)
            *length = 0;
        return 0;
    }
}
