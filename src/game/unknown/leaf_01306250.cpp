/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_object05adaaa8.h"

/* The render device's source file, as the report names it (0x15cc515). */
#define JS_DEVICE_CPP /* derived name */                                                           \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsDevice.cpp"

/* DeallocatePrivateData (the report's name for the function): the entry
 * checked to be one of the device's, then put at the head of the free
 * list, its next the old head. */
void Object05adaaa8::DeallocatePrivateData(PrivateData01306250 *ptr)
{
    // clang-format off: the report spells the condition with spaces inside the parentheses
    ANZU_ASSERT(JS_DEVICE_CPP, 940, ( ptr - m_privateData ) < kPrivateDataCountMax);
    // clang-format on
    ptr->next.SetPointer(m_freePrivateData);
    m_freePrivateData = ptr;
}
