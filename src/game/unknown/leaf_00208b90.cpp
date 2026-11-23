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

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 1 rowed caller where the base calls it (round 513D: cause not found;
 * not its address range, its callers' count, its cost or its unit: a single block, cost 0 under
 * the link's threshold of 262 with its bonuses, and with it outside the module every row holds) */
void FUN_00208b90(Object0020d4b0 *self, float ax, float ay, float az, float bx, float by,
                  float bz) /* derived name */
{
    FUN_0020d4b0(self, ax, ay, az, bx, by, bz);
}
