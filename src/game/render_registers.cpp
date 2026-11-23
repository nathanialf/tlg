/* src/game/render_registers.cpp: the hardware words' init, out of line. They
 * have no address of their own in the base: the link inlines them at each
 * caller (CreateRasterizerState, 0x131f450), where their stores stay under
 * the stores that follow (tlg_game_jsrasterizerstate.h). */
#include "tlg_types.h"

#include "tlg_game_jsblendstate.h"
#include "tlg_game_jsdepthstencilstate.h"
#include "tlg_game_jsrasterizerstate.h"

void PrimitiveSetup0131f450::init()
{
    m_reg = kPolygonModeFill << 5 | kPolygonModeFill << 8;
}

void ClipControl0131f450::init()
{
    m_reg = 0x80000;
}

void BlendControl012fed00::init()
{
    m_reg = 0;
}

void BlendControl012fed00::setBlendEnable(bool enable)
{
    m_reg = (m_reg & ~0x40000000u) | (u32)enable << 30;
}

void BlendControl012fed00::setSeparateAlphaEnable(bool enable)
{
    m_reg = (m_reg & ~0x20000000u) | (u32)enable << 29;
}

void BlendControl012fed00::setColorEquation(u32 src, u32 op, u32 dst)
{
    m_reg = (m_reg & ~0x1fffu) | (src & 0x1f) | (op & 7) << 5 | (dst & 0x1f) << 8;
}

void BlendControl012fed00::setAlphaEquation(u32 src, u32 op, u32 dst)
{
    m_reg = (m_reg & ~0x1fff0000u) | (src & 0x1f) << 16 | (op & 7) << 21 | (dst & 0x1f) << 24;
}

void AlphaToMaskControl012fed00::init()
{
    m_reg = 0xaa00;
}

void AlphaToMaskControl012fed00::setEnable(bool enable)
{
    m_reg = (m_reg & ~1u) | (u32)enable;
}

void StencilControl01304c20::init()
{
    testVal = 0;
    mask = 0;
    writeMask = 0;
    opVal = 0;
}

void StencilOpControl01304c20::init()
{
    m_reg = 0;
}

void StencilOpControl01304c20::setStencilOps(u32 fail, u32 pass, u32 depthFail)
{
    m_reg = (m_reg & ~0xfffu) | (fail & 0xf) | (pass & 0xf) << 4 | (depthFail & 0xf) << 8;
}

void StencilOpControl01304c20::setStencilOpsBack(u32 fail, u32 pass, u32 depthFail)
{
    m_reg =
        (m_reg & ~0xfff000u) | (fail & 0xf) << 12 | (pass & 0xf) << 16 | (depthFail & 0xf) << 20;
}

void DepthStencilControl01304c20::setDepthControl(u32 zWrite, u32 zFunc)
{
    m_reg = (m_reg & ~0x74u) | (zWrite & 1) << 2 | (zFunc & 7) << 4;
}

void DepthStencilControl01304c20::setDepthEnable(bool enable)
{
    m_reg = (m_reg & ~2u) | (u32)enable << 1;
}

void DepthStencilControl01304c20::setStencilEnable(bool enable)
{
    m_reg = (m_reg & ~1u) | (u32)enable;
}

void DepthStencilControl01304c20::setStencilFunction(u32 func)
{
    m_reg = (m_reg & ~0x700u) | (func & 7) << 8;
}

void DepthStencilControl01304c20::setStencilFunctionBack(u32 func)
{
    m_reg = (m_reg & ~0x700000u) | (func & 7) << 20;
}

void DepthStencilControl01304c20::setSeparateStencilEnable(bool enable)
{
    m_reg = (m_reg & ~0x80u) | (u32)enable << 7;
}
