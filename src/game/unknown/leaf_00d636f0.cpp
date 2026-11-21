/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the record FUN_00d636f0 works on: a counted reference at
 * +0x50, emptied by compare-and-swap; the rest not traced */
struct Object00d636f0 { /* derived name */
    u8 unknown0[0x50];
    AtomicRef0045c470<Object016b9108> unknown50; /* +0x50 */
};

void FUN_00d5c810(Object00d636f0 *self); /* derived name */
void FUN_00c5a160(Object00d636f0 *self); /* derived name */

/* derived name: FUN_00d5c810 on the record, the reference at +0x50 emptied,
 * then FUN_00c5a160 on the record (a tail call); called at 0xd5fdfb,
 * 0xd5ff9b and 0xd60161 */
void FUN_00d636f0(Object00d636f0 *self)
{
    FUN_00d5c810(self);
    self->unknown50.clear();
    FUN_00c5a160(self);
}
