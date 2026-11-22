/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_assert.h"
#include "tlg_game_jsview.h"

/* ~JsView (its report, JsView.cpp:24): the resource checked to be set and
 * its reference dropped, then the base's destructor, a tail call. The
 * destructor is the class's key function, so this file emits the vtable and
 * the deleting destructor 0x1326c10. */
JsView::~JsView()
{
    /* the condition as the report spells it ("m_pResource!= nullptr", 0x15cf0d1) */
    // clang-format off
    ANZU_ASSERT(JS_VIEW_CPP, 24, m_pResource!= nullptr);
    // clang-format on
    m_pResource->Release();
}
