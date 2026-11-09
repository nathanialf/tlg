/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: one of six functions FUN_004acae0 stores the address of (lea
 * at 0x4ace70; FUN_004ad600 to FUN_004ad690 pass 0 to 4 and -1): calls
 * FUN_004aba80 with its second argument, the object and 3, as a tail call. The
 * types and the return type are not traced. Class and method unknown. */
struct Object004ad600; /* derived name */
struct Target004ad600; /* derived name */

void FUN_004aba80(Target004ad600 *target, Object004ad600 *object, int); /* derived name */

void FUN_004ad650(Object004ad600 *self, Target004ad600 *target) /* derived name */
{
    FUN_004aba80(target, self, 3);
}
