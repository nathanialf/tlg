/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_type.h"

extern Type00503fb0 *D_598c670; /* derived name: the type of the objects counted */
extern Type00503fb0 *D_598c818; /* derived name: the type of the groups walked */

/* derived names: what an object of the counted type refers to at +0x28: an
 * int at +0x2c added to the total */
struct Value00c11e60 { /* derived name */
    u8 unknown0[0x2c];
    int amount; /* +0x2c */
};

/* derived names: an object the walk is given: at +0x28 a value (the
 * counted type, which adds it while its int at +0x30 is set) or a list of
 * objects with their count at +0x30 (the group type) */
struct Object00c11e60 : Object016b9108 { /* derived name */
    u8 unknown24[0x4];
    void *held28; /* +0x28 */
    unsigned n30; /* +0x30 */
};

/* derived names: the total at +0x10 FUN_00c0fb30 keeps */
struct Total00c11e60 { /* derived name */
    u8 unknown0[0x10];
    int total; /* +0x10 */
};

/* derived name: each object of the list adds its value's amount to the
 * total when it is of the counted type and its int at +0x30 is set; an
 * object of the group type has its own list walked the same way */
// NONMATCHING: in the whole module the same instructions but for two registers: the base walks the
// list in r12 and keeps its end in r15, this build the other way round (the index form and the end
// formed first measured, round 484D)
void FUN_00c11e60(Total00c11e60 *self, Object00c11e60 **objects, unsigned count)
{
    const Type00503fb0 *counted = D_598c670;
    Object00c11e60 **end = objects + count;
    for (Object00c11e60 **object = objects; object != end; ++object) {
        Object00c11e60 *it = *object;
        if (isKindOf(it->type, counted)) {
            if (it->n30)
                self->total += static_cast<Value00c11e60 *>(it->held28)->amount;
        } else if (isKindOf(it->type, D_598c818)) {
            FUN_00c11e60(self, static_cast<Object00c11e60 **>(it->held28), it->n30);
        }
    }
}
