/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the name string "condorA_pa" at 0x15c6b41; slot 7 of
 * the vtable at 0x16c11e0 (its pointer at 0x16c1228), the vtable stored by
 * FUN_01068970 FUN_01068d20. The string is referenced as the read-only data it
 * is (docs/DECISIONS.md D8 addendum: its text is not copied; the GOT load
 * becomes the base's lea under D10). Class and method unknown. */
extern const char D_15c6b41[];

struct Object01068bb0;

const char *FUN_01068bb0(const Object01068bb0 *self) /* derived name */
{
    return D_15c6b41;
}
