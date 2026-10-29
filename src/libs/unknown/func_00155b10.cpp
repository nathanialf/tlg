/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Listener00155b10::FUN_00155b00(u8 value)
{
    flag |= value;
    owner->changed = true;
}

void Listener00155b10::FUN_00155b10()
{
    ListenedSignals00155b10 *signals = object->FUN_slot8();
    signals->signalA.unsubscribe(this, &Listener00155b10::FUN_00155b00);
    signals->signalB.unsubscribe(this, &Listener00155b10::FUN_00155b10);
    object = 0;
    owner->changed = true;
}
