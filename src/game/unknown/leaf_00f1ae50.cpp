/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the name string "boyA_pa" at 0x15c50d3; slot 7 of the
 * vtable at 0x16bee10 (its pointer at 0x16bee58), the vtable stored by
 * FUN_00f1ac10 FUN_00f1afc0. The string is referenced as the read-only data it
 * is (docs/DECISIONS.md D8 addendum: its text is not copied; the GOT load
 * becomes the base's lea under D10). Class and method unknown. */
extern const char D_15c50d3[];

struct Object00f1ae50;

const char *FUN_00f1ae50(const Object00f1ae50 *self) /* derived name */
{
    return D_15c50d3;
}
