/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_game_jsdepthstencilstate.h"

/* CreateDepthStencilState (the name its message gives, "JsGraphics
 * :CreateDepthStencilState"): a null description is printed with the file
 * and line (JsDepthStencilState.cpp:97), the out pointer cleared and -6
 * returned; a null out pointer gives -2; else a new state made from the
 * description is handed out and 0 returned. */
// NONMATCHING: 86/113, every store and the depth word's chain of ors as the base's; the depth
// word's eight reads of the description are scheduled ahead of the chain (0x1304cdb on, the
// base reads each just before its or) and the table's base is r8, not rdi: 429 bytes against 424
int CreateDepthStencilState(const JsDepthStencilDesc *pDepthStencilDesc,
                            Object016d7f00 **ppDepthStencilState)
{
    if (pDepthStencilDesc == nullptr) {
        printf("%s(%d): ERROR : JsGraphics :CreateDepthStencilState: invalid args. "
               "pDepthStencilDesc == nullptr.\n",
               JS_DEPTH_STENCIL_STATE_CPP, 97);
        if (ppDepthStencilState)
            *ppDepthStencilState = nullptr;
        return -6;
    }
    if (ppDepthStencilState == nullptr)
        return -2;
    const JsDepthStencilDesc &desc = *pDepthStencilDesc;
    Object016d7f00 *state = new Object016d7f00();
    state->m_desc = desc;
    DepthStencilRegisters01304c20 &regs = state->m_registers;
    regs.stencilControl.init();
    regs.depthControl.setDepthControl(desc.DepthWriteMask, D_1525590[desc.DepthFunc]);
    regs.depthControl.setDepthEnable(desc.DepthEnable);
    regs.depthControl.setStencilEnable(desc.StencilEnable);
    regs.depthControl.setStencilFunction(D_1525590[desc.FrontFace.StencilFunc]);
    regs.depthControl.setStencilFunctionBack(D_1525590[desc.BackFace.StencilFunc]);
    regs.depthControl.setSeparateStencilEnable(true);
    regs.stencilControl.mask = desc.StencilReadMask;
    regs.stencilControl.opVal = 1;
    regs.stencilControl.testVal = 0;
    regs.stencilControl.writeMask = desc.StencilWriteMask;
    regs.stencilOps.init();
    regs.stencilOps.setStencilOps(D_1525540[desc.FrontFace.StencilFailOp],
                                  D_1525540[desc.FrontFace.StencilPassOp],
                                  D_1525540[desc.FrontFace.StencilDepthFailOp]);
    regs.stencilOps.setStencilOpsBack(D_1525540[desc.BackFace.StencilFailOp],
                                      D_1525540[desc.BackFace.StencilPassOp],
                                      D_1525540[desc.BackFace.StencilDepthFailOp]);
    *ppDepthStencilState = state;
    return 0;
}
