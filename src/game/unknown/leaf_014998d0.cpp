/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jsdevicecontext.h"
#include "tlg_libc.h"

/* SetSamplers (the report's name for the function): the range checked, then
 * each sampler that changes stored and its slot's bit set. */
void JsDeviceContext::SetSamplers(u32 StartSlot, u32 NumSamplers, JsSamplerState *const *ppSamplers)
{
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 480, StartSlot < JS_COMMONSHADER_SAMPLER_SLOT_COUNT);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 481,
                StartSlot + NumSamplers <= JS_COMMONSHADER_SAMPLER_SLOT_COUNT);
    ANZU_ASSERT(JS_DEVICE_CONTEXT_INLINE_H, 482, ppSamplers != nullptr);
    for (u32 i = 0; i < NumSamplers; ++i) {
        u32 slot = StartSlot + i;
        if (m_samplers[slot] != ppSamplers[i]) {
            m_samplers[slot] = ppSamplers[i];
            m_dirtySamplers |= 1 << slot;
        }
    }
}
