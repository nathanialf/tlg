/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
// NONMATCHING (FUN_00b414a0 and its thunk 0xb41630 only): greedy's assignment: the base keeps the mask in ebx until the loop and spills it there (`mov [rbp-0x3c], ebx`), the build spills it at entry (`mov [rbp-0x30], esi`); the thunk's jump target is not resolved by its method name.
#include "tlg_game_object01397620.h"

/* derived names: slot 6 of the vtable at 0x16b5c48 and, through the thunk
 * 0xb40760 (this - 0x28, the body inlined into it), the one slot of the base
 * at +0x28: the int at +0x20, with the answers of the objects at +0x40 (bit
 * 0 of the mask set, asked with it cleared) and +0x48 (bit 2, likewise) and
 * of the two held objects added. */
int Object01397620::FUN_00004340(int mask) const
{
    int result = flags;
    if ((mask & 1) && child40)
        result |= child40->FUN_00004340(mask & ~1);
    if ((mask & 4) && child48)
        result |= child48->FUN_00004340(mask & ~4);
    if (unknown58.get())
        result |= unknown58.get()->FUN_00004340(mask);
    if (unknown60.get())
        result |= unknown60.get()->FUN_00004340(mask);
    return result;
}

/* derived names: slot 6 of the vtable at 0x16b5ce8 (its thunk 0xb41630 in
 * the base at +0x28): the base's answer (0xb406d0, inlined), then the held
 * object at +0x80's and each object of the array at +0x68's, each held by a
 * copy of its reference while it is asked. */
int Object016b5ce8::FUN_00004340(int mask) const
{
    int result = Object01397620::FUN_00004340(mask);
    if (unknown80.get())
        result |= unknown80.get()->FUN_00004340(mask);
    unsigned count = unknown68.size();
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Object016b9108> child(unknown68.at(i));
        if (child.get())
            result |= static_cast<Class137ba70 *>(child.get())->FUN_00004340(mask);
    }
    return result;
}
