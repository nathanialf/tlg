/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: drops the counted reference at +0xa0 of the object (the
 * pointer cleared first), then releases the names at +0x90 and +0x5c. The
 * members go in descending order of offset, as a destructor's would; no
 * vptr is stored. The owner is not traced. */
struct Object01365e50 { /* derived name */
    u8 unknown0[0x5c];
    Name unknown5c; /* +0x5c */
    u8 unknown60[0x30];
    Name unknown90; /* +0x90 */
    u8 unknown94[0xc];
    Ref00503fb0<Node00503fb0> unknowna0; /* +0xa0 */
};

void FUN_01365e50(Object01365e50 *self) /* derived name */
{
    self->unknowna0.release();
    self->unknown90.release();
    self->unknown5c.release();
}
