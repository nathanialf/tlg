/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jscomputecontext.h"
#include "tlg_libc.h"

/* CSSetShaderResources (the report's name for the function): the range
 * checked against the context's slots and the constant update engine's,
 * then the views stored one by one. */
void JsComputeContext::CSSetShaderResources(u32 StartSlot, u32 NumViews,
                                            JsShaderResourceView *const *ppShaderResourceViews)
{
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 114, StartSlot < JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 115,
                StartSlot + NumViews <= JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 116, ppShaderResourceViews != nullptr);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 117, NumViews > 0);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 118,
                StartSlot + NumViews <=
                    sce::Gnmx::LightweightConstantUpdateEngine::kMaxResourceCount);
    for (u32 i = 0; i < NumViews; ++i)
        m_shaderResources[StartSlot + i] = ppShaderResourceViews[i];
}
