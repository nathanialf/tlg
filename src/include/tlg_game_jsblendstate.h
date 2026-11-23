/* src/include/tlg_game_jsblendstate.h: the render's blend state
 * (render/ps4/JsBlendState.cpp, as CreateBlendState's messages name the
 * file). No string names the class; it is named for its vtable row
 * _ZTV14Object016d7ed8 (0x16d7ed8, config/vtables.derived.base.txt, D12).
 * Its destructors are the empty ones five classes share (0x14968f0 and
 * 0x1496900, in the stretch of inline functions): it declares none, and the
 * unit that constructs it emits them and the vtable. The description's
 * field names are its messages' (0x15cb8cd and on). */
#ifndef TLG_GAME_JSBLENDSTATE_H
#define TLG_GAME_JSBLENDSTATE_H

#include "tlg_types.h"

#include "tlg_game_object0130acb0.h"

/* The state's source file, as the messages name it (0x15cb891). */
#define JS_BLEND_STATE_CPP /* derived name */                                                      \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsBlendState.cpp"

/* derived names: the counts the description's values are checked against */
enum {
    JS_BLEND_COUNT = 19,
    JS_BLEND_OP_COUNT = 5,
    JS_COLOR_WRITE_ENABLE_COUNT = 16,
};

/* derived names: the blend factors (0 to 18) as the hardware's, and the
 * blend operations (0 to 4) as the hardware's */
extern const int D_15254d0[];
extern const int D_1525520[];

/* one render target's blend (0x20 bytes) */
struct JsRenderTargetBlendDesc {
    bool BlendEnable;         /* +0x0 (derived name) */
    u32 SrcBlend;             /* +0x4 */
    u32 DestBlend;            /* +0x8 */
    u32 BlendOp;              /* +0xc */
    u32 SrcBlendAlpha;        /* +0x10 */
    u32 DestBlendAlpha;       /* +0x14 */
    u32 BlendOpAlpha;         /* +0x18 */
    u8 RenderTargetWriteMask; /* +0x1c */
};

/* the description (0x104 bytes, copied whole into the state) */
struct JsBlendDesc {
    bool AlphaToCoverageEnable;              /* +0x0 (derived name) */
    bool IndependentBlendEnable;             /* +0x1 (derived name) */
    JsRenderTargetBlendDesc RenderTarget[8]; /* +0x4 */
};

/* derived names: a render target's blend control word: the colour's source
 * factor in bits 0 to 4, its operation in 5 to 7, its destination factor in
 * 8 to 12, the alpha's from bit 16, the separate alpha and enable bits 29
 * and 30 */
struct BlendControl012fed00 {
    u32 m_reg;

    /* out of line, as the rasterizer state's words (render_registers.cpp):
     * the base keeps each store a setter makes under the next one where a
     * read of the description comes between, and orders each equation's
     * fields as the setter's own unit ranks them */
    void init();
    void setBlendEnable(bool enable);
    void setSeparateAlphaEnable(bool enable);
    void setColorEquation(u32 src, u32 op, u32 dst);
    void setAlphaEquation(u32 src, u32 op, u32 dst);
};

/* derived names: the alpha to mask control word (+0x154): its enable in
 * bit 0 */
struct AlphaToMaskControl012fed00 {
    u32 m_reg;

    void init(); /* 0xaa00 */
    void setEnable(bool enable);
};

class Object016d7ed8 : public Object0130acb0 /* derived name */
{
  public:
    /* kind 8: the words initialized; CreateBlendState copies the
     * description in and builds the words from the copy */
    Object016d7ed8() : Object0130acb0(8)
    {
        m_alphaToMaskControl.init();
        m_renderTargetMask = 0;
        for (int i = 0; i < 8; i++)
            m_blendControl[i].init();
    }

    JsBlendDesc m_desc;                              /* +0x30 */
    BlendControl012fed00 m_blendControl[8];          /* +0x134 */
    AlphaToMaskControl012fed00 m_alphaToMaskControl; /* +0x154 */
    u32 m_renderTargetMask;                          /* +0x158 (derived name) */
};

#endif
