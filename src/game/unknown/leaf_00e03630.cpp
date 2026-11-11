/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes its two arguments to FUN_00c08c00, FUN_00c07eb0 and
 * FUN_00c08630 in turn and returns 0; stored by FUN_00c10900 (lea at
 * 0xc10a5f), as FUN_00c095e0 is. The parameters' types and the callees' return
 * types are not traced. */
struct Object00c08c00;   /* derived name */
struct Argument00c08c00; /* derived name */

void FUN_00c08c00(Object00c08c00 *object, Argument00c08c00 *argument); /* derived name */
void FUN_00c07eb0(Object00c08c00 *object, Argument00c08c00 *argument); /* derived name */
void FUN_00c08630(Object00c08c00 *object, Argument00c08c00 *argument); /* derived name */

int FUN_00e03630(Object00c08c00 *object, Argument00c08c00 *argument) /* derived name */
{
    FUN_00c08c00(object, argument);
    FUN_00c07eb0(object, argument);
    FUN_00c08630(object, argument);
    return 0;
}
