/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stddef.h>

#include "tlg_types.h"

/* derived names: a reader of one byte at a time over a buffered source, the
 * callback FUN_00dccb8d's caller passes (lea at 0xdccb8d) to FUN_00dcdf60
 * beside the chunk name "HksReload" (the script VM's reload of a function):
 * sets the size it hands back to 1; when the buffer is used up, asks the
 * source's callback at +0x8 (with the state at +0x0, the source's argument at
 * +0x18 and the buffer's size at +0x38 to fill) for the next buffer, kept at
 * +0x30 with the position at +0x40 restarted, and reports "Error reading from
 * buffer" through FUN_00d9cfb0 (variadic, the state first) when there is
 * none; returns the byte's address and advances the position. Its first
 * argument (the state, passed by the caller) is not read. The types are not
 * traced. */
struct lua_State;

struct Source00dce910 { /* derived name */
    lua_State *unknown0;
    const char *(*unknown8)(lua_State *state, void *argument, size_t *size);
    u8 unknown10[8];
    void *unknown18;
    u8 unknown20[0x10];
    const char *unknown30; /* the buffer */
    size_t unknown38;      /* its size */
    size_t unknown40;      /* the position in it */
};

void FUN_00d9cfb0(lua_State *state, const char *format, ...); /* derived name */

// NONMATCHING: GVN's scalar PRE makes the buffer field's address a phi of two GEPs (r14 kept
// across the call, a push more) where the base reloads [rbx+0x30] after the merge
const char *FUN_00dce910(lua_State *, Source00dce910 *source, size_t *size) /* derived name */
{
    *size = 1;
    if (source->unknown40 == source->unknown38) {
        source->unknown30 =
            source->unknown8(source->unknown0, source->unknown18, &source->unknown38);
        source->unknown40 = 0;
        if (source->unknown30 == 0) {
            FUN_00d9cfb0(source->unknown0, "Error reading from buffer");
        }
    }
    return source->unknown30 + source->unknown40++;
}
