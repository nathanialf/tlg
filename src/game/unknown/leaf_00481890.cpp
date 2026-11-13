/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets the counted reference at +0x8 of the object to
 * another object, by compare-and-swap, then passes the object on with the
 * pointer at +0x50 to FUN_004b6d00, a tail call. The classes are not
 * traced. */
struct Target00481890; /* derived name */

struct Object00481890 { /* derived name */
    u8 unknown0[0x8];
    AtomicRef0045c470<Node00503fb0> unknown8; /* +0x8 */
    u8 unknown10[0x40];
    Target00481890 *unknown50; /* +0x50 */
};

/* the object set: a class of its own over the counted one (the pointer is
 * converted before the exchange: AtomicRef0045c470's set) */
class Value00481890 : public Node00503fb0 /* derived name */
{
};

void FUN_004b6d00(Target00481890 *target, Value00481890 *value); /* derived name */

// NONMATCHING: 54/65, 218 bytes for 227: before the tail call the base tests
// the object again and passes null in a branch of its own (`test r15, r15;
// je; mov rsi, r15; jmp; xor esi, esi`), where the build passes it as it is:
// a select of the pointer and null kept as a branch (the parked class).
void FUN_00481890(Object00481890 *self, Value00481890 *value) /* derived name */
{
    self->unknown8.set(value);
    FUN_004b6d00(self->unknown50, value);
}
