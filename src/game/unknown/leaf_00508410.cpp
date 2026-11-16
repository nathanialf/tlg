/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: whether the object named "Condor" (usable by this thread)
 * is there and its position at +0x120 is nearer to the point than the
 * radius plus 12. The object's class is not traced. */
struct Named00508410 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16; /* +0x16 */
    u8 unknown18[0x108];
    float x; /* +0x120 */
    float y; /* +0x124 */
    float z; /* +0x128 */
};

struct Point00508410 { /* derived name */
    float x, y, z;
};

extern const char D_15c8db4[7];

bool FUN_00508410(const Point00508410 *point, float radius) /* derived name */
{
    Name name(D_15c8db4);
    Named00508410 *record = static_cast<Named00508410 *>(D_17ac870[name.index].record18);
    Named00508410 *object = 0;
    if (record && ((record->flags16 & 4) || threadMayUse()))
        object = record;
    name.release();
    if (object) {
        float reach = radius + 12.0f;
        float x = object->x - point->x;
        float y = object->y - point->y;
        float z = object->z - point->z;
        if (reach * reach > x * x + y * y + z * z)
            return true;
    }
    return false;
}
