/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the box of a "FILE*" handle as FUN_00dd3dd0 finds it
 * (leaf_00de9a00.cpp's), its handle null once closed */
struct FileHandle00de9a50;

struct FileBox00de9a00 /* derived name */
{
    FileHandle00de9a50 *handle; /* +0x0 */
    int kind;                   /* +0x8 */
};

FileBox00de9a00 *FUN_00dd3dd0(lua_State *state, const char *type); /* derived name */

/* derived names: Lua's lua_pushfstring (FUN_00d97520) and the string object
 * of a text of known length and hash (FUN_00db9de0) */
const char *FUN_00d97520(lua_State *state, const char *format, ...);
void *FUN_00db9de0(lua_State *state, const char *text, size_t length, u32 hash);

extern const char D_15bc1f6[6]; /* "FILE*" */

/* derived name: the "__tostring" entry of the "FILE*" handle's metatable
 * (the table at 0x16bc9f0): "file (closed)" or "file (%p)" with the box */
int FUN_00de9960(lua_State *state)
{
    FileBox00de9a00 *box = FUN_00dd3dd0(state, D_15bc1f6);
    setTop(state, 0);
    if (box->handle) {
        FUN_00d97520(state, "file (%p)", box);
    } else {
        void *string = FUN_00db9de0(state, "file (closed)", 13, 0x377b9582);
        HksObject *top = state->top;
        top->type = 4;
        top->value.pointer = string;
        state->top = top + 1;
    }
    return 1;
}
