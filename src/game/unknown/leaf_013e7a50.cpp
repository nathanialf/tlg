/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtables at 0x16d4be0, 0x16d4c20, 0x16d4c68 and
 * 0x16d4ca8: stores its pointer at +0x8 and three of its ints at +0x9c, +0xa0
 * and +0xa4, then passes the object and the remaining int to FUN_013e5560, as
 * a tail call. The types are not traced. Class and method unknown. */
struct Object013e7a50 { /* derived name */
    u8 unknown0[0x8];
    void *unknown8;
    u8 unknown10[0x8c];
    int unknown9c;
    int unknowna0;
    int unknowna4;
};

void FUN_013e5560(Object013e7a50 *self, int value); /* derived name */

void FUN_013e7a50(Object013e7a50 *self, void *pointer, int first, int value, int second,
                  int third) /* derived name */
{
    self->unknown8 = pointer;
    self->unknown9c = first;
    self->unknowna0 = second;
    self->unknowna4 = third;
    FUN_013e5560(self, value);
}
