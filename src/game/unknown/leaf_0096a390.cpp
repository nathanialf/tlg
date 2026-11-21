/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 8 of the class at 0x16b1468 (its thunk 0x96a480):
 * the bits set in the root class's flags, then the same slot asked with them
 * of each object of the array at +0x58, the count read once, each held by a
 * counted reference of its own across the call (`call [rax+0x40]`); an
 * empty slot is passed over */
void Object016b1468::FUN_0137ba70(int bits)
{
    flags |= bits;
    const unsigned count = unknown58.size();
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Object016b9108> child(unknown58.at(i));
        if (child.get())
            static_cast<Class137ba70 *>(child.get())->FUN_0137ba70(bits);
    }
}
