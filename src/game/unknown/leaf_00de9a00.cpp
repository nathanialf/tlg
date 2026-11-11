/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the "__gc" entry of the "FILE*" handle's metatable (the
 * binding table at 0x16bc9f0: "__tostring", "__gc", then "close" at
 * 0x16bca10, leaf_00de9a50.cpp's): for the box FUN_00dd3dd0 finds for the
 * state, when it holds a handle, a box of kind 2 gives the handle back
 * through the allocation function it carries (its user data, the handle,
 * its 0x18 bytes, new size 0: the script allocator's free); any other kind
 * closes it through the "close" entry FUN_00de9110. Returns 0. The kinds'
 * meaning is not traced. */
struct FileHandle00de9a50 /* derived name */
{
    FILE *file;                                                              /* +0x0 */
    void *(*allocate)(void *user, void *block, size_t size, size_t newSize); /* +0x8 */
    void *user;                                                              /* +0x10 */
};

struct FileBox00de9a00 /* derived name */
{
    FileHandle00de9a50 *handle; /* +0x0 */
    int kind;                   /* +0x8 */
};

FileBox00de9a00 *FUN_00dd3dd0(lua_State *state, const char *type); /* derived name */
int FUN_00de9110(lua_State *state);                                /* derived name */

extern const char D_15bc1f6[6]; /* "FILE*" */

int FUN_00de9a00(lua_State *state) /* derived name */
{
    FileBox00de9a00 *box = FUN_00dd3dd0(state, D_15bc1f6);
    if (FileHandle00de9a50 *handle = box->handle) {
        if (box->kind == 2) {
            handle->allocate(handle->user, handle, sizeof *handle, 0);
        } else {
            FUN_00de9110(state);
        }
    }
    return 0;
}
