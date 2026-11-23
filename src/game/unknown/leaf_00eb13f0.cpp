/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016be818.h"

/* derived name: the complete destructor: the kind 0 object's link back to
 * this one cleared, then the reference dropped (the object read again after
 * the store); the base's destructor (leaf_00cef280.cpp) follows. The
 * destructor is the class's key function, so this file emits the vtable. */
// NONMATCHING (FUN_00eb13f0 only): the base ends in Object00cef280's vptr
// store (0xeb1456), the parked class of 0xcef280 (D16: its body is empty
// here); the deleting destructor FUN_00eb1470 drops it before the delete
Object016be818::~Object016be818()
{
    if (kind == 0)
        static_cast<Shape00eb1170 *>(shape)->owner = 0;
    shape->removeReference();
}
