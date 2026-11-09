/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of the global objects at 0x59497d0,
 * 0x5949800 and 0x59497e8 (the int at +0x10 of each set from the thread record
 * at fs:0 before registration, +0x14 zeroed), registered with __cxa_atexit by
 * FUN_00d667c0; its own body is empty, so the destructor of its base or first
 * member, FUN_0134f620 (which frees the pointers in the array at +0x0 counted
 * by the int at +0x8), runs as a tail call. Written as a free function on that
 * record, as round 107A's FUN_0136fe60 and FUN_01384a30 are. */
struct Object0134f620; /* derived name */

void FUN_0134f620(Object0134f620 *self); /* derived name */

void FUN_013baac0(Object0134f620 *self) /* derived name */
{
    FUN_0134f620(self);
}
