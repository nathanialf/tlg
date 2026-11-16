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

// NONMATCHING: 2/44 (round 365B, whole module, 110 bytes against 137; the three below the same).
// (1) the base loads the object's flags (`movzx r15d, word [r14+0x16]`) before the thread
// flag's address is taken (the general-dynamic call, hence r15 and the frame's `push rax`) and
// tests the thread's flag as `mov al, [rax]; xor al, 1; test al, 1; jne`: one condition split
// late, both tests in its block; the build takes the address first, then `test byte
// [r14+0x16], 4` and `test byte [rax], 1; je`. (2) the type walk: the base enters the loop at
// the parent's load and tests the found object for null again after it. With the flag read
// through threadMayUse() the address is taken in the second test's block (`movzx; and 1; cmp 1`).
int FUN_00858390(void *, const Object00858390 *self) /* derived name */
{
    Named00858390 *named = findNamed<Named00858390>(self->name14, D_598a010);
    if (named)
        named->flags41 |= 8;
    return 1;
}

/* derived names: the same, clearing the flag */
int FUN_00858420(void *, const Object00858390 *self) /* derived name */
{
    Named00858390 *named = findNamed<Named00858390>(self->name14, D_598a010);
    if (named)
        named->flags41 &= ~8;
    return 1;
}

/* derived names: the object of the type D_5938af0 points to, with flags at
 * +0x240: bit 0 set by FUN_00858270, bit 1 by FUN_00858300 */
struct Named00858270 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16;              /* +0x16 */
    const Type00503fb0 *type; /* +0x18 */
    u8 unknown20[0x220];
    u8 flags240; /* +0x240 */
};

extern const Type00503fb0 *D_5938af0; /* derived name */

int FUN_00858270(void *, const Object00858390 *self) /* derived name */
{
    Named00858270 *named = findNamed<Named00858270>(self->name14, D_5938af0);
    if (named)
        named->flags240 |= 1;
    return 1;
}

int FUN_00858300(void *, const Object00858390 *self) /* derived name */
{
    Named00858270 *named = findNamed<Named00858270>(self->name14, D_5938af0);
    if (named)
        named->flags240 |= 2;
    return 1;
}
