/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_assert.h"
#include "tlg_game_jsrasterizerstate.h"
#include "tlg_game_object05adaaa8.h"

/* CreateRasterizerState (its report, JsRasterizerState.cpp:18): the out
 * pointer checked, then a new state made from the description, or the
 * device's default state handed out with a reference taken. */
void Object05adaaa8::CreateRasterizerState(const JsRasterizerDesc *pRasterizerDesc,
                                           Object016d7fd0 **ppRasterizerState)
{
    /* the condition as the report spells it (0x15cda5a) */
    // clang-format off
    ANZU_ASSERT(JS_RASTERIZER_STATE_CPP, 18, ppRasterizerState!= nullptr);
    // clang-format on
    if (pRasterizerDesc) {
        *ppRasterizerState = new Object016d7fd0(*pRasterizerDesc);
    } else {
        defaultRasterizerState->AddRef();
        *ppRasterizerState = defaultRasterizerState;
    }
}
