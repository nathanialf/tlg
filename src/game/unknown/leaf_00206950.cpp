/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_00206a90 as a tail call, the
 * only reference to that function, which follows it in the file at +0x140; 148
 * call sites, each passing a stack object and four floats. FUN_00206a90
 * normalizes the vector (x, y, z), scales the fourth float by pi/360 (half an
 * angle in degrees, as radians), passes it twice to the unnamed import
 * ZtjspkJQ+vw (first argument 0, then 1) and stores four floats at +0x0 to
 * +0xc. The shape of a complete-object constructor delegating to the base-
 * object one, emitted on its own as clang 3.3 does for a linkonce definition
 * (NOTES, rounds 74A and 73B on 0x195fe0); written as a free function on that
 * object until the class is modelled. */
struct Object00206a90; /* derived name */

void FUN_00206a90(Object00206a90 *self, float x, float y, float z, float angle); /* derived name */

void FUN_00206950(Object00206a90 *self, float x, float y, float z, float angle) /* derived name */
{
    FUN_00206a90(self, x, y, z, angle);
}
