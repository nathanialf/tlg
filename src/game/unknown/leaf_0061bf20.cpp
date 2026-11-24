/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the node held at +0x1e8 of the object at +0x28 has its
 * first component of the type D_58143e0 points to marked: the int at +0x38
 * set to 1. The int spans the byte flags at +0x3a of other components
 * (Component00503fb0), so that component's class is read through a view of
 * its own; the classes are not traced. */
extern Type00503fb0 *D_58143e0; /* derived name: the component's type */

struct Marked0061bf20 { /* derived name: the component's view */
    u8 unknown0[0x38];
    int marked; /* +0x38 */
};

struct Holder0061bf20 { /* derived name */
    u8 unknown0[0x1e8];
    Object016b85e0 *node; /* +0x1e8 */
};

struct Object0061bf20 { /* derived name */
    u8 unknown0[0x28];
    Holder0061bf20 *holder; /* +0x28 */
};

void FUN_0061bf20(Object0061bf20 *self) /* derived name */
{
    if (Object016b85e0 *node = self->holder->node) {
        if (Component00503fb0 *component = node->component(D_58143e0))
            reinterpret_cast<Marked0061bf20 *>(component)->marked = 1;
    }
}
