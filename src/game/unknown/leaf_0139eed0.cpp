/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the entry its int argument indexes in
 * the array of 12-byte entries the pointer at +0x0 of its second argument
 * holds; the first argument is unused (slot 8 beside it hands out the next
 * entry of an array in the object); slot 7 of the vtable at 0x16d0298 (its
 * pointer at 0x16d02e0), the vtable stored by FUN_00bf9780 FUN_013a05f0. Class
 * and method unknown. */
struct Entry0139eed0 { /* derived name */
    u8 unknown0[12];
};

struct Array0139eed0 { /* derived name */
    Entry0139eed0 *unknown0;
};

struct Object0139eed0; /* derived name */

Entry0139eed0 *FUN_0139eed0(Object0139eed0 *, const Array0139eed0 *array,
                            int index) /* derived name */
{
    return &array->unknown0[index];
}
