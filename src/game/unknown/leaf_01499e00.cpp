/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"
#include "tlg_libc.h"

/* derived name: every shader resource binding (the 0x400 bytes at +0x1980)
 * cleared with memset, as a tail call. */
void JsDeviceContext::clearShaderResources()
{
    memset(m_shaderResources, 0, sizeof(m_shaderResources));
}
