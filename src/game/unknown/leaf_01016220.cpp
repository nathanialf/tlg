/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: returns 0 when its first argument is less than its second,
 * else the second (vcmpltss, vandnps); FUN_01015bb0 passes its address (lea at
 * 0x1015bb0) to FUN_01015bd0 with 0.0 in xmm1. */
float FUN_01016220(float value, float limit) /* derived name */
{
    return value < limit ? 0.0f : limit;
}
