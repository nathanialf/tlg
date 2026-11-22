/* src/include/tlg_game_jscomputecontext.h: the render's compute context
 * (render/ps4/JsComputeContext.cpp, as its reports name the file). The class
 * name is its constructor's report (FUN_012ffc30, "JsComputeContext"); the
 * methods are named by their own reports, the constants and parameters by the
 * reports' conditions. Its vtable is at 0x16c3818 (no row in
 * config/vtables.base.txt), stored by FUN_012ffc30, FUN_013001f0 and
 * FUN_013002e0; the methods written here are declared without it, each with
 * its slot. */
#ifndef TLG_GAME_JSCOMPUTECONTEXT_H
#define TLG_GAME_JSCOMPUTECONTEXT_H

#include "tlg_types.h"

#include "tlg_game_jsrender.h"

/* The compute context's source file, as the reports name it (0x15cbea5). */
#define JS_COMPUTE_CONTEXT_CPP /* derived name */                                                  \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsComputeContext.cpp"

class JsComputeContext
{
  public:
    /* slot 10 (0x16c3840) */
    void CSSetConstantBuffers(u32 StartSlot, u32 NumBuffers, JsBuffer *const *ppConstantBuffers);
    /* slot 11 (0x16c3848) */
    void CSSetSamplers(u32 StartSlot, u32 NumSamplers, JsSamplerState *const *ppSamplers);
    /* slot 13 (0x16c3858) */
    void CSSetShaderResources(u32 StartSlot, u32 NumViews,
                              JsShaderResourceView *const *ppShaderResourceViews);
    /* slot 14 (0x16c3860) */
    void CSSetUnorderedAccessViews(u32 StartSlot, u32 NumUAVs,
                                   JsUnorderedAccessView *const *ppUnorderedAccessViews,
                                   const u32 *pUAVInitialCounts);
    /* a GPU label yielded on until it reads 0x10 (called directly) */
    static void StallUntilSignaled(volatile u64 *handle);
    /* slot 30 (0x16c3900): occlusion queries are not supported here; the
     * check fails unconditionally (JsComputeContext.cpp:754) */
    void BeginOcclusion();
    /* slot 31 (0x16c3908): likewise (JsComputeContext.cpp:761) */
    void EndOcclusion();

  private:
    u8 unknown0[0x1d18];
    /* derived names, each array from the method that fills it */
    JsShaderResourceView
        *m_shaderResources[JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT];           /* +0x1d18 */
    JsUnorderedAccessView *m_unorderedAccessViews[JS_PS_CS_UAV_REGISTER_COUNT];  /* +0x2118 */
    u32 m_initialCounts[JS_PS_CS_UAV_REGISTER_COUNT];                            /* +0x2158 */
    JsSamplerState *m_samplers[JS_COMMONSHADER_SAMPLER_SLOT_COUNT];              /* +0x2178 */
    JsBuffer *m_constantBuffers[JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT]; /* +0x21f8 */
};

#endif
