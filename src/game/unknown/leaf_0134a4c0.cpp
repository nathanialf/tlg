/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: the setters of the three Names at +0x54c, +0x544 and +0x548
 * (Name's assignment, inlined), each held in 17 vtable slots, the three
 * side by side (the second and third adjacent, the first six before); the
 * field layout of leaf_0134a430.cpp's siblings. Class and methods unknown. */
void FUN_0134a4c0(Object0134a660 *self, const Name &name) /* derived name */
{
    self->name54c = name;
}

void FUN_0134a580(Object0134a660 *self, const Name &name) /* derived name */
{
    self->name544 = name;
}

void FUN_0134a5f0(Object0134a660 *self, const Name &name) /* derived name */
{
    self->name548 = name;
}

/* derived names: the setter of the Name at +0x540, which also sets bit 4 of
 * the byte at +0x20 (as the setters of the words at +0x4f4 to +0x50c do),
 * whether or not the name changed. */
void FUN_0134a450(Object0134a660 *self, const Name &name) /* derived name */
{
    self->name540 = name;
    self->unknown20 |= 0x10;
}
