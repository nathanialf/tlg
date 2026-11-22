/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: as FUN_00589590 over an array of plain pointers: each
 * object of the array at +0x30 of the second argument is handed to its
 * handler, the object's int at +0x24 indexing the table of functions at
 * +0x48 of the first argument; a null object, index 0 or a null entry is
 * skipped, and the count is read again after each call. Returns 0. Its
 * address is passed at 0xbe750a. The classes are not traced. */
struct Visitor00c0a930; /* derived name */

typedef void (*Handler00c0a930)(Visitor00c0a930 *visitor,
                                Object016b85e0 *object); /* derived name */

struct Visitor00c0a930 {
    u8 unknown0[0x48];
    Handler00c0a930 *handlers; /* +0x48 */
};

struct Object00c0a930 { /* derived name */
    u8 unknown0[0x30];
    Array05943280<Object016b85e0 *> unknown30; /* +0x30 */
};

int FUN_00c0a930(Visitor00c0a930 *self, Object00c0a930 *object) /* derived name */
{
    for (unsigned i = 0; i < object->unknown30.size(); i++) {
        Object016b85e0 *node = object->unknown30.at(i);
        if (node) {
            int index = node->unknown24;
            if (index) {
                Handler00c0a930 handler = self->handlers[index];
                if (handler)
                    handler(self, node);
            }
        }
    }
    return 0;
}
