/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the slot of the vtable at 0x16bb288 (no class yet): passes
 * its second argument, the int at +0xf60 of the record its pointer at +0x7dc8
 * holds, -1 and 0 to FUN_00daba60, then increments that int. The arguments'
 * types are not traced. */
struct Record00daba20_7dc8 /* derived name */
{
    u8 unknown0[0xf60];
    int unknownF60; /* +0xf60 */
};

struct Object00daba20 /* derived name */
{
    u8 unknown0[0x7dc8];
    Record00daba20_7dc8 *unknown7dc8; /* +0x7dc8 */
};

void FUN_00daba60(Object00daba20 *self, void *argument, int count, int limit,
                  int flag); /* derived name */

void FUN_00daba20(Object00daba20 *self, void *argument) /* derived name */
{
    FUN_00daba60(self, argument, self->unknown7dc8->unknownF60, -1, 0);
    ++self->unknown7dc8->unknownF60;
}
