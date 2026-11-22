/* src/include/tlg_game_jsdevicecontext.h: the render's device context
 * (render/ps4/JsDeviceContext.cpp). The class name is its constructor's report
 * (FUN_0130c660, "JsDeviceContext"); the methods written here are the
 * vtable's slots 5 to 9 (the row _ZTV15JsDeviceContext, 0x16c39b8,
 * config/vtables.derived.base.txt; stored by FUN_0130c660 and the
 * destructor 0x130dea0), defined in JsDeviceContextInline.h as their reports
 * name it. The destructor (leaf_0130dea0.cpp) runs Object0130acb0's.
 * DrawContext01314290 (tlg_game_drawcontext.h) holds the draws whose reports
 * name JsDeviceContext.cpp; whether it is this class is not traced. */
#ifndef TLG_GAME_JSDEVICECONTEXT_H
#define TLG_GAME_JSDEVICECONTEXT_H

#include "tlg_types.h"

#include "tlg_game_commandbuffer.h"
#include "tlg_game_jsrender.h"
#include "tlg_game_object0130acb0.h"

/* The inline header's path as JsDeviceContext.cpp includes it (0x15cc949);
 * other units include it by other paths (0xdf4890's "dev/../ps4/"). */
#define JS_DEVICE_CONTEXT_INLINE_H /* derived name */                                              \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4/JsDeviceContextInline.h"

/* derived name: the direct memory the destructor releases (0x20000 bytes
 * from this offset), then sets to 0 */
extern long D_5adaae0;

/* derived names: the targets slots 4, 12 and 13 forward to (their own
 * slots 3, 4 and 5), the pointers slots 7 and 35 store */
class Target01319850;
class Target01319870;
class Target01319890;
struct Target01499350;
struct Target01499f10;

class JsDeviceContext : public Object0130acb0
{
  public:
    /* slots 0 and 1 (0x130dea0, 0x130e020) */
    virtual ~JsDeviceContext();

    /* slot 4 (0x1319850): the target's slot 3 called with the context, a
     * null target skipped (leaf_01319850.cpp) */
    void Begin(Target01319850 *target); /* derived name */
    /* slot 5 (0x16c39f0) */
    void SetConstantBuffers(u32 StartSlot, u32 NumBuffers, JsBuffer *const *ppConstantBuffers);
    /* slot 6 (0x16c39f8) */
    void SetSamplers(u32 StartSlot, u32 NumSamplers, JsSamplerState *const *ppSamplers);
    /* slot 7 (0x1499350) */
    void setUnknown4670(Target01499350 *value); /* derived name */
    /* slot 8 (0x16c3a08) */
    void SetShaderResources(u32 StartSlot, u32 NumViews,
                            JsShaderResourceView *const *ppShaderResourceViews);
    /* slot 9 (0x16c3a10) */
    void CSSetUnorderedAccessViews(u32 StartSlot, u32 NumUAVs,
                                   JsUnorderedAccessView *const *ppUnorderedAccessViews,
                                   const u32 *pUAVInitialCounts);
    /* slot 12 (0x1319870): the target's slot 4 (leaf_01319870.cpp) */
    void End(Target01319870 *target); /* derived name */
    /* slot 13 (0x1319890): the target's slot 5, -2 without one */
    int GetData(Target01319890 *target, void *first, void *second, void *third); /* derived name */
    /* slot 16 (0x1319760): the view's count written to the buffer's base
     * address, by the CPU when the view has an initial count, else by a
     * copy packet from the counts; the buffer stamped. The offset is not
     * read. */
    void CopyStructureCount(JsBuffer *pDstBuffer, u32 DstAlignedByteOffset,
                            JsUnorderedAccessView *pSrcView); /* derived name */
    /* slot 18 (0x131b190): slot 19 (FUN_0131a010) with 0 inserted */
    void slot18(void *a, void *b, void *c, void *d, void *f); /* derived name */
    /* slot 20 (0x1499e00): every shader resource unbound */
    void clearShaderResources(); /* derived name */
    /* slot 21 (0x131b1c0): a label of the volatile memory set to 0x11, the
     * end-of-pipe event that writes 0x10 to it */
    u64 *writeEndOfPipeLabel(); /* derived name */
    /* slot 23 (0x131b330): the packet setting register 0x215 */
    void setRegister215(u32 low, u32 middle, u32 high); /* derived name */
    /* slot 25 (0x131b1b0): empty */
    void slot25(); /* derived name */
    /* slot 27 (0x1499360): the device's volatile memory allocated from, the
     * alignment from the table at 0x1525560 */
    u64 allocateVolatile(u32 size, unsigned alignment); /* derived name */
    /* slot 28 (0x131b3d0): the end-of-pipe event for the register 0x528
     * or 0x514 by the mode at +0x278 */
    void writeEvent(u64 address); /* derived name */
    /* slots 29 and 30 (0x131b4c0, 0x131b630): the counter address written
     * for the first and the second of the two counters, then the register
     * 1 */
    void slot29(u64 *counters); /* derived name */
    void slot30(u64 *counters); /* derived name */
    /* slot 32 (0x131b840): a three-dword type-3 packet, bit 0 of +0x47e8
     * cleared */
    void slot32(); /* derived name */
    /* slot 33 (0x1499e20): a push marker */
    void PushMarker(const char *marker); /* derived name */
    /* slot 34 (0x1499eb0): the marker closed */
    void PopMarker(); /* derived name */
    /* slots 35 and 36 (0x1499f10, 0x1499f20) */
    void setUnknown130d0(Target01499f10 *value); /* derived name */
    Target01499f10 *getUnknown130d0() const;     /* derived name */

  private:
    u8 unknown10[0x278 - 0x10];
    u32 mode; /* +0x278: 0x8000 picks the register 0x528 (slot 28) */
    u8 unknown27c[0x500 - 0x27c];
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
    u8 unknown20f8[0x4670 - 0x20f8];
    Target01499350 *unknown4670; /* +0x4670: stored by slot 7 */
    u8 unknown4678[0x4690 - 0x4678];
    /* derived names: references the destructor drops (+0x4698 first) */
    JsUnknown *unknown4690; /* +0x4690 */
    JsUnknown *unknown4698; /* +0x4698 */
    u8 unknown46a0[0x47ac - 0x46a0];
    u32 unknown47ac; /* +0x47ac: stored into the buffer by slot 16 */
    u8 unknown47b0[0x47c0 - 0x47b0];
    CommandBuffer01496a80 commands; /* +0x47c0 (derived name) */
    u8 unknown47e8;                 /* +0x47e8: bit 0 cleared by slot 32 */
    u8 unknown47e9[0x13090 - 0x47e9];
    /* derived names: entries the destructor hands back to the object
     * 0x5adaaa8 points at, +0x13098 and +0x130a0 to its list at +0x100b8,
     * the others to the one at +0x100e8 */
    void *entry13090; /* +0x13090 */
    void *entry13098; /* +0x13098 */
    void *entry130a0; /* +0x130a0 */
    void *entry130a8; /* +0x130a8 */
    void *entry130b0; /* +0x130b0 */
    /* +0x130b8: where the views' counts are, each a word at its slot
     * (slot 16) */
    u32 counterBase; /* derived name */
    u8 unknown130bc[0x130d0 - 0x130bc];
    Target01499f10 *unknown130d0; /* +0x130d0: stored by slot 35, returned by slot 36 */
};

#endif
