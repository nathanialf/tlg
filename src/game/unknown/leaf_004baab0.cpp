/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_owner004baab0.h"

/* FUN_004baab0: the vector of a name set: the last one's value replaced when
 * it has the name, else the name's earlier entry removed and the name and
 * the value appended. The new entry is constructed (its name cleared) and
 * then tested before it is filled: `add rbx, r14; mov dword [rbx], 0; je`
 * (the reserved placement form is not tested by the compiler itself) */
void Owner004baab0::setVector(const Name &name, const Vec4 &value) /* derived name */
{
    if (vectors.size()) {
        int last = vectors.size() - 1;
        if (vectors.at(last).name == name) {
            vectors.at(last).value = value;
            return;
        }
        for (int i = 0; i < last; ++i) {
            if (vectors.at(i).name == name) {
                vectors.removeAt(i);
                break;
            }
        }
    }
    NamedVector004baab0 *entry = new (vectors.append()) NamedVector004baab0;
    if (entry) {
        entry->name = name;
        entry->value = value;
    }
}
