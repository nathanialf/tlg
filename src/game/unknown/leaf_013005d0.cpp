/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jscomputecontext.h"
#include "tlg_libc.h"

/* CSSetSamplers (the report's name for the function): the range checked,
 * then the samplers copied into the context's bindings. */
void JsComputeContext::CSSetSamplers(u32 StartSlot, u32 NumSamplers,
                                     JsSamplerState *const *ppSamplers)
{
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 88, StartSlot < JS_COMMONSHADER_SAMPLER_SLOT_COUNT);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 89,
                StartSlot + NumSamplers <= JS_COMMONSHADER_SAMPLER_SLOT_COUNT);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 90, ppSamplers != nullptr);
    memcpy(&m_samplers[StartSlot], ppSamplers, NumSamplers * sizeof(JsSamplerState *));
}
