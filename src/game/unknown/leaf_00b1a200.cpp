/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: resolves an object's name once: while the byte at +0xc
 * is clear, a name at +0x38 that is not the empty one is looked up (the
 * record of its entry in the name table, taken when this thread may use
 * it, else null) and the counted reference at +0x48 is set to it by
 * compare-and-swap; then the byte is set. The named object's class is one
 * over the reference's (`cmp r15, rbx` at 0xb1a284, the new pointer
 * first). The owner is not traced. */
struct Value00b1a200 : Node00503fb0 { /* derived name */
};

struct Object00b1a200 { /* derived name */
    u8 unknown0[0xc];
    bool resolved; /* +0xc */
    u8 unknownd[0x2b];
    Name name; /* +0x38 */
    u8 unknown3c[0xc];
    AtomicRef0045c470<Node00503fb0> reference; /* +0x48 */
};

void FUN_00b1a200(Object00b1a200 *self) /* derived name */
{
    if (!self->resolved) {
        if (self->name.index != 0) {
            Value00b1a200 *found = 0;
            Value00b1a200 *object =
                static_cast<Value00b1a200 *>(D_17ac870[self->name.index].record18);
            if (object && ((object->flags16 & 4) || D_16dc098))
                found = object;
            self->reference.set(found);
        }
        self->resolved = true;
    }
}
