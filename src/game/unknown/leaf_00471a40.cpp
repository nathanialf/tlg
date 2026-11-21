/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016a9ba8.h"

/* derived names: slot 11 of the base class, called directly by the
 * override; its class is not traced, so it is typed with the object it is
 * given */
void FUN_00a8e440(Object016a9ba8 *self); /* derived name */

/* derived names: nothing while bit 0 of +0x44c is set; else, with +0x30 set and +0x90
 * clear, the controller's state made active (the controller's +0x6c set to 1
 * first when the state's +0x30 or +0x40 is clear) and its slots 9 and 6
 * given the object; otherwise the state made inactive. Then the base class's
 * slot 11. */
void Object016a9ba8::slot11()
{
    if (flags44c & 1)
        return;
    if (unknown30 && !unknown90) {
        ControllerState00471a40 *state = controller->state;
        if (!state->unknown30 || !state->active)
            controller->unknown6c = 1;
        state->active = 1;
        controller->slot9(this);
        controller->slot6(this);
    } else {
        controller->state->active = 0;
    }
    FUN_00a8e440(this);
}
