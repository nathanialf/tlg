/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: makes one of four objects by kind (0 to 3, the jump table
 * 0x1558c10): FUN_00cbc5a0 with the object the pointer at 0x5945a38 holds,
 * the kind's pointer (0x5946d70, 0x5946cb0, 0x5946cc8, 0x5946d10), the empty
 * name and 0, the result passed to FUN_00cf8120 and returned; any other kind
 * gives null. What the four pointers hold and the callees' parameters past
 * their use here are not traced. */
struct Object05945a38;    /* derived name */
struct Object00cbc5a0;    /* derived name */
struct Prototype00a05e80; /* derived name */

extern Object05945a38 *D_5945a38;
extern Prototype00a05e80 *D_5946d70;
extern Prototype00a05e80 *D_5946cb0;
extern Prototype00a05e80 *D_5946cc8;
extern Prototype00a05e80 *D_5946d10;

Object00cbc5a0 *FUN_00cbc5a0(Object05945a38 *owner, Prototype00a05e80 *prototype, const Name &name,
                             int flags);   /* derived name */
void FUN_00cf8120(Object00cbc5a0 *object); /* derived name */

// NONMATCHING: the base keeps four temporaries and no destructor after the calls: the empty
// name's release is gone because the module knew FUN_00cbc5a0 only reads its name (it copies
// it, 0xcbc5d4): needs FUN_00cbc5a0's body in the module; the build releases one shared temporary
Object00cbc5a0 *FUN_00a05e80(int kind) /* derived name */
{
    Object00cbc5a0 *object;
    switch (kind) {
    case 0:
        object = FUN_00cbc5a0(D_5945a38, D_5946d70, Name(), 0);
        break;
    case 1:
        object = FUN_00cbc5a0(D_5945a38, D_5946cb0, Name(), 0);
        break;
    case 2:
        object = FUN_00cbc5a0(D_5945a38, D_5946cc8, Name(), 0);
        break;
    case 3:
        object = FUN_00cbc5a0(D_5945a38, D_5946d10, Name(), 0);
        break;
    default:
        return nullptr;
    }
    FUN_00cf8120(object);
    return object;
}
