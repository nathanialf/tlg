/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_joints0148a5e0.h"

/* derived name: the name of the joint FUN_0045e2c0 looks for */
extern Name D_57d5368;

/* derived names: an object with a node at +0x28 (a joint's layout: its
 * position at +0x120) and, at +0x80, the owner of a model's joints (the
 * model at +0xc0) */
struct Object0045e2c0 { /* derived name */
    u8 unknown0[0x28];
    Joint0148a5e0 *node28; /* +0x28 */
    u8 unknown30[0x50];
    Owner0148a5e0 joints; /* +0x80 */
};

/* derived name: the position of the joint the name at 0x57d5368 names,
 * 0.255 higher, else the node's at +0x28; zero without that node; written
 * to the first argument (rax is not set: no hidden return pointer). Three
 * callers (FUN_0048fea0, FUN_00ac34f0, FUN_00ac5230). */
void FUN_0045e2c0(Float4 &position, const Object0045e2c0 *object) /* derived name */
{
    if (object->node28) {
        position = object->node28->position;
        if (object->joints.skeleton.model) {
            const s16 index = object->joints.skeleton.jointIndex(D_57d5368);
            if (index >= 0) {
                if (const Joint0148a5e0 *joint = object->joints.skeleton.model->joints.at(index)) {
                    Float4 raised = joint->position;
                    raised.y += 0.255f;
                    position = raised;
                }
            }
        }
    } else {
        position = Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
}
