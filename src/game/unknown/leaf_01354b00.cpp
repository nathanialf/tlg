/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the entry its third argument indexes
 * (signed) in the array of 0x1c-byte entries the pointer at +0x0 of its second
 * argument points to; slot 7 of the vtable at 0x16caee0 (its pointer at
 * 0x16caf28), the vtable stored by FUN_005114e0 FUN_01354780 FUN_01354f30. The
 * first argument (the object) is not used; the entry's fields are not traced.
 * Class and method unknown. */
struct Object01354b00; /* derived name */

struct Entry01354b00 { /* derived name */
    u8 unknown0[0x1c];
};

struct Array01354b00 { /* derived name */
    Entry01354b00 *entries;
};

Entry01354b00 *FUN_01354b00(Object01354b00 *, const Array01354b00 *array,
                            int index) /* derived name */
{
    return &array->entries[index];
}
