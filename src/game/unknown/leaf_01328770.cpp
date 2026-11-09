/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the 16 bytes its second argument points to over its
 * first (vmovups); its pointer at 0x16c5540 is in a table of function pointers
 * (0x16c5500 to 0x16c5580 all functions, 0x1327b60 to 0x1328ef0), counted from
 * the vtable at 0x16c3c80 stored by FUN_01325f10 FUN_01326700 it would be slot
 * 790. The record's type is not traced. */
struct Value01328770 { /* derived name */
    u8 unknown0[0x10];
};

void FUN_01328770(Value01328770 *destination, const Value01328770 *source) /* derived name */
{
    *destination = *source;
}
