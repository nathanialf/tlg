/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aa0d0.h"

/* slot 8 of 0x16aa0d0 (and of 0x16aa140 and 0x16aa290, which keep it): the
 * position at +0x40 moved by 0.2 of the vector at 0x57d78a0, its fourth
 * component kept, whatever the index */
Float4 Object016aa0d0::slot8(int) const
{
    const float w = unknown40.w;
    const float x = unknown40.x + D_57d78a0.x * 0.2f;
    const float y = unknown40.y + D_57d78a0.y * 0.2f;
    const float z = unknown40.z + D_57d78a0.z * 0.2f;
    Float4 result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    return result;
}
