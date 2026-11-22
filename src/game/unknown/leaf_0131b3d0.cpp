/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* derived name: the event packet for the register 0x528 when the mode at
 * +0x278 is 0x8000, else for 0x514 */
void JsDeviceContext::writeEvent(u64 address)
{
    if (mode == 0x8000)
        commands.writeEvent(0x528, address);
    else
        commands.writeEvent(0x514, address);
}
