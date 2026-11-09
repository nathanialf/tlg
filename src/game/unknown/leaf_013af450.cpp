/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the entry its int argument indexes in
 * the array of 40-byte entries the pointer at +0x0 of its second argument
 * holds; the first argument is unused (slot 8 beside it hands out the next
 * entry of an array in the object); slot 7 of the vtable at 0x16d1c38 (its
 * pointer at 0x16d1c80), the vtable stored by FUN_00cd5ca0 FUN_013af5c0. Class
 * and method unknown. */
struct Entry013af450 { /* derived name */
    u8 unknown0[40];
};

struct Array013af450 { /* derived name */
    Entry013af450 *unknown0;
};

struct Object013af450; /* derived name */

Entry013af450 *FUN_013af450(Object013af450 *, const Array013af450 *array,
                            int index) /* derived name */
{
    return &array->unknown0[index];
}
