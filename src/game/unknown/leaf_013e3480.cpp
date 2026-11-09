/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00fb0cf0 (slot 7 of the same vtables, called
 * directly) with the object, its pointer argument, 1 and its int argument, as
 * a tail call; slot 8 of the vtable at 0x16d4790 (its pointer at 0x16d47e0),
 * the vtable stored by FUN_00fbac70; slot 8 of the vtable at 0x16d47e8 (its
 * pointer at 0x16d4838), the vtable stored by FUN_00fbac70. FUN_00fb0cf0 keeps
 * the pointer (movq rsi) and sign-extends the third (movslq edx). The types
 * and the return type are not traced. Class and method unknown. */
struct Object013e3480; /* derived name */

void FUN_00fb0cf0(Object013e3480 *self, void *value, int flag, int count); /* derived name */

void FUN_013e3480(Object013e3480 *self, void *value, int count) /* derived name */
{
    FUN_00fb0cf0(self, value, 1, count);
}
