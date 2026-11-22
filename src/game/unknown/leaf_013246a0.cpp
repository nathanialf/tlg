/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_assert.h"
#include "tlg_game_jsunknown.h"

/* ~JsUnknown (its report, JsUnknown.cpp:76): no reference is left. The
 * destructor is the class's key function, so this file emits the vtable,
 * the deleting destructor 0x1324770 and slot 2. */
JsUnknown::~JsUnknown()
{
    ANZU_ASSERT(JS_UNKNOWN_CPP, 76, m_referenceCount == 0);
}

void JsUnknown::Destroy()
{
    delete this;
}
