/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ac990.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the component of the type D_57d4a68 points to, as far as
 * slot 17 of Object016ac990 reads it: an int at +0x3e0 */
struct Component00765280 : Component00503fb0 { /* derived name */
    u8 unknown8c[0x354];
    int unknown3e0; /* +0x3e0 */
};

extern Type00503fb0 *D_57d4a68; /* derived name: the component's type */

/* derived names: slot 17 of the vtable at 0x16ac990: when the int at +0x104
 * is 1, the body at +0x68 takes the two references at +0x110 and +0x118,
 * and, when the first holds a node with a component of the type D_57d4a68
 * points to, the component's int at +0x3e0; the argument is not read */
// NONMATCHING: the node's reader count's address (round 365B, whole module, 110/141, same size):
// the base forms it twice, `lea rdi, [r14+0x30]` for FUN_01331c10 and `lock dec dword
// [r14+0x30]` after the search, where the build keeps `lea r14, [r12+0x30]` in a register for
// both; the rest (the two exchanges, the search inlined) is the base's
void Object016ac990::slot17(Context0079c700 *)
{
    if (unknown104 == 1) {
        Body0077bac0 *body = unknown68;
        body->unknown62e0 = held110;
        body->unknown62e8 = held118;
        if (Object016b85e0 *node = held110.get())
            if (Component00503fb0 *found = node->findComponent(D_57d4a68))
                body->unknown62d0 = static_cast<Component00765280 *>(found)->unknown3e0;
    }
}
