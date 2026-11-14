/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: fills a holder's counted reference (+0x8) with an object
 * made from a source object, then lowers the holder's int at +0x18 by one.
 * With no source, or with the flag 2 at +0x2c of the source's type (+0x18)
 * set, the reference is emptied; else FUN_00cb8ac0 makes the object from
 * the type, 1, the source and the next value of the counter D_5945a14
 * (`lock xadd; inc ecx`). The made object's class is one over the
 * reference's (`cmp rcx, rbx` at 0x8a94a4, the new pointer first). The
 * classes are not traced. */
struct Made008a9440 : Node00503fb0 { /* derived name */
};

struct Type008a9440 { /* derived name */
    u8 unknown0[0x2c];
    u8 flags; /* +0x2c */
};

struct Source008a9440 { /* derived name */
    u8 unknown0[0x18];
    Type008a9440 *type; /* +0x18 */
};

struct Holder008a9440 { /* derived name */
    u8 unknown0[0x8];
    AtomicRef0045c470<Node00503fb0> reference; /* +0x8 */
    u8 unknown10[0x8];
    int pending; /* +0x18 */
};

extern int D_5945a14; /* derived name: a counter of the objects made */

Made008a9440 *FUN_00cb8ac0(Type008a9440 *type, int unknown, Source008a9440 *source,
                           int serial); /* derived name */

void FUN_008a9440(Source008a9440 *source, Holder008a9440 *holder) /* derived name */
{
    Made008a9440 *made = 0;
    if (source) {
        Type008a9440 *type = source->type;
        if (!(type->flags & 2))
            made = FUN_00cb8ac0(type, 1, source, __sync_add_and_fetch(&D_5945a14, 1));
    }
    holder->reference.set(made);
    __sync_fetch_and_sub(&holder->pending, 1);
}
