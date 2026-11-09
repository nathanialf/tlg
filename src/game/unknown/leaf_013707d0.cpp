/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_013707e0, which writes the
 * quaternion for a rotation of the given angle in degrees (scaled by pi/360,
 * 0.0087266) about the Z axis: the results of import 0x14b03b8 for selectors 0
 * and 1 (a sine and cosine pair by their use) at +8 and +0xc, zeros elsewhere.
 * Called directly from 10 sites; no value returned. */
struct Quaternion; /* derived name */

void FUN_013707e0(Quaternion *out, float degrees); /* derived name */

void FUN_013707d0(Quaternion *out, float degrees) /* derived name */
{
    FUN_013707e0(out, degrees);
}
