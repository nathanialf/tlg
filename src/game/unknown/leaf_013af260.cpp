/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00d0cc60 with the object, the address of entry i
 * (0x28 bytes each) of the array its second argument points to, and its fourth
 * argument, as a tail call; slot 3 of the vtable at 0x16d1c38 (its pointer at
 * 0x16d1c60). FUN_00d0cc60 is reached the same way by FUN_01354940,
 * FUN_0139ecf0 and FUN_013af260 with other entry sizes. The types are not
 * traced. Class and method unknown. */
struct Object013af260; /* derived name */

struct Entry013af260 { /* derived name */
    u8 unknown0[0x28];
};

struct Array013af260 { /* derived name */
    Entry013af260 *unknown0;
};

void FUN_00d0cc60(Object013af260 *self, void *entry, void *argument); /* derived name */

// NONMATCHING: scheduling of the outgoing copy rdx = rcx against the two scaled-index leas (base: copy first, the loaded pointer in rsi, the index in rax; compiled: copy last, the pointer in rax); the same body with an imul scale (FUN_01354940) is equal
void FUN_013af260(Object013af260 *self, Array013af260 *array, int i,
                  void *argument) /* derived name */
{
    FUN_00d0cc60(self, &array->unknown0[i], argument);
}
