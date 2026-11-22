/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jscomputecontext.h"
#include "tlg_libc.h"

/* CSSetConstantBuffers (the report's name for the function): the range
 * checked, then the buffers copied into the context's bindings. */
void JsComputeContext::CSSetConstantBuffers(u32 StartSlot, u32 NumBuffers,
                                            JsBuffer *const *ppConstantBuffers)
{
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 74,
                StartSlot < JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 75,
                StartSlot + NumBuffers <= JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT);
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 76, ppConstantBuffers != nullptr);
    memcpy(&m_constantBuffers[StartSlot], ppConstantBuffers, NumBuffers * sizeof(JsBuffer *));
}
