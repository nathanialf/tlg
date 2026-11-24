/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: two functions of one shape, each held in a vtable of its
 * own class (their addresses at 0x16c05a8 and 0x16c2750): the
 * node at +0x8 of the object at +0x18 is searched for its first component of
 * the type the pointer at 0x5823930 holds, under the node's reader count, and
 * the byte at +0x7c of that component is returned; zero when there is no
 * node or no such component. The classes are not traced. */
extern const Type00503fb0 *D_5823930; /* derived name */

struct Flagged00ff0ab0 { /* derived name: the component's view */
    u8 unknown0[0x7c];
    u8 flag; /* +0x7c */
};

struct Holder00ff0ab0 { /* derived name */
    u8 unknown0[0x8];
    Object016b85e0 *node; /* +0x8 */
};

struct Object00ff0ab0 { /* derived name */
    u8 unknown0[0x18];
    Holder00ff0ab0 *holder; /* +0x18 */
};

// NONMATCHING: 2 instructions, 125 bytes against 127: the return's zero. The base makes it in one
// block both null paths reach (`xor eax, eax` at 0xff0b28, the found path `movzx; jmp` over it);
// here it is made in the entry before the node's test and again after the drop (round 573D;
// FUN_0046f3d0's residual)
int FUN_00ff0ab0(Object00ff0ab0 *self) /* derived name */
{
    if (Object016b85e0 *node = self->holder->node) {
        if (Component00503fb0 *component = node->component(D_5823930))
            return reinterpret_cast<Flagged00ff0ab0 *>(component)->flag;
    }
    return 0;
}

// NONMATCHING: FUN_00ff0ab0's residual (the return's zero)
int FUN_0125d180(Object00ff0ab0 *self) /* derived name */
{
    if (Object016b85e0 *node = self->holder->node) {
        if (Component00503fb0 *component = node->component(D_5823930))
            return reinterpret_cast<Flagged00ff0ab0 *>(component)->flag;
    }
    return 0;
}
