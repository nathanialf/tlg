/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback that calls FUN_00c0e250 with its two arguments and
 * returns 0. FUN_00be6da0 stores its address (lea at 0xbe769e) into a table of
 * callbacks in the object it builds (four pointers at a time, by 32-byte
 * vector stores), as FUN_00525530 stores FUN_0058da00 and FUN_0058da10.
 * FUN_00c0e250 keeps both (movq rdi, rsi) and reads +0x28 of the second; the
 * types are not traced. Owner and meaning unknown. */
struct Object00c0e250;   /* derived name */
struct Argument00c0e250; /* derived name */

void FUN_00c0e250(Object00c0e250 *self, Argument00c0e250 *argument); /* derived name */

int FUN_00c0e240(Object00c0e250 *self, Argument00c0e250 *argument) /* derived name */
{
    FUN_00c0e250(self, argument);
    return 0;
}
