/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00a8e580
 * as a tail call; slot 21 of the vtable at 0x16a8430 (stored by FUN_002f9860
 * FUN_002fed80). FUN_00a8e580 takes the float in xmm0 saved at entry. The
 * record is the one FUN_00a8e580 works on; the return type is not traced. */
struct Object00a8e580; /* derived name */

void FUN_00a8e580(Object00a8e580 *self, float value); /* derived name */

void FUN_0030d480(Object00a8e580 *self, float value) /* derived name */
{
    FUN_00a8e580(self, value);
}
