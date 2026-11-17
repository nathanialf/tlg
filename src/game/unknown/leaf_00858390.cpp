/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets flag 8 at +0x41 of the object the name at +0x14 of the
 * second argument names, when it is of the type D_598a010 points to; returns
 * 1. The first argument is not read. The classes are not traced. */
struct Named00858390 : Object016b9108 /* derived name */
{
    u8 unknown24[0x1d];
    u8 flags41; /* +0x41 */
};

struct Object00858390 { /* derived name */
    u8 unknown0[0x14];
    Name name14; /* +0x14 */
};

extern const Type00503fb0 *D_598a010; /* derived name */

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
struct Named00858270 : Object016b9108 /* derived name */
{
    u8 unknown24[0x21c];
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
