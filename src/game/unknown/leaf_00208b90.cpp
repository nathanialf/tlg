/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_0020d4b0 as a tail call, the
 * only reference to that function, which follows it in the file at +0x4920;
 * 311 call sites. FUN_0020d4b0 takes the object and two vectors of three
 * floats. The shape of a complete-object constructor delegating to the base-
 * object one, emitted on its own as clang 3.3 does for a linkonce definition
 * (NOTES, rounds 74A and 73B on 0x195fe0); written as a free function on that
 * object until the class is modelled. */
struct Object0020d4b0; /* derived name */

void FUN_0020d4b0(Object0020d4b0 *self, float ax, float ay, float az, float bx, float by,
                  float bz); /* derived name */

void FUN_00208b90(Object0020d4b0 *self, float ax, float ay, float az, float bx, float by,
                  float bz) /* derived name */
{
    FUN_0020d4b0(self, ax, ay, az, bx, by, bz);
}
