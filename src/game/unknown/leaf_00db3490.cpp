/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 138 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb520, beside FUN_00db3680, slot 137): FUN_00db3300 resolves its third argument
 * into an index (-1 when it finds none) and a pointer (null), FUN_00daba60
 * takes the second argument, the int at +0xf60 of the record the pointer at
 * +0x7dc8 holds, the index and the pointer, and the int is raised after.
 * Class and method unknown; the arguments' types are not traced. */
struct Owner00db3490 { /* derived name */
    u8 unknown0[0xf60];
    int unknownf60; /* +0xf60 */
};

struct Object00db3490 { /* derived name */
    u8 unknown0[0x7dc8];
    Owner00db3490 *unknown7dc8;
};

void FUN_00db3300(Object00db3490 *self, void *name, int *index, void **found); /* derived name */
void FUN_00daba60(Object00db3490 *self, void *target, int count, int index,
                  void *found); /* derived name */

// NONMATCHING: instruction order (list-ilp): the base loads the index (ecx) before the pointer (r8) for the call, the build after (as FUN_00db3680)
void FUN_00db3490(Object00db3490 *self, void *target, void *name) /* derived name */
{
    int index = -1;
    void *found = 0;
    FUN_00db3300(self, name, &index, &found);
    FUN_00daba60(self, target, self->unknown7dc8->unknownf60, index, found);
    self->unknown7dc8->unknownf60++;
}
