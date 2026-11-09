/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_01343600, which writes the
 * quaternion of the rotation in a 4x4 float matrix (the trace from +0x0, +0x14
 * and +0x28) as a 16-byte store at its first argument. Called directly from 41
 * sites; no value returned. */
struct Quaternion; /* derived name */
struct Matrix44;   /* derived name */

void FUN_01343600(Quaternion *out, const Matrix44 *matrix); /* derived name */

void FUN_013435f0(Quaternion *out, const Matrix44 *matrix) /* derived name */
{
    FUN_01343600(out, matrix);
}
