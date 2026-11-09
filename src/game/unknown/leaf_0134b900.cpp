/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_0134bc00, which writes the
 * quaternion for a rotation of the given angle in degrees (scaled by pi/360,
 * 0.0087266) about the Y axis: the results of import 0x14b03b8 for selectors 0
 * and 1 (a sine and cosine pair by their use) at +4 and +0xc, zeros elsewhere.
 * Called directly from 83 sites; no value returned. */
struct Quaternion; /* derived name */

void FUN_0134bc00(Quaternion *out, float degrees); /* derived name */

void FUN_0134b900(Quaternion *out, float degrees) /* derived name */
{
    FUN_0134bc00(out, degrees);
}
