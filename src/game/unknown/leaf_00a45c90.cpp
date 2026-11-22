/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_hks.h"

/* derived names: the script C function "Sound_ReleaseCSV" (its usage
 * "Sound_ReleaseCSV()"; FUN_00a44ab0's registration through FUN_00c87e30, lea
 * at 0xa44c15): empties the list of strings Sound_GetCSV (FUN_00a45c20) reads
 * from the object the pointer at 0x5827b50 holds and gives its block back,
 * releases the text at +0x5b90 the strings point into, clears it, the cursor
 * into it, the position and the size, then pushes true and returns 1. The types are not traced
 * beyond these fields. */
struct Object05827b50 { /* derived name */
    u8 unknown0[0x5b90];
    char *text;    /* +0x5b90: the file's bytes (Sound_LoadCSV, FUN_00a45980) */
    char *cursor;  /* +0x5b98: where the next line is cut from */
    int position;  /* +0x5ba0: Sound_GetCSV's */
    unsigned size; /* +0x5ba4: the file's size */
    Array05943280<const char *> strings; /* +0x5ba8 */
};

extern Object05827b50 *D_5827b50;

int FUN_00a45c90(lua_State *state) /* derived name */
{
    Object05827b50 *list = D_5827b50;
    list->strings.clear();
    releaseBlock(list->text);
    list->text = 0;
    list->cursor = 0;
    list->position = 0;
    list->size = 0;
    pushBoolean(state, true);
    return 1;
}
