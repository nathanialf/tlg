/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_registry00cb8240.h"

/* derived names: FUN_00c1ac70 empties a table's objects: each object of the
 * list FUN_00cb8240 gives whose type is the one at 0x5937fe8 or derives from
 * it has its pointer at +0x28 taken out and handed to FUN_00c1a850; one of
 * the type at 0x5938160 hands its pointer at +0x30, when set, to
 * FUN_00c1be50. The two pointed classes are not traced. */
struct Member00c1a850; /* derived name */
struct Member00c1be50; /* derived name */

struct Object00c1ac70 : Object00cb8240 { /* derived name */
    u8 unknown20[0x8];
    Member00c1a850 *unknown28; /* +0x28 */
    Member00c1be50 *unknown30; /* +0x30 */
};

extern const Type00503fb0 *D_5937fe8;
extern const Type00503fb0 *D_5938160;

void FUN_00c1a850(Member00c1a850 *member); /* derived name */
void FUN_00c1be50(Member00c1be50 *member); /* derived name */

// NONMATCHING: 326 bytes against 326 (80/97), the first type walk's pointer: the base copies
// the object's type before the first compare (`mov rdx, rax; cmp rax, rcx; je` at 0xc1ad02) and
// keeps the object in rsi, the build copies it after the branch (`cmp; je; mov rsi, rcx`) and
// keeps the object in rax; every instruction is otherwise the base's
void FUN_00c1ac70(Registry00cb8240 *self) /* derived name */
{
    Array01343a80<Object00cb8240 *> objects;
    unsigned count = FUN_00cb8240(self, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object00c1ac70 *object = static_cast<Object00c1ac70 *>(objects.at(i));
        if (isKindOf(object->type, D_5937fe8)) {
            Member00c1a850 *member = object->unknown28;
            object->unknown28 = 0;
            FUN_00c1a850(member);
        } else if (isKindOf(object->type, D_5938160)) {
            if (object->unknown30)
                FUN_00c1be50(object->unknown30);
        }
    }
}
