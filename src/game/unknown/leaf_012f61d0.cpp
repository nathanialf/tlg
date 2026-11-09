/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the name string "condorEndingA_pa" at 0x15cb435; slot
 * 7 of the vtable at 0x16c36b8 (its pointer at 0x16c3700), the vtable stored
 * by FUN_012f5f90 FUN_012f6340. The string is referenced as the read-only data
 * it is (docs/DECISIONS.md D8 addendum: its text is not copied; the GOT load
 * becomes the base's lea under D10). Class and method unknown. */
extern const char D_15cb435[];

struct Object012f61d0;

const char *FUN_012f61d0(const Object012f61d0 *self) /* derived name */
{
    return D_15cb435;
}
