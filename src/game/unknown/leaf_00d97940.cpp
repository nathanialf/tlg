/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stddef.h>

#include "tlg_types.h"

/* derived names: a block read of the script loader (its message "%s: %s in
 * precompiled chunk", as Lua's lundump.c): FUN_013bd670 reads the block, and
 * when the int at +0x34 is set (the chunk's byte order differs) each element
 * of the size (1, 2, 4 or 8: the jump table 0x1559d28 over 1 to 8) has its
 * bytes reversed; any other size pushes "bad size" with FUN_00d96630 (as
 * luaO_pushfstring, with the state at +0x0 and the chunk's name at +0x70 of
 * the stream) and gives 0. Returns 0 when the read fails, else 1. The
 * stream's and the reader's other fields are not traced. */
struct State00d97940; /* derived name */

struct Stream00d97940 {   /* derived name */
    State00d97940 *state; /* +0x0 */
    u8 unknown8[0x68];
    const char *name; /* +0x70 */
};

struct Reader00d97940 {     /* derived name */
    Stream00d97940 *stream; /* +0x0 */
    u8 unknown8[0x2c];
    int swap; /* +0x34 */
};

int FUN_013bd670(Reader00d97940 *self, u8 *data, size_t bytes);   /* derived name */
void FUN_00d96630(State00d97940 *state, const char *format, ...); /* derived name */

int FUN_00d97940(Reader00d97940 *self, u8 *data, size_t bytes, size_t size) /* derived name */
{
    if (!FUN_013bd670(self, data, bytes))
        return 0;
    if (!self->swap)
        return 1;
    switch (size) {
    case 1:
        break;
    case 2:
        for (u8 *p = data; bytes != 0; bytes -= 2, p += 2) {
            u8 t = p[0];
            p[0] = p[1];
            p[1] = t;
        }
        break;
    case 4:
        for (u8 *p = data; bytes != 0; bytes -= 4, p += 4) {
            u8 t = p[0];
            p[0] = p[3];
            p[3] = t;
            t = p[1];
            p[1] = p[2];
            p[2] = t;
        }
        break;
    case 8:
        for (u8 *p = data; bytes != 0; bytes -= 8, p += 8) {
            u8 t = p[0];
            p[0] = p[7];
            p[7] = t;
            t = p[1];
            p[1] = p[6];
            p[6] = t;
            t = p[2];
            p[2] = p[5];
            p[5] = t;
            t = p[3];
            p[3] = p[4];
            p[4] = t;
        }
        break;
    default:
        FUN_00d96630(self->stream->state, "%s: %s in precompiled chunk", self->stream->name,
                     "bad size");
        return 0;
    }
    return 1;
}
