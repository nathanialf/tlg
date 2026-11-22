/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* derived name: stores its pointer argument at +0x130d0; slot 36
 * (leaf_01499f20.cpp) returns it. The pointer's target is not traced. */
void JsDeviceContext::setUnknown130d0(Target01499f10 *value)
{
    unknown130d0 = value;
}
