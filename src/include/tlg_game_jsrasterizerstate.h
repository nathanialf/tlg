/* src/include/tlg_game_jsrasterizerstate.h: the render's rasterizer state
 * (render/ps4/JsRasterizerState.cpp, as CreateRasterizerState's report names
 * the file). No string names the class; it is named for its vtable row
 * _ZTV14Object016d7fd0 (0x16d7fd0, config/vtables.derived.base.txt, D12).
 * Its destructors are the empty ones five classes share (0x14968f0 and
 * 0x1496900, in the stretch of inline functions): it declares none, and the
 * unit that constructs it emits them and the vtable.
 * The description's fields follow the hardware words the constructor
 * builds from them. */
#ifndef TLG_GAME_JSRASTERIZERSTATE_H
#define TLG_GAME_JSRASTERIZERSTATE_H

#include "tlg_types.h"

#include "tlg_game_object0130acb0.h"

/* The state's source file, as the report names it (0x15cda76). */
#define JS_RASTERIZER_STATE_CPP /* derived name */                                                 \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsRasterizerState.cpp"

/* derived names: the fill and cull modes the constructor tells apart */
enum JsFillMode {
    JS_FILL_WIREFRAME = 2,
    JS_FILL_SOLID = 3,
};

enum JsCullMode {
    JS_CULL_NONE = 1,
    JS_CULL_FRONT = 2,
    JS_CULL_BACK = 3,
};

/* derived names: the description (0x1c bytes, copied whole into the state) */
struct JsRasterizerDesc {
    u32 FillMode;               /* +0x0 */
    u32 CullMode;               /* +0x4 */
    bool FrontCounterClockwise; /* +0x8 */
    int DepthBias;              /* +0xc */
    float DepthBiasClamp;       /* +0x10 */
    float SlopeScaledDepthBias; /* +0x14 */
    bool DepthClipEnable;       /* +0x18 */
    bool ScissorEnable;         /* +0x19 */
    bool MultisampleEnable;     /* +0x1a */
    bool AntialiasedLineEnable; /* +0x1b */
};

/* derived names: the primitive setup word (+0x4c): the cull face in bits 0
 * and 1, the front face in bit 2, the polygon mode from bit 3.
 *
 * Its init() and the clip control's are out of line in a unit of their own
 * (render_registers.cpp), which the link inlines: the base keeps each init
 * store under the store that follows it (0x131f592 under 0x131f5a0, 0x131f5e6
 * under 0x131f5fd). The unit's pipeline cannot form those selects before its
 * dead store pass runs with no store to speculate from (a call there); the
 * link's runs dead store elimination while the arms are still branches and
 * speculates the arm's store into a select only in its last CFG pass. Inline
 * here, the unit forms the select first and the init store dies. */
struct PrimitiveSetup0131f450 {
    u32 m_reg;

    enum PolygonMode { kPolygonModeLine = 1, kPolygonModeFill = 2 };

    void init(); /* the polygon modes filled (0x240) */

    void setPolygonMode(PolygonMode front, PolygonMode back)
    {
        u32 enable = front != kPolygonModeFill || back != kPolygonModeFill;
        m_reg = (m_reg & ~0x7e8u) | enable << 3 | front << 5 | back << 8;
    }

    void setFrontFace(bool clockwise)
    {
        m_reg = (m_reg & ~4u) | (u32)clockwise << 2;
    }

    void setCullFace(u32 face)
    {
        m_reg = (m_reg & ~3u) | face;
    }
};

/* derived names: the clip control word (+0x50) */
struct ClipControl0131f450 {
    u32 m_reg;

    void init(); /* 0x80000 */

    /* derived name: the clip space bits set */
    void setClipDisable()
    {
        m_reg |= 0xc000000u;
    }
};

class Object016d7fd0 : public Object0130acb0 /* derived name */
{
  public:
    /* kind 7 */
    explicit Object016d7fd0(const JsRasterizerDesc &desc) : Object0130acb0(7), m_desc(desc)
    {
        m_primitiveSetup.init();
        if (m_desc.FillMode == JS_FILL_WIREFRAME)
            m_primitiveSetup.setPolygonMode(PrimitiveSetup0131f450::kPolygonModeLine,
                                            PrimitiveSetup0131f450::kPolygonModeLine);
        m_primitiveSetup.setFrontFace(!m_desc.FrontCounterClockwise);
        switch (m_desc.CullMode) {
        case JS_CULL_NONE:
            m_primitiveSetup.setCullFace(0);
            break;
        case JS_CULL_FRONT:
            m_primitiveSetup.setCullFace(1);
            break;
        case JS_CULL_BACK:
            m_primitiveSetup.setCullFace(2);
            break;
        }
        m_clipControl.init();
        if (!m_desc.DepthClipEnable)
            m_clipControl.setClipDisable();
    }

  private:
    JsRasterizerDesc m_desc;                 /* +0x30 */
    PrimitiveSetup0131f450 m_primitiveSetup; /* +0x4c */
    ClipControl0131f450 m_clipControl;       /* +0x50 */
};

#endif
