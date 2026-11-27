/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_joints0148a5e0.h"

/* derived names: slot 0 of the vtable at 0x16d7b80 (built by FUN_0129ea30),
 * as leaf_0148c5d0.cpp's: the object passed to FUN_013e8390, then the index
 * of its owner's joint "jt_RotAxis" kept at +0x18 */
struct Object0148a5e0 { /* derived name */
    u8 unknown0[0x8];
    Owner0148a5e0 *owner; /* +0x8 */
    u8 unknown10[0x8];
    int rotAxis; /* +0x18 */
};

void FUN_013e8390(Object0148a5e0 *object); /* derived name */

void FUN_0148a5e0(Object0148a5e0 *self) /* derived name */
{
    FUN_013e8390(self);
    self->rotAxis = self->owner->skeleton.jointIndex(Name("jt_RotAxis"));
}
