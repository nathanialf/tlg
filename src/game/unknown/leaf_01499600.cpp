/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jsdevicecontext.h"
#include "tlg_libc.h"

/* CSSetUnorderedAccessViews (the report's name for the function): the range
 * checked, then the views and, when passed, their initial counts copied into
 * the context's bindings. */
void JsDeviceContext::CSSetUnorderedAccessViews(
    u32 StartSlot, u32 NumUAVs, JsUnorderedAccessView *const *ppUnorderedAccessViews,
    const u32 *pUAVInitialCounts)
{
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 1184, StartSlot < JS_PS_CS_UAV_REGISTER_COUNT);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 1185, NumUAVs > 0);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 1186, ppUnorderedAccessViews != nullptr);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 1187,
                StartSlot + NumUAVs <= JS_PS_CS_UAV_REGISTER_COUNT);
    memcpy(&m_unorderedAccessViews[StartSlot], ppUnorderedAccessViews,
           NumUAVs * sizeof(JsUnorderedAccessView *));
    if (pUAVInitialCounts)
        memcpy(&m_initialCounts[StartSlot], pUAVInitialCounts, NumUAVs * sizeof(u32));
}
