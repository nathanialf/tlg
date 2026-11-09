/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of the global object at 0x581bda0,
 * registered with __cxa_atexit by FUN_0082f0e0; its own body is empty, so the
 * destructor of its base or first member, FUN_0134f620 (which frees the
 * pointers in the array at +0x0 counted by the int at +0x8, 683 call sites),
 * runs as a tail call. Written as a free function on that record, as the
 * derived complete destructors are. */
struct Object0134f620; /* derived name */

void FUN_0134f620(Object0134f620 *self); /* derived name */

void FUN_0136fe60(Object0134f620 *self) /* derived name */
{
    FUN_0134f620(self);
}
