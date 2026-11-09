/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback that passes its argument on to FUN_010d4220 as a
 * tail call; FUN_010c79e0 stores its address at 0x58235b0 beside the values it
 * stores at 0x58235c0 to 0x58235d0 before setting an event flag (a request for
 * another thread). The record is the one FUN_010d4220 works on (a pointer at
 * +0x0, ints at +0x8 and +0xc); the return type is not traced. */
struct Object010d4220; /* derived name */

void FUN_010d4220(Object010d4220 *self); /* derived name */

void FUN_010d48d0(Object010d4220 *self) /* derived name */
{
    FUN_010d4220(self);
}
