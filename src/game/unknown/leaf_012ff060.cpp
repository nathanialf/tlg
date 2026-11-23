/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_jsbuffer.h"

/* the buffer's destructor: its entry at +0x30 handed back to the heap it came
 * from (the Garlic one's member at +0x100b8 and count at +0x100a0, else the
 * Onion one's at +0x100e8 and +0x100b0) and cleared, then the base's
 * destructor, a tail call. The destructor is the class's key function, so
 * this file emits the vtable and the deleting destructor 0x12ff1a0. */
// NONMATCHING: the base reads the device (`mov r15, [D_5adaaa8]`) and the entry before the usage's test, keeps one
// callee-saved register fewer, and tests the CPU's read access as a whole word (`mov eax, 0x20000; and eax, [rbx+0x18c]`);
// this build reads the device in each arm and tests one byte (`test byte [r12+0x18e], 2`). The tail call after the
// stack guard's check is the base's (AnzuAssertFailed). The deleting destructor FUN_012ff1a0 inlines this one in the
// base and calls it here.
JsBuffer::~JsBuffer()
{
    if (IsGarlic()) {
        returnEntry(entry30);
    } else if (entry30) {
        JsDevice *owner = D_5adaaa8;
        FUN_0131e2d0(owner->unknown100e8, entry30);
        __sync_fetch_and_add(&owner->unknown100b0, 1);
    }
    entry30 = 0;
}
