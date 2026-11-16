/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector00fdab40.h"

/* derived names: a copy of FUN_0101e270 (leaf_0101e270.cpp, where the walk
 * is described) at its own unit's rate, 1 - 0.865 (the float difference,
 * 0x3e0a3d70, not 0.135f's 0x3e0a3d71). Called only from its own unit. */
void FUN_012a7830(Vector4Loop *value, const Vector4Loop &target, float step) /* derived name */
{
    const float rate = 1.0f - 0.865f;
    Vector4Loop d = target - *value;
    if (dot(d, d) >= 1e-10f * 1e-10f) {
        float frames = step * 59.999996f;
        int whole = (int)frames;
        float fraction = frames - (float)whole;
        for (;;) {
            d = target - *value;
            if (!(whole-- > 0))
                break;
            *value = rate * d + *value;
        }
        *value = fraction * rate * d + *value;
    } else {
        *value = target;
    }
}
