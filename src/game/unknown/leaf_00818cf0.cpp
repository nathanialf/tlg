/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the int at +0x34 of the object its second argument
 * points to is 0, sets it to 1 and passes the pointer at +0x48 of the object
 * the pointer at 0x57c9390 holds and that object to FUN_0081a930, a tail call
 * (the callee keeps its second argument, a store of rsi in its frame); slot 0
 * of the vtable at 0x16ae798 (its pointer at 0x16ae7a8; no constructor stores
 * it), its slot 1 the empty method FUN_001af750. The first argument is not
 * read; the classes and the callee's return type are not traced. */
struct Object00818cf0;    /* derived name */
struct Member057c9390_48; /* derived name */

struct Argument00818cf0 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x48];
    Member057c9390_48 *unknown48;
};

extern Object057c9390 *D_57c9390;

void FUN_0081a930(Member057c9390_48 *member, Argument00818cf0 *object); /* derived name */

void FUN_00818cf0(Object00818cf0 *, Argument00818cf0 *object) /* derived name */
{
    if (object->unknown34 == 0) {
        object->unknown34 = 1;
        FUN_0081a930(D_57c9390->unknown48, object);
    }
}
