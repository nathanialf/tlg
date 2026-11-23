/* src/include/tlg_game_jsdepthstencilstate.h: the render's depth stencil
 * state (render/ps4/JsDepthStencilState.cpp, as CreateDepthStencilState's
 * message names the file). No string names the class; it is named for its
 * vtable row _ZTV14Object016d7f00 (0x16d7f00, D12). Its destructors are the
 * empty ones five classes share (0x14968f0 and 0x1496900): it declares
 * none, and the unit that constructs it emits them and the vtable. */
#ifndef TLG_GAME_JSDEPTHSTENCILSTATE_H
#define TLG_GAME_JSDEPTHSTENCILSTATE_H

#include "tlg_types.h"

#include "tlg_game_object0130acb0.h"

/* The state's source file, as the message names it (0x15cc34c). */
#define JS_DEPTH_STENCIL_STATE_CPP /* derived name */                                              \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsDepthStencilState.cpp"

/* derived names: the comparison functions (1 to 8) as the hardware's (0 to
 * 7), and the stencil operations (1 to 8) as the hardware's */
extern const int D_1525590[];
extern const int D_1525540[];

/* derived names: one face's stencil operations and test */
struct JsDepthStencilOpDesc {
    u32 StencilFailOp;      /* +0x0 */
    u32 StencilDepthFailOp; /* +0x4 */
    u32 StencilPassOp;      /* +0x8 */
    u32 StencilFunc;        /* +0xc */
};

/* derived names: the description (0x30 bytes, copied whole into the state) */
struct JsDepthStencilDesc {
    bool DepthEnable;               /* +0x0 */
    u32 DepthWriteMask;             /* +0x4 */
    u32 DepthFunc;                  /* +0x8 */
    bool StencilEnable;             /* +0xc */
    u8 StencilReadMask;             /* +0xd */
    u8 StencilWriteMask;            /* +0xe */
    JsDepthStencilOpDesc FrontFace; /* +0x10 */
    JsDepthStencilOpDesc BackFace;  /* +0x20 */
};

/* derived names: the depth stencil control word (+0x60) */
struct DepthStencilControl01304c20 {
    u32 m_reg;
    /* out of line (render_registers.cpp): the word built field by field in
     * the description's order (0x1304cdb on) */
    void setDepthControl(u32 zWrite, u32 zFunc);
    void setDepthEnable(bool enable);
    void setStencilEnable(bool enable);
    void setStencilFunction(u32 func);
    void setStencilFunctionBack(u32 func);
    void setSeparateStencilEnable(bool enable);
};

/* derived names: the stencil control bytes (+0x64) */
struct StencilControl01304c20 {
    u8 testVal;
    u8 mask;
    u8 writeMask;
    u8 opVal;
    void init(); /* render_registers.cpp */
};

/* derived names: the stencil operations word (+0x68): the front face's
 * fail, pass and depth fail operations from bit 0, the back face's from
 * bit 12 */
struct StencilOpControl01304c20 {
    u32 m_reg;
    /* out of line (render_registers.cpp): each face's three fields in the
     * order the setter's own unit ranks them */
    void init();
    void setStencilOps(u32 fail, u32 pass, u32 depthFail);
    void setStencilOpsBack(u32 fail, u32 pass, u32 depthFail);
};

/* derived name: the state's hardware words, zeroed together */
struct DepthStencilRegisters01304c20 {
    DepthStencilControl01304c20 depthControl; /* +0x0 */
    StencilControl01304c20 stencilControl;    /* +0x4 */
    StencilOpControl01304c20 stencilOps;      /* +0x8 */
};

class Object016d7f00 : public Object0130acb0 /* derived name */
{
  public:
    /* kind 9: the words zeroed; CreateDepthStencilState copies the
     * description in and builds the words from it */
    Object016d7f00() : Object0130acb0(9), m_registers() {}

    JsDepthStencilDesc m_desc;                 /* +0x30 */
    DepthStencilRegisters01304c20 m_registers; /* +0x60 */
};

#endif
