/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function named "MSC_DumpState" by its
 * parameter-count message: with any argument it formats that message into a
 * local buffer that nothing reads, and returns 0 (no result); it does nothing
 * else. The C function's own name is unknown. */
int FUN_008e8010(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_DumpState", 0);
    }
    return 0;
}
