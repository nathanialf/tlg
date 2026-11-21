/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the record FUN_00d24260 empties: two pointers at +0x50,
 * an array of counted references at +0x68 and a counted reference at +0x80;
 * the rest not traced */
struct Object00d24260 { /* derived name */
    u8 unknown0[0x50];
    void *unknown50; /* +0x50 */
    void *unknown58; /* +0x58 */
    u8 unknown60[8];
    Object0134f620 unknown68;                    /* +0x68 */
    AtomicRef0045c470<Object016b9108> unknown80; /* +0x80 */
};

/* derived name: the array emptied to no capacity (FUN_0138c8d0 with 0), the
 * two pointers cleared (one 16-byte store), then the reference emptied by
 * compare-and-swap */
void FUN_00d24260(Object00d24260 *self)
{
    self->unknown68.clear(0);
    self->unknown50 = 0;
    self->unknown58 = 0;
    self->unknown80.clear();
}
