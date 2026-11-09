/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback that calls FUN_0058dae0 with its two arguments and
 * returns 0. FUN_00525530 stores its address (lea at 0x525852) into a table of
 * callbacks in the object it builds (four pointers at a time, by 32-byte
 * vector stores); the neighbouring callbacks take the same two pointers
 * (FUN_0058da20 reads +0x38 and +0x2c of the second and returns 0).
 * FUN_0058dae0 keeps both (movq rdi, rsi); the types are not traced. Owner and
 * meaning unknown. */
struct Object0058dae0;   /* derived name */
struct Argument0058dae0; /* derived name */

void FUN_0058dae0(Object0058dae0 *self, Argument0058dae0 *argument); /* derived name */

int FUN_0058da00(Object0058dae0 *self, Argument0058dae0 *argument) /* derived name */
{
    FUN_0058dae0(self, argument);
    return 0;
}
