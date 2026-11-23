/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_simd.h"

/* derived names: a named vector, 32 bytes */
struct NamedVector004baab0 { /* derived name */
    Name name;               /* +0x0 */
    u8 unknown4[0xc];
    Vec4 value; /* +0x10 */
};

/* derived names: the object FUN_0046c870 hands FUN_004baab0, its named
 * vectors at +0x5d0, the last one set the most recently */
struct Owner004baab0 { /* derived name */
    void setVector(const Name &name, const Vec4 &value);

    u8 unknown0[0x5d0];
    Array05943280<NamedVector004baab0> vectors; /* +0x5d0 */
};

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
