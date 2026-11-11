/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the second entry of a table of two callbacks at 0x57ac9c0 in
 * .data (its first FUN_00ed19c0; lea at 0xec577b and on in FUN_00ec4540):
 * passes the pointer at +0x0 of its argument, null skipped, to the function
 * the pointer at 0x57ad998 holds and returns 0. The pointer is the game's
 * object (stored at 0xeb467b, called from nine sites from 0xeb5990), declared
 * here and defined by the game module's stand-in: the base calls through it
 * PC-relative (`call [rip]`). The types are not traced. */
struct Object00ed1a20 { /* derived name */
    void *unknown0;
};

extern void (*D_57ad998)(void *pointer);

int FUN_00ed1a20(Object00ed1a20 *self) /* derived name */
{
    if (self->unknown0)
        D_57ad998(self->unknown0);
    return 0;
}
