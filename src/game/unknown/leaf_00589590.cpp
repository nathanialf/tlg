/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: each counted reference of the array at +0x30 of the
 * second argument is held for one turn of the loop (the count raised, then
 * dropped) and the object handed to its handler: the object's int at +0x24
 * indexes the table of functions at +0x48 of the first argument, and index
 * 0 or a null entry is skipped. The array's ends are taken once (`lea r12,
 * [rbx+rax*8]`). Returns 0. The classes are not traced. */
struct Visitor00589590; /* derived name */

typedef void (*Handler00589590)(Visitor00589590 *visitor, Node00503fb0 *object); /* derived name */

struct Visitor00589590 {
    u8 unknown0[0x48];
    Handler00589590 *handlers; /* +0x48 */
};

struct Object00589590 { /* derived name */
    u8 unknown0[0x30];
    Array05943280<Ref00503fb0<Node00503fb0>> unknown30; /* +0x30 */
};

int FUN_00589590(Visitor00589590 *self, Object00589590 *object) /* derived name */
{
    for (Ref00503fb0<Node00503fb0> reference : object->unknown30) {
        Node00503fb0 *node = reference.get();
        if (node) {
            int index = node->unknown24;
            if (index) {
                Handler00589590 handler = self->handlers[index];
                if (handler)
                    handler(self, node);
            }
        }
    }
    return 0;
}
