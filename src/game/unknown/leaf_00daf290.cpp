/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00daba60 with the object, its second argument, 3,
 * -1 and 0 (32-bit), as a tail call. The types and the return type are not
 * traced; slot 27 of the vtable at 0x16bb0c0 (its pointer at 0x16bb1a8), the
 * vtable stored by FUN_00da4250 FUN_00ddbb60 | home BytecodeReader.cpp. Class
 * and method unknown. */
struct Object00daf290; /* derived name */

void FUN_00daba60(Object00daf290 *self, void *argument, int, int, int); /* derived name */

void FUN_00daf290(Object00daf290 *self, void *argument) /* derived name */
{
    FUN_00daba60(self, argument, 3, -1, 0);
}
