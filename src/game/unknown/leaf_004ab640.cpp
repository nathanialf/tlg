/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: gives up an object's counted reference at +0x38 when it
 * holds one: FUN_00c63970 is called with the member at +0xd0 of the object
 * the pointer at 0x5938c40 holds, the object at 0x57d74b4, the name at
 * +0x40 and the reference, then the name is released and the reference
 * emptied by compare-and-swap. The callee's parameters are typed from this
 * call alone; the owner and the object at 0x57d74b4 are not traced. */
struct Member05938c40_d0; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xd0];
    Member05938c40_d0 *unknownd0;
};

extern Object05938c40 *D_5938c40;

struct Object057d74b4; /* derived name */

extern Object057d74b4 D_57d74b4;

struct Object004ab640 { /* derived name */
    u8 unknown0[0x38];
    AtomicRef0045c470<Node00503fb0> reference; /* +0x38 */
    Name name;                                 /* +0x40 */
};

void FUN_00c63970(Member05938c40_d0 *member, Object057d74b4 *object, Name *name,
                  AtomicRef0045c470<Node00503fb0> *reference); /* derived name */

void FUN_004ab640(Object004ab640 *self) /* derived name */
{
    if (self->reference.get()) {
        FUN_00c63970(D_5938c40->unknownd0, &D_57d74b4, &self->name, &self->reference);
        self->name.release();
        self->reference.clear();
    }
}
