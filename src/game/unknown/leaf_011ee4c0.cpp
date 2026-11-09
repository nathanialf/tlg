/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the name string "soldierA_pa" at 0x15c8e00; slot 7 of
 * the vtable at 0x16c1c30 (its pointer at 0x16c1c78), the vtable stored by
 * FUN_011ee280 FUN_011ee630. The string is referenced as the read-only data it
 * is (docs/DECISIONS.md D8 addendum: its text is not copied; the GOT load
 * becomes the base's lea under D10). Class and method unknown. */
extern const char D_15c8e00[];

struct Object011ee4c0;

const char *FUN_011ee4c0(const Object011ee4c0 *self) /* derived name */
{
    return D_15c8e00;
}
