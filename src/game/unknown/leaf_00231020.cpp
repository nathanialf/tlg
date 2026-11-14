/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: one 0xe0-byte entry of the array at +0x558 of the object:
 * a name at +0x0, a reference another thread may replace at +0x8 and a
 * counted reference at +0xb8. Its destructor is a function of its own
 * (0x1347ab0): the reference at +0xb8 released, then the one at +0x8, then
 * the name. The rest is not traced. */
struct Entry00231020 {                    /* derived name */
    Name name;                            /* +0x0 */
    AtomicRef0045c470<Node00503fb0> node; /* +0x8 */
    u8 unknown10[0xa8];
    Ref00503fb0<Node00503fb0> unknownb8; /* +0xb8 */
    u8 unknownc0[0x20];
};

struct Object00231020 { /* derived name */
    u8 unknown0[0x558];
    Array05943280<Entry00231020> entries; /* +0x558 */
};

void FUN_002307d0(Object00231020 *self); /* derived name */
void FUN_00c57220(Node00503fb0 *node);   /* derived name */

/* derived names: after FUN_002307d0, each entry that holds a node hands it
 * to FUN_00c57220 and empties its reference by compare-and-swap (the array
 * read again after the call), then every entry is destroyed and the count
 * cleared. The owner is not traced. */
void FUN_00231020(Object00231020 *self) /* derived name */
{
    FUN_002307d0(self);
    for (unsigned i = 0; i < self->entries.size(); ++i) {
        if (self->entries.at(i).node.get()) {
            FUN_00c57220(self->entries.at(i).node.get());
            self->entries.at(i).node.clear();
        }
    }
    self->entries.removeAll();
}
