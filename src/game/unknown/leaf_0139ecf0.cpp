/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00d0cc60 with the object, the address of entry i
 * (0xc bytes each) of the array its second argument points to, and its fourth
 * argument, as a tail call; slot 3 of the vtable at 0x16d0298 (its pointer at
 * 0x16d02c0). FUN_00d0cc60 is reached the same way by FUN_01354940,
 * FUN_0139ecf0 and FUN_013af260 with other entry sizes. The types are not
 * traced. Class and method unknown. */
struct Object0139ecf0; /* derived name */

struct Entry0139ecf0 { /* derived name */
    u8 unknown0[0xc];
};

struct Array0139ecf0 { /* derived name */
    Entry0139ecf0 *unknown0;
};

void FUN_00d0cc60(Object0139ecf0 *self, void *entry, void *argument); /* derived name */

void FUN_0139ecf0(Object0139ecf0 *self, Array0139ecf0 *array, int i,
                  void *argument) /* derived name */
{
    FUN_00d0cc60(self, &array->unknown0[i], argument);
}
