/* src/include/tlg_game_jsdevicecontext.h: the render's device context
 * (render/ps4/JsDeviceContext.cpp). The class name is its constructor's report
 * (FUN_0130c660, "JsDeviceContext"); the methods written here are the
 * vtable's slots 5 to 9 (0x16c39c8, stored by FUN_0130c660 and FUN_0130dea0;
 * no row in config/vtables.base.txt), defined in JsDeviceContextInline.h as
 * their reports name it and declared here without the vtable.
 * DrawContext01314290 (tlg_game_drawcontext.h) holds the draws whose reports
 * name JsDeviceContext.cpp; whether it is this class is not traced. */
#ifndef TLG_GAME_JSDEVICECONTEXT_H
#define TLG_GAME_JSDEVICECONTEXT_H

#include "tlg_types.h"

#include "tlg_game_jsrender.h"

/* The inline header's path as JsDeviceContext.cpp includes it (0x15cc949);
 * other units include it by other paths (0xdf4890's "dev/../ps4/"). */
#define JS_DEVICE_CONTEXT_INLINE_H /* derived name */                                              \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4/JsDeviceContextInline.h"

class JsDeviceContext
{
  public:
    /* slot 5 (0x16c39f0) */
    void SetConstantBuffers(u32 StartSlot, u32 NumBuffers, JsBuffer *const *ppConstantBuffers);
    /* slot 6 (0x16c39f8) */
    void SetSamplers(u32 StartSlot, u32 NumSamplers, JsSamplerState *const *ppSamplers);
    /* slot 8 (0x16c3a08) */
    void SetShaderResources(u32 StartSlot, u32 NumViews,
                            JsShaderResourceView *const *ppShaderResourceViews);
    /* slot 9 (0x16c3a10) */
    void CSSetUnorderedAccessViews(u32 StartSlot, u32 NumUAVs,
                                   JsUnorderedAccessView *const *ppUnorderedAccessViews,
                                   const u32 *pUAVInitialCounts);

  private:
    u8 unknown0[0x500];
    /* derived names, each array from the method that fills it */
    JsBuffer *m_constantBuffers[JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT]; /* +0x500 */
    u8 unknown578[0x1980 - 0x578];
    JsShaderResourceView
        *m_shaderResources[JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT]; /* +0x1980 */
    u8 unknown1d80[0x2000 - 0x1d80];
    JsSamplerState *m_samplers[JS_COMMONSHADER_SAMPLER_SLOT_COUNT]; /* +0x2000 */
    u8 unknown2080[0x14];
    u32 m_dirtySamplers; /* +0x2094: a bit for each sampler slot changed */
    JsUnorderedAccessView *m_unorderedAccessViews[JS_PS_CS_UAV_REGISTER_COUNT]; /* +0x2098 */
    u32 m_initialCounts[JS_PS_CS_UAV_REGISTER_COUNT];                           /* +0x20d8 */
};

#endif
