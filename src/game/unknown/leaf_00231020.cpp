/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: one 0xe0-byte entry of the array at +0x558 of the object:
 * a name at +0x0, a reference another thread may replace at +0x8 and a
 * counted reference at +0xb8. Its destructor is a function of its own
 * (0x1347ab0): the reference at +0xb8 released, then the one at +0x8, then
 * the name. The rest is not traced. */
struct Entry00231020 {                      /* derived name */
    Name name;                              /* +0x0 */
    AtomicRef0045c470<Object016b9108> node; /* +0x8 */
    u8 unknown10[0xa8];
    Ref00503fb0<Object016b9108> unknownb8; /* +0xb8 */
    u8 unknownc0[0x20];
};

struct Object00231020 { /* derived name */
    ~Object00231020();

    u8 unknown0[0x558];
    Array05943280<Entry00231020> entries; /* +0x558 */
};

// NONMATCHING: the object's destructor (FUN_0022fd60, 2,628 bytes; the
// vtable 0x16a7988): only the entries at +0x558 are written: destroyed one
// by one through the entry's destructor (`imul rdi, rax, 0xe0; add rdi,
// [r14+0x558]; call 0x1347ab0` at 0x2302b0), then the block released. The
// entry's destructor has five callers in the base; this is the second one
// written.
Object00231020::~Object00231020() {}

void FUN_002307d0(Object00231020 *self); /* derived name */
void FUN_00c57220(Object016b9108 *node); /* derived name */

/* derived names: after FUN_002307d0, each entry that holds a node hands it
 * to FUN_00c57220 and empties its reference by compare-and-swap (the array
 * read again after the call), then every entry is destroyed and the count
 * cleared. The owner is not traced. */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 365 at the
 * link, over its threshold of 175: one signature changes no row) */
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
