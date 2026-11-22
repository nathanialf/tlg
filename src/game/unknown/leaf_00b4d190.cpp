/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: gives the object's name at +0x240 the name of the object
 * it is handed, or releases it when it is handed none; called by
 * FUN_00b51aa0. The field's meaning is not traced. */
struct Object00b4d190 { /* derived name */
    u8 unknown0[0x240];
    Name name240; /* +0x240 */
};

void FUN_00b4d190(Object00b4d190 *self, const Object016b9108 *object) /* derived name */
{
    if (object)
        self->name240 = object->name;
    else
        self->name240.release();
}
