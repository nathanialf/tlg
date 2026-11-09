/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback; FUN_012d3850 stores its address at 0x58235b0
 * among the fields of a global record and then calls sceKernelSetEventFlag,
 * and calls FUN_012e0090 directly on the same kind of record (a pointer at
 * +0x0, ints at +0x8 and +0xc). It passes its argument on as a tail call; the
 * callback's exact type is not traced. */
struct Object012e0090; /* derived name */

void FUN_012e0090(Object012e0090 *work); /* derived name */

void FUN_012e0740(Object012e0090 *work) /* derived name */
{
    FUN_012e0090(work);
}
