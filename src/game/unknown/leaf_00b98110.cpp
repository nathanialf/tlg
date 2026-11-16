/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: slot 15 of the vtable at 0x16b7148 (its pointer at
 * 0x16b71c0, the class Object016b7148 of config/vtables.derived.base.txt):
 * the place of a cell in a square of n by n cells (n at +0x3d0, the cell's
 * running number at +0x3d8 taken modulo n * n) as twice its column over the
 * grid's width times n and twice its row over the grid's height times n, the
 * grid's sizes unsigned (+0x84 and +0x88 of the object at +0x3de8); zero
 * without a grid. Class and method unknown. */
struct Grid00b98110 { /* derived name */
    u8 unknown0[0x84];
    u32 width;  /* +0x84, derived name */
    u32 height; /* +0x88, derived name */
};

struct Object00b98110 { /* derived name */
    u8 unknown0[0x3d0];
    int cells; /* +0x3d0, derived name: n */
    u8 unknown3d4[0x4];
    int cell; /* +0x3d8, derived name */
    u8 unknown3dc[0x3de8 - 0x3dc];
    Grid00b98110 *grid; /* +0x3de8, derived name */
};

// NONMATCHING: the base keeps two returns (the null arm one 16-byte zero store, the other x and y
// then `mov qword [rdi+8], 0`); the build sinks the two arms' stores into one tail with a phi of
// x and y (SimplifyCFG's sinking of the returned Float4's stores)
Float4 FUN_00b98110(const Object00b98110 *self) /* derived name */
{
    const Grid00b98110 *grid = self->grid;
    if (!grid)
        return Float4(0, 0, 0, 0);
    int n = self->cells;
    int cell = self->cell % (n * n);
    return Float4(2.0f * (cell % n) / (grid->width * n), 2.0f * (cell / n) / (grid->height * n), 0,
                  0);
}
