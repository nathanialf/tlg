/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jscomputecontext.h"

/* derived name: stores its pointer argument at +0x2318; slot 36
 * (leaf_01496ae0.cpp) returns it. The pointer's target is not traced. */
void JsComputeContext::setUnknown2318(Target01496ad0 *value)
{
    unknown2318 = value;
}
