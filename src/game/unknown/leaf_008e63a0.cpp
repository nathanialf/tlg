/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object016b0448.h"
void FUN_008db510(Object0581f4b8 *object); /* derived name */

/* derived names: the script C function named "MSC_SetFlagGameover" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's truth
 * (false without one) in flagGameover of the object the pointer at 0x581f740
 * holds and, when it is set, hands the object at +0x8 to FUN_008db510 (as
 * the script "ResetCheckList" does its own, leaf_008d5e20.cpp); returns 0 (no
 * results). The C function's own name is unknown. */
// NONMATCHING: instruction order: on the boolean's path the base reads the pointer at 0x581f740
// after `setne al; movzx ecx, al` (0x8e6430), this build before `setne` (list-ilp); the rest equal
int FUN_008e63a0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetFlagGameover", 1);
    }
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool gameover = false;
    if (type != 0) {
        gameover = true;
        if (type == 1)
            gameover = value->value.boolean != 0;
    }
    Object016b0448 *object = D_581f740;
    object->flagGameover = gameover;
    if (gameover)
        FUN_008db510(object->unknown8);
    return 0;
}
