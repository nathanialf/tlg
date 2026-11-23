/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_game_jsblendstate.h"

/* CreateBlendState (its messages, "JsGraphics :CreateBlendState"): a null
 * description, or a render target's value out of its range (only the first
 * target's unless the targets blend independently), is printed with the file
 * and line, the out pointer cleared and -6 returned; else a new state made
 * from the description is handed out, when there is an out pointer, and 0
 * returned. */
// NONMATCHING: 183/187, the success path's `xor eax, eax` (the return value) is scheduled
// before its three last stores (0x12fef67); the base keeps it after them, before the jump
int CreateBlendState(const JsBlendDesc *pBlendStateDesc, Object016d7ed8 **ppBlendState)
{
    if (pBlendStateDesc == nullptr) {
        printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid args. "
               "pBlendStateDesc == nullptr.\n",
               JS_BLEND_STATE_CPP, 60);
        if (ppBlendState)
            *ppBlendState = nullptr;
        return -6;
    }

    for (u32 i = 0; i < (pBlendStateDesc->IndependentBlendEnable ? 8u : 1u); i++) {
        const JsRenderTargetBlendDesc &target = pBlendStateDesc->RenderTarget[i];
        if (target.SrcBlend >= JS_BLEND_COUNT) {
            printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid desc.  "
                   "pBlendStateDesc->RenderTarget[ %d ].SrcBlend( 0x%0x ).\n",
                   JS_BLEND_STATE_CPP, 67, i, target.SrcBlend);
            goto error;
        }
        if (target.DestBlend >= JS_BLEND_COUNT) {
            printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid desc.  "
                   "pBlendStateDesc->RenderTarget[ %d ].DestBlend( 0x%0x ).\n",
                   JS_BLEND_STATE_CPP, 72, i, target.DestBlend);
            goto error;
        }
        if (target.SrcBlendAlpha >= JS_BLEND_COUNT) {
            printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid desc.  "
                   "pBlendStateDesc->RenderTarget[ %d ].SrcBlendAlpha( 0x%0x ).\n",
                   JS_BLEND_STATE_CPP, 77, i, target.SrcBlendAlpha);
            goto error;
        }
        if (target.DestBlendAlpha >= JS_BLEND_COUNT) {
            printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid desc.  "
                   "pBlendStateDesc->RenderTarget[ %d ].DestBlendAlpha( 0x%0x ).\n",
                   JS_BLEND_STATE_CPP, 82, i, target.DestBlendAlpha);
            goto error;
        }
        if (target.BlendOp >= JS_BLEND_OP_COUNT) {
            printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid desc.  "
                   "pBlendStateDesc->RenderTarget[ %d ].BlendOp( 0x%0x ).\n",
                   JS_BLEND_STATE_CPP, 87, i, target.BlendOp);
            goto error;
        }
        if (target.BlendOpAlpha >= JS_BLEND_OP_COUNT) {
            printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid desc.  "
                   "pBlendStateDesc->RenderTarget[ %d ].BlendOpAlpha( 0x%0x ).\n",
                   JS_BLEND_STATE_CPP, 92, i, target.BlendOpAlpha);
            goto error;
        }
        if (target.RenderTargetWriteMask >= JS_COLOR_WRITE_ENABLE_COUNT) {
            printf("%s(%d): ERROR : JsGraphics :CreateBlendState: invalid desc.  "
                   "pBlendStateDesc->RenderTarget[ %d ].RenderTargetWriteMask( 0x%0x ).\n",
                   JS_BLEND_STATE_CPP, 97, i, target.RenderTargetWriteMask);
            goto error;
        }
    }

    if (ppBlendState) {
        Object016d7ed8 *state = new Object016d7ed8();
        state->m_desc = *pBlendStateDesc;
        const JsRenderTargetBlendDesc *targets = state->m_desc.RenderTarget;
        u32 mask = 0;
        for (int i = 0; i < 8; i++) {
            const JsRenderTargetBlendDesc &target =
                targets[state->m_desc.IndependentBlendEnable ? i : 0];
            BlendControl012fed00 &blendControl = state->m_blendControl[i];
            blendControl.init();
            if (target.BlendEnable) {
                blendControl.setBlendEnable(true);
                blendControl.setSeparateAlphaEnable(true);
                blendControl.setColorEquation(D_15254d0[target.SrcBlend], D_1525520[target.BlendOp],
                                              D_15254d0[target.DestBlend]);
                blendControl.setAlphaEquation(D_15254d0[target.SrcBlendAlpha],
                                              D_1525520[target.BlendOpAlpha],
                                              D_15254d0[target.DestBlendAlpha]);
            }
            mask |= (target.RenderTargetWriteMask & 0xf) << (i * 4);
        }
        state->m_alphaToMaskControl.init();
        if (state->m_desc.AlphaToCoverageEnable)
            state->m_alphaToMaskControl.setEnable(true);
        state->m_renderTargetMask = mask;
        *ppBlendState = state;
    }
    return 0;

error:
    if (ppBlendState)
        *ppBlendState = nullptr;
    return -6;
}
