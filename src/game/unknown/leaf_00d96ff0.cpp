/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"
#include "tlg_hks.h"

/* derived name: the length of a table (FUN_00db9aa0, its body not written) */
unsigned FUN_00db9aa0(HksTable *table);

/* derived name: Lua's lua_objlen by its arguments: the length of a number's
 * text, of a string, a table, a userdata's block (its size from bit 10 of
 * its head, less the head) or a structure's table, else 0; the call timed */
// NONMATCHING: the number's text: the base converts from memory after a vxorps (the recorded
// memory-form vcvtss2sd residual, docs/NOTES.md round 260A) and duplicates the exit's mark test into that
// case
size_t FUN_00d96ff0(lua_State *s, const HksObject *value)
{
    HksApiTimer timer(s);
    switch (value->type & 0xf) {
    case 3: {
        char text[256];
        return FUN_00d95b60(text, sizeof(text), "%0.8g", value->value.number);
    }
    case 4:
        return static_cast<int>(static_cast<HksString *>(value->value.pointer)->lengthAndFlags);
    case 5:
        return FUN_00db9aa0(value->value.table);
    case 7:
        return (static_cast<HksUserdata *>(value->value.pointer)->flags >> 10) -
               sizeof(HksUserdata);
    case 12: {
        HksTable *table = value->value.structure->table;
        return table ? FUN_00db9aa0(table) : 0;
    }
    default:
        return 0;
    }
}
