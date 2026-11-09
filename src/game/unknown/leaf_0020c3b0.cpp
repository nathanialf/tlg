/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_0020d740 as a tail call, the
 * only reference to that function, which follows it in the file at +0x1390;
 * 125 call sites. FUN_0020d740 passes scaled floats to the unnamed import
 * ZtjspkJQ+vw (first argument 0, then 1) and stores four floats at +0x0 to
 * +0xc. The shape of a complete-object constructor delegating to the base-
 * object one, emitted on its own as clang 3.3 does for a linkonce definition
 * (NOTES, rounds 74A and 73B on 0x195fe0); written as a free function on that
 * object until the class is modelled. */
struct Object0020d740; /* derived name */

void FUN_0020d740(Object0020d740 *self, float x, float y, float z); /* derived name */

void FUN_0020c3b0(Object0020d740 *self, float x, float y, float z) /* derived name */
{
    FUN_0020d740(self, x, y, z);
}
