/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the component at +0x320 of the object below: over
 * Object01343880 (the scene node that holds it at +0x28), flags at +0x38 */
struct Child00e87a90 : Object01343880 { /* derived name */
    u8 unknown34[0x4];
    u8 flags38; /* +0x38 */
};

struct Target00e87db0; /* derived name */

/* derived names: the object FUN_00e87a90 switches, as far as it reads: the
 * target at +0x318, the component at +0x320 and the state at +0x32c */
struct Object00e87a90 { /* derived name */
    u8 unknown0[0x318];
    Target00e87db0 *unknown318; /* +0x318 */
    Child00e87a90 *child320;    /* +0x320 */
    u8 unknown328[0x4];
    u32 state32c; /* +0x32c */
};

void FUN_00e87db0(Target00e87db0 *target); /* derived name */
void FUN_00d24260(Child00e87a90 *child);   /* derived name */

/* derived name: while bit 1 of the state is set: switched on, the state
 * becomes 1, FUN_00e87db0 runs over the target, the component is emptied
 * (FUN_00d24260), flagged and taken out of the node that holds it under
 * the world's write lock (FUN_00c5a160's body, the lock held by a
 * WorldWriteLock05938c40); switched off, bits 2 and 3 of the state are
 * replaced by bit 2 */
void FUN_00e87a90(Object00e87a90 *self, int on) /* derived name */
{
    u32 state = self->state32c;
    if (state & 2) {
        if (on) {
            self->state32c = 1;
            FUN_00e87db0(self->unknown318);
            Child00e87a90 *child = self->child320;
            FUN_00d24260(child);
            child->flags38 |= 1;
            Object016b85e0 *holder = static_cast<Object016b85e0 *>(child->unknown28);
            if (holder) {
                WorldWriteLock05938c40 lock;
                holder->removeChild(child);
            }
        } else {
            self->state32c = (state & ~0xc) | 4;
        }
    }
}
