/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the name string "condorATail_pa" at 0x15ca2af; slot 7
 * of the vtable at 0x16c3078 (its pointer at 0x16c30c0), the vtable stored by
 * FUN_0129a790 FUN_0129ab40. The string is referenced as the read-only data it
 * is (docs/DECISIONS.md D8 addendum: its text is not copied; the GOT load
 * becomes the base's lea under D10). Class and method unknown. */
extern const char D_15ca2af[];

struct Object0129a9d0;

const char *FUN_0129a9d0(const Object0129a9d0 *self) /* derived name */
{
    return D_15ca2af;
}
