/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes its two arguments to FUN_00c08c00, FUN_00c07990 and
 * FUN_00c08630 in turn and returns 0; stored at +0x8 of an entry of the
 * 0x60-byte table records FUN_00c0bd50 and FUN_00c0c0b0 fill (lea at 0xc0bff5
 * and 0xc0c55f). The parameters' types and the callees' return types are not
 * traced. */
struct Object00c08c00;   /* derived name */
struct Argument00c08c00; /* derived name */

void FUN_00c08c00(Object00c08c00 *object, Argument00c08c00 *argument); /* derived name */
void FUN_00c07990(Object00c08c00 *object, Argument00c08c00 *argument); /* derived name */
void FUN_00c08630(Object00c08c00 *object, Argument00c08c00 *argument); /* derived name */

int FUN_00c095e0(Object00c08c00 *object, Argument00c08c00 *argument) /* derived name */
{
    FUN_00c08c00(object, argument);
    FUN_00c07990(object, argument);
    FUN_00c08630(object, argument);
    return 0;
}
