/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets flag 8 at +0x41 of the object the name at +0x14 of the
 * second argument names, when it is of the type D_598a010 points to; returns
 * 1. The first argument is not read. The classes are not traced. */
struct Named00858390 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16;              /* +0x16 */
    const Type00503fb0 *type; /* +0x18 */
    u8 unknown20[0x21];
    u8 flags41; /* +0x41 */
};

struct Object00858390 { /* derived name */
    u8 unknown0[0x14];
    Name name14; /* +0x14 */
};

extern const Type00503fb0 *D_598a010; /* derived name */

// NONMATCHING: 2/44. (1) the base tests the object's flag 4 first (the flags
// loaded with `movzx r15d, word` before the thread flag's address is taken),
// then the thread's flag (`mov al; xor al, 1; test al, 1`); the build's `or`
// of the two has the thread's flag first (Reassociate runs after the flag is
// one bit: its load ranks below the mask's compare; with the flag still a
// byte at Reassociate the two tie and the source's order stays). (2) the type
// walk: the base compares the object's own type before the loop and enters
// at the parent's load (the parked loop class), and tests the found object
// for null again after the loop.
int FUN_00858390(void *, const Object00858390 *self) /* derived name */
{
    Named00858390 *named = findNamed<Named00858390>(self->name14, D_598a010);
    if (named)
        named->flags41 |= 8;
    return 1;
}
