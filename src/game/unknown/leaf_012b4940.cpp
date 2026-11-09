/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the name string "condor_lw_A_pa" at 0x15ca43f; slot 7
 * of the vtable at 0x16c33b8 (its pointer at 0x16c3400), the vtable stored by
 * FUN_012b4700 FUN_012b4ab0. The string is referenced as the read-only data it
 * is (docs/DECISIONS.md D8 addendum: its text is not copied; the GOT load
 * becomes the base's lea under D10). Class and method unknown. */
extern const char D_15ca43f[];

struct Object012b4940;

const char *FUN_012b4940(const Object012b4940 *self) /* derived name */
{
    return D_15ca43f;
}
