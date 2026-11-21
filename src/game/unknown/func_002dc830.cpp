/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_slot9.h"
#include "tlg_math.h"

/* derived names: FUN_002dc830 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 3 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15638ce[19];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57cbc40(D_15cb5dd, false);
Name D_57cbc44(D_15cb5e6, false);
Name D_57cbb1c(D_15638ce, false);

/* derived names: slot 9 of the vtable at 0x16a8178 (its pointer at
 * 0x16a81d0; the class of leaf_002dc440.cpp, named for the vtable): runs
 * FUN_0042d4e0 on the object, empties the names at +0x110, +0x114, +0x148 and
 * +0x14c, clears the int at +0x118 and the vector at +0x120, and sets the
 * four floats at +0x130 to this file's z axis (VECTOR_Z, read as two
 * eight-byte halves and stored lane by lane). */
struct Object016a8178 : Object0042d4e0 /* derived name */
{
    u8 unknown0[0x110];
    Name name110;   /* +0x110 */
    Name name114;   /* +0x114 */
    int unknown118; /* +0x118 */
    u8 unknown11c[4];
    Float4A unknown120; /* +0x120 */
    Float4 unknown130;  /* +0x130 */
    u8 unknown140[8];
    Name name148; /* +0x148 */
    Name name14c; /* +0x14c */
};

void FUN_002dbe30(Object016a8178 *self) /* derived name */
{
    FUN_0042d4e0(self);
    self->name110 = Name();
    self->name114 = Name();
    self->unknown118 = 0;
    self->unknown120 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
    self->unknown130 =
        Float4(lane(VECTOR_Z.v, 0), lane(VECTOR_Z.v, 1), lane(VECTOR_Z.v, 2), lane(VECTOR_Z.v, 3));
    self->name148 = Name();
    self->name14c = Name();
}
