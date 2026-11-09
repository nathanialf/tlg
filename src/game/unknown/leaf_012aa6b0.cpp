/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the name string "condorArmorA_pa" at 0x15ca3bf; slot
 * 7 of the vtable at 0x16c3258 (its pointer at 0x16c32a0), the vtable stored
 * by FUN_012aa470 FUN_012aa820. The string is referenced as the read-only data
 * it is (docs/DECISIONS.md D8 addendum: its text is not copied; the GOT load
 * becomes the base's lea under D10). Class and method unknown. */
extern const char D_15ca3bf[];

struct Object012aa6b0;

const char *FUN_012aa6b0(const Object012aa6b0 *self) /* derived name */
{
    return D_15ca3bf;
}
