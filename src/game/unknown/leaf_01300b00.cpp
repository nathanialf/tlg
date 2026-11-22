/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jscomputecontext.h"
#include "tlg_libc.h"

/* CSSetUnorderedAccessViews (the report's name for the function): the range
 * checked, the views and their initial counts copied into the context's
 * bindings, and each view given its count (or -1 when none is passed). */
void JsComputeContext::CSSetUnorderedAccessViews(
    u32 StartSlot, u32 NumUAVs, JsUnorderedAccessView *const *ppUnorderedAccessViews,
    const u32 *pUAVInitialCounts)
{
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 134, StartSlot < JS_PS_CS_UAV_REGISTER_COUNT);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 135, NumUAVs > 0);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 136, ppUnorderedAccessViews != nullptr);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 137, StartSlot + NumUAVs <= JS_PS_CS_UAV_REGISTER_COUNT);
    memcpy(&m_unorderedAccessViews[StartSlot], ppUnorderedAccessViews,
           NumUAVs * sizeof(JsUnorderedAccessView *));
    if (pUAVInitialCounts) {
        memcpy(&m_initialCounts[StartSlot], pUAVInitialCounts, NumUAVs * sizeof(u32));
        for (u32 i = 0; i < NumUAVs; ++i) {
            if (ppUnorderedAccessViews[i])
                ppUnorderedAccessViews[i]->initialCount = pUAVInitialCounts[i];
        }
    } else {
        for (u32 i = 0; i < NumUAVs; ++i) {
            if (ppUnorderedAccessViews[i])
                ppUnorderedAccessViews[i]->initialCount = 0xffffffff;
        }
    }
}
