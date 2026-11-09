/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the pointer at +0x1d18, a pointer to a
 * record with a reference count at +0x8. FUN_00f501f0 (and five more sites)
 * passes it to FUN_00f53a70 passes its address (lea at 0xf504a3) as the getter
 * beside the setter FUN_013cfaa0, which swaps the pointer in with lock
 * cmpxchg, increments the new record's count and decrements the old one's
 * (both after testing for 0xdeadc0de); the getter's parameter is the record
 * the setter adjusts. Owner and meaning unknown. */
struct Counted013cfb60 { /* derived name */
    u8 unknown0[8];
    int count; /* the setters test it against 0xdeadc0de, the released mark, before they change it */
};

struct Object013cfb60 { /* derived name */
    u8 unknown0[0x1d18];
    Counted013cfb60 *unknown1d18; /* its address returned by FUN_013cfb60, stored by FUN_013cfaa0 */
    Counted013cfb60 *unknown1d20; /* its address returned by FUN_013cfc30, stored by FUN_013cfb70 */
    Counted013cfb60 *unknown1d28; /* its address returned by FUN_013cfd00, stored by FUN_013cfc40 */
    Counted013cfb60 *unknown1d30; /* its address returned by FUN_013cfdd0, stored by FUN_013cfd10 */
    Counted013cfb60 *unknown1d38; /* its address returned by FUN_013dd790, stored by FUN_013df0c0 */
    Counted013cfb60 *unknown1d40; /* its address returned by FUN_013dd7a0, stored by FUN_013df180 */
    Counted013cfb60 *unknown1d48; /* its address returned by FUN_013dd7b0, stored by FUN_013df240 */
    Counted013cfb60 *unknown1d50; /* its address returned by FUN_013dd7c0, stored by FUN_013df300 */
};

Counted013cfb60 **FUN_013cfb60(Object013cfb60 *self) /* derived name */
{
    return &self->unknown1d18;
}
