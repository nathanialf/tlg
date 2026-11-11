/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_libc.h"

/* derived names: the "flush" entry of the script binding table at 0x16bca10
 * ("close", "flush", "lines"): flushes the stream of the "FILE*" handle
 * FUN_00dd3dd0 finds for the state (all streams, fflush(0), without one), and
 * returns 0. The state's type is not traced. */
struct FileHandle00de9a50 { /* derived name */
    FILE *file;
};

struct State00de9a50; /* derived name */

FileHandle00de9a50 **FUN_00dd3dd0(State00de9a50 *state, const char *type); /* derived name */

int FUN_00de9a50(State00de9a50 *state) /* derived name */
{
    FileHandle00de9a50 *handle = *FUN_00dd3dd0(state, "FILE*");
    if (handle) {
        fflush(handle->file);
    } else {
        fflush(0);
    }
    return 0;
}
