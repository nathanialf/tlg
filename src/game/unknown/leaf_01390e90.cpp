/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived name: the entries walked from the first to the end (`shl rcx, 3`
 * on the count, then `add rdx, 8; add rcx, -8; jne`). It is Object016b4ce0's
 * search for an entry by name, written as a free friend function only
 * because the layout places an unrowed callee by its FUN_<addr> name and a
 * member draft has none (round 572C): when it is a row it returns to a
 * member of the class. */
// NONMATCHING: the result's copies: the base gives each exit of the exchange's release its own
// `mov rax, rbx; jmp` and the last found's exit its own block (314 bytes); the build joins them
// in one block (290 bytes). The loop and the exchange are the base's. Seven forms tried.
Entry016b4ce0 *FUN_01390e90(Object016b4ce0 *self, const Name &name) /* derived name */
{
    Entry016b4ce0 *found = Entry016b4ce0::of(self->found10.get());
    if (found == 0 || found->name310 != name.index) {
        found = 0;
        for (const Ref00503fb0<Object016b9108> *at = self->entries.begin();
             at != self->entries.end(); ++at) {
            Object016b9108 *object = at->get();
            Entry016b4ce0 *entry = Entry016b4ce0::of(object);
            if (entry->name310 == name.index) {
                self->found10.set(object);
                found = entry;
                break;
            }
        }
    }
    return found;
}
