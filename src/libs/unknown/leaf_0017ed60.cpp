/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtables at 0x16a6180 and 0x16a6200 (a
 * reference-counted class and its base, built at 0x17e9c5 and 0x184f60)
 * stores the string pointer at +0x10, which their constructors set to the
 * Havok version string "hk_2014.2.0-r1" and slot 5 (FUN_00007f80) reads.
 * The same body fills slot 7 of two game vtables (0x16bc0b0, 0x16bc118). */
struct Versioned0017ed60 {
    u8 unknown0[0x10];
    const char *version;
};

void FUN_0017ed60(Versioned0017ed60 *self, const char *version) /* derived name */
{
    self->version = version;
}
