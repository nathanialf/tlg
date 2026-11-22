/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jsdevicecontext.h"
#include "tlg_libc.h"

/* SetConstantBuffers (the report's name for the function): the range
 * checked, then the buffers copied into the context's bindings. */
void JsDeviceContext::SetConstantBuffers(u32 StartSlot, u32 NumBuffers,
                                         JsBuffer *const *ppConstantBuffers)
{
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 396, ppConstantBuffers != nullptr);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 397, NumBuffers > 0);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 398,
                StartSlot < JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 399,
                StartSlot + NumBuffers <= JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT);
    memcpy(&m_constantBuffers[StartSlot], ppConstantBuffers, NumBuffers * sizeof(JsBuffer *));
}
