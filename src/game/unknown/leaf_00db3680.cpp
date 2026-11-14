/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 137 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb518; the family of FUN_00daff10): FUN_00db3300 resolves its third
 * argument into an index (-1 when it finds none) and a pointer (null), the
 * 16-bit count at +0xe of the record the pointer at +0x1798 of the record at
 * +0x7dc8 holds is raised, and FUN_00daba60 takes the second argument, the
 * count before the raise, the index and the pointer. Class and method
 * unknown; the arguments' types are not traced. */
struct Record00db3680 { /* derived name */
    u8 unknown0[0xe];
    unsigned short unknowne; /* +0xe */
};

struct Owner00db3680 { /* derived name */
    u8 unknown0[0x1798];
    Record00db3680 *unknown1798;
};

struct Object00db3680 { /* derived name */
    u8 unknown0[0x7dc8];
    Owner00db3680 *unknown7dc8;
};

void FUN_00db3300(Object00db3680 *self, void *name, int *index, void **found); /* derived name */
void FUN_00daba60(Object00db3680 *self, void *target, int count, int index,
                  void *found); /* derived name */

void FUN_00db3680(Object00db3680 *self, void *target, void *name) /* derived name */
{
    int index = -1;
    void *found = 0;
    FUN_00db3300(self, name, &index, &found);
    unsigned short count = self->unknown7dc8->unknown1798->unknowne++;
    FUN_00daba60(self, target, count, index, found);
}
