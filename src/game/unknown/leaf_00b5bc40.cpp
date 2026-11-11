/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b6b10 (+0x48 from the vtable stored at
 * 0x16b6ac8): sets the float at +0x11c to 2 when the int at +0x54 is 2, to 0.5
 * when it is 0, and the float at +0x84 to 99999. The class is not traced. */
struct Object00b5bc40 { /* derived name */
    u8 unknown0[0x54];
    int unknown54;
    u8 unknown58[0x2c];
    float unknown84;
    u8 unknown88[0x94];
    float unknown11c;
};

// NONMATCHING: the two stores to +0x11c sunk into one store of a phi (the constants then loaded, SimplifyCFG's sinking of common code with differing operands, new in 4.0) where the base keeps the two immediate stores and duplicates the +0x84 store into the 0 arm: a compiler-history candidate, not tested
void FUN_00b5bc40(Object00b5bc40 *self) /* derived name */
{
    if (self->unknown54 == 2) {
        self->unknown11c = 2.0f;
    } else if (self->unknown54 == 0) {
        self->unknown11c = 0.5f;
    }
    self->unknown84 = 99999.0f;
}
