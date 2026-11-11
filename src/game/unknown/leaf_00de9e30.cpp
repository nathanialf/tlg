/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the "write" entry of the script binding table at 0x16bca10
 * (the file handle's methods, leaf_00de9a50.cpp's "flush" among them): writes
 * the arguments from the second on to the "FILE*" handle FUN_00dd3dd0 finds
 * for the state, through FUN_00de97e0 (the first argument it writes, then the
 * count of arguments, top - base; FUN_00de7d70 passes the count less one),
 * a tail call. */
struct FileHandle00de9a50; /* derived name */

FileHandle00de9a50 **FUN_00dd3dd0(lua_State *state, const char *type); /* derived name */
int FUN_00de97e0(lua_State *state, FileHandle00de9a50 *handle, int first,
                 int count); /* derived name */

extern const char D_15bc1f6[6]; /* "FILE*" */

int FUN_00de9e30(lua_State *state) /* derived name */
{
    FileHandle00de9a50 *handle = *FUN_00dd3dd0(state, D_15bc1f6);
    return FUN_00de97e0(state, handle, 2, state->top - state->base);
}
