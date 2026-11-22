/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jsdevicecontext.h"
#include "tlg_libc.h"

/* SetShaderResources (the report's name for the function): the range
 * checked, then the views copied into the context's bindings. */
void JsDeviceContext::SetShaderResources(u32 StartSlot, u32 NumViews,
                                         JsShaderResourceView *const *ppShaderResourceViews)
{
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 658,
                StartSlot < JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 659,
                StartSlot + NumViews <= JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 660, ppShaderResourceViews != nullptr);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 661, NumViews > 0);
    memcpy(&m_shaderResources[StartSlot], ppShaderResourceViews,
           NumViews * sizeof(JsShaderResourceView *));
}
