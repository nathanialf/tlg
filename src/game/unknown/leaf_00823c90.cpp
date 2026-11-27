/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object00823c90.h"

/* derived names: the string's name (interned as a copy), compared with the
 * name of each object at +0x270; on the first that has it, slot 15 runs and
 * the answer is 1, else 0; the name is released last. */
// NONMATCHING: 44/63 at the base's 203 bytes, registers only: the object and the name trade r14 and
// r15 (and the counter and the element esi and edx); the control flow and every instruction's place
// are the base's. Compiled: the answer declared before the name (no change).
int FUN_00823c90(Object00823c90 *self, const char *string) /* derived name */
{
    const unsigned interned = Name::intern(string);
    Name name(interned);
    int found = 0;
    for (unsigned i = 0; i < self->objects.size(); ++i) {
        if (self->objects.at(i)->name == name) {
            self->slot15();
            found = 1;
            break;
        }
    }
    return found;
}
