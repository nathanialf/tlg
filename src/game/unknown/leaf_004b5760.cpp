/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted004b5ff0.h"

/* FUN_004b5760: for a source whose slot 5 answers true, an object of the
 * type at 0x57d7ea8 made under the empty name (FUN_00cbc5a0, mode 1); it
 * holds the source at +0x50 (exchanged in) and the source's answer, asked
 * again, at +0x87, and a reference to it is appended to the holder's array
 * at +0x28 (FUN_004b5ff0, an empty reference for null). The made object,
 * else null, is returned. Its callers are not traced. */
// NONMATCHING: register assignment only (91 of 134): the base holds the
// made object in r14, the holder in rbx and the stack guard's address in
// r15 (reloaded through rbx at 0x4b5882 and copied back), the build r15,
// r14 and rbx (one register for both loads of the guard's address). An
// early return for the null arm gives the same; the making as an inline
// member of the made class 76 of 135.
Counted004b5ff0 *FUN_004b5760(Holder004b5760 *holder, Source004b5760 *source) /* derived name */
{
    Counted004b5ff0 *object = 0;
    if (source && source->slot5()) {
        object = static_cast<Counted004b5ff0 *>(FUN_00cbc5a0(D_5945a38, D_57d7ea8, Name(), 1));
        object->source50.set(source);
        object->taken87 = source->slot5();
        holder->objects28.push(Ref00503fb0<Counted004b5ff0>(object));
    }
    return object;
}
