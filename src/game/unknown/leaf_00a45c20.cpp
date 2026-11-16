/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* derived names: the script C function "Sound_GetCSV" (its usage
 * "Sound_GetCSV()"; FUN_00a44ab0's registration through FUN_00c87e30, lea at
 * 0xa44bf0): pushes the next string of the list the object the pointer at
 * 0x5827b50 holds (the strings at +0x5ba8, their count at +0x5bb0, the
 * position at +0x5ba0, advanced), nil past the end or for a null string, and
 * returns 1 (one result), through pushString (tlg_hks_string.h). The types
 * are not traced beyond these fields. */
struct Object05827b50 { /* derived name */
    u8 unknown0[0x5ba0];
    int unknown5ba0; /* +0x5ba0: the position */
    u8 unknown5ba4[4];
    const char **unknown5ba8; /* +0x5ba8: the strings */
    unsigned unknown5bb0;     /* +0x5bb0: their count */
};

extern Object05827b50 *D_5827b50;

int FUN_00a45c20(lua_State *state) /* derived name */
{
    Object05827b50 *list = D_5827b50;
    const char *string = 0;
    if (unsigned(list->unknown5ba0) < list->unknown5bb0) {
        string = list->unknown5ba8[list->unknown5ba0++];
    }
    pushString(state, string);
    return 1;
}
