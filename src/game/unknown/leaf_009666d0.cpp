/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 5 of the class at 0x16b13b8 (its thunk 0x9667c0):
 * the same slot asked of each object of the array at +0x48, the count read
 * once, each held by a counted reference of its own across the call (`lock
 * inc` before `call [rax+0x28]`, the release after); an empty slot is
 * passed over */
void Object016b13b8::FUN_0137ba50()
{
    const unsigned count = unknown48.size();
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Object016b9108> child(unknown48.at(i));
        if (child.get())
            static_cast<Class137ba70 *>(child.get())->FUN_0137ba50();
    }
}
