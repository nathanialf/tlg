/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slots 9 and 10 (one body) of the vtables at 0x16caee0
 * (stored by FUN_005114e0 FUN_01354780 FUN_01354f30), 0x16d0298 (stored by
 * FUN_00bf9780 FUN_013a05f0) and 0x16d1c38 (stored by FUN_00cd5ca0
 * FUN_013af5c0): returns the address of the array of 12-byte entries at +0x14.
 * Slot 8 (FUN_0139eee0) returns the entry at the count, the int at +0x10, and
 * increments it. The entries' fields and the array's length are not traced;
 * the two slots may be a const and a non-const accessor. */
struct Entry0139ef00 /* derived name */
{
    u8 unknown0[0xc];
};

struct Object0139ef00 /* derived name */
{
    u8 unknown0[0x10];
    int count;                /* +0x10 */
    Entry0139ef00 entries[1]; /* +0x14, length not traced */
};

Entry0139ef00 *FUN_0139ef00(Object0139ef00 *self) /* derived name */
{
    return self->entries;
}
