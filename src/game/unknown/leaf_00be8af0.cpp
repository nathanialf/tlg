/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the object FUN_0069cxxx takes an object out of
 * (0x69ceff, kind 3): arrays of counted references by kind at +0x3a40 */
struct Object00be8af0 /* derived name */
{
    /* 0xbe8af0: the object's reference taken while the kind's array is
     * searched, dropped, then its element removed and the ones after it
     * moved down */
    void remove(Object016b9108 *object, unsigned kind); /* derived name */

    u8 unknown0[0x3a40];
    Array05943280<Ref00503fb0<Object016b9108>>
        lists[4]; /* +0x3a40, by kind (3 the largest seen; the count not traced) */
};

void Object00be8af0::remove(Object016b9108 *object, unsigned kind)
{
    Array05943280<Ref00503fb0<Object016b9108>> &list = lists[kind];
    int index = list.indexOf(Ref00503fb0<Object016b9108>(object));
    if (index != -1)
        list.removeAt(index);
}
