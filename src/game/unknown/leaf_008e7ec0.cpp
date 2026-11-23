/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object016b0448.h"

void FUN_008ec8b0(Object016b0448 *object); /* derived name */
void FUN_008ec4e0(
    State0581f740 *state,
    const char *handler); /* derived name: the state's script handler of that name run */

/* derived names: the script C function named "MSC_UnRegisterStateAll" by its
 * parameter-count message (with arguments it formats that message into a
 * local buffer that nothing reads): FUN_008ec8b0 run over the object the
 * pointer at 0x581f740 holds, then, last first, each state whose ints at
 * +0x4, +0x8 and +0xc are all 0 given its "onLeave" (FUN_008ec4e0) and
 * removed; returns 0 (no results). The C function's own name is unknown. */
int FUN_008e7ec0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_UnRegisterStateAll", 0);
    }
    FUN_008ec8b0(D_581f740);
    for (int i = D_581f740->states.size(); i > 0; --i) {
        State0581f740 &entry = D_581f740->states.at(i - 1);
        if (entry.unknown4 == 0 && entry.unknown8 == 0 && entry.unknownc == 0) {
            FUN_008ec4e0(&entry, "onLeave");
            D_581f740->states.removeAt(i - 1);
        }
    }
    return 0;
}
