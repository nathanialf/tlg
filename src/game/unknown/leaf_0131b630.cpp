/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* derived name: the second counter's address written, then the register 1
 * set to 0x11000100 */
void JsDeviceContext::slot30(u64 *counters)
{
    commands.writeCounterAddress(counters, 1);
    commands.setRegister1(0x11000100);
}
