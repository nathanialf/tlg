/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_008506c0 registers under "footstep_fx_walk_up"
 * (its id the FUN_013bad90 hash of the string; lea at 0x850a5a): passes its
 * second and third arguments, the string "walk_up", its fourth and fifth
 * arguments, 0 and 0 (the last on the stack) to FUN_008540e0 and returns 1.
 * The first argument is not read; the parameters' types and the callee's
 * return type are not traced. */
struct Object008574a0;   /* derived name */
struct Argument008574a0; /* derived name */

void FUN_008540e0(Argument008574a0 *argument, void *second, const char *name, void *third,
                  void *fourth, void *fifth, int value); /* derived name */

int FUN_00857620(Object008574a0 *, Argument008574a0 *argument, void *second, void *third,
                 void *fourth) /* derived name */
{
    FUN_008540e0(argument, second, "walk_up", third, fourth, 0, 0);
    return 1;
}
