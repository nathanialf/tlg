/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: an object with a counted reference at +0x238, exchanged
 * (FUN_0020d8c0 calls this twice); not traced further */
struct Object00cbdeb0 /* derived name */
{
    u8 unknown0[0x238];
    AtomicRef0045c470<Object016b9108> held238; /* +0x238 */
};

/* derived name: the class of the value given, over the reference's (the
 * value compared first, `cmp rsi, rbx`); not traced */
class Value00cbdeb0 : public Object016b9108 /* derived name */
{
};

void FUN_00cbd9b0(Object00cbdeb0 *object); /* derived name */

/* derived name: the value put into the reference, then FUN_00cbd9b0 on the
 * object as a tail call */
void FUN_00cbdeb0(Object00cbdeb0 *object, Value00cbdeb0 *value)
{
    object->held238.set(value);
    FUN_00cbd9b0(object);
}
