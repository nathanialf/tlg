/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object05945a38.h"

class Cache0138e140; /* derived name */

/* derived names: an object the cache makes: the root class's, then the
 * name it was made for at +0x28 and its cache at +0x30; not traced
 * further */
struct Item0138e140 : Object016b9108 { /* derived name */
    u8 unknown24[0x4];
    Name key;             /* +0x28 (derived name) */
    Cache0138e140 *cache; /* +0x30 (derived name) */
};

/* derived name: the type of the objects the cache makes */
extern Type00503fb0 *D_5938160;

/* derived names: a node of the cache's map: a name's index, the index of
 * its object in the cache's array at +0x8 and the next node of its chain at
 * +0x10 */
struct MapNode0138e140 { /* derived name */
    unsigned key;        /* +0x0 */
    u8 unknown4[0x4];
    int index; /* +0x8 */
    u8 unknownc[0x4];
    MapNode0138e140 *next; /* +0x10 */
};

/* derived names: the map: 256 chains, chosen by the low byte of a name's
 * index; FUN_00a84840 adds a node */
struct Map0138e140 {                /* derived name */
    MapNode0138e140 *chains[0x100]; /* +0x0 */
};

void FUN_00a84840(Map0138e140 *map, const Name *name, unsigned key, int index); /* derived name */

/* derived names: the cache: its objects as counted references at +0x28 and
 * the map from a name to an object's index at +0x40 */
class Cache0138e140 /* derived name */
{
  public:
    Item0138e140 *get(Owner05943280 *heap, const Name &name); /* derived name: FUN_0138e140 */

  private:
    u8 unknown0[0x28];
    Object0134f620 objects; /* +0x28 (derived name) */
    Map0138e140 map;        /* +0x40 (derived name) */
};

/* FUN_0138e140: the cache's object for a name, made when the map has none,
 * with `heap` as the thread's heap meanwhile: an object of the type at
 * 0x5938160 made under the empty name (FUN_00cbc5a0, mode 0), given the name
 * and the cache, a reference to it appended to the array at +0x28
 * (FUN_0138e360) and its index put in the map under the name
 * (FUN_00a84840) */
Item0138e140 *Cache0138e140::get(Owner05943280 *heap, const Name &name)
{
    ThreadHeapScope05943280 scope(heap);
    const unsigned key = name.index;
    int index;
    MapNode0138e140 *node = map.chains[key & 0xff];
    for (; node; node = node->next)
        if (node->key == key)
            break;
    if (node) {
        index = node->index;
    } else {
        Item0138e140 *item =
            static_cast<Item0138e140 *>(FUN_00cbc5a0(D_5945a38, D_5938160, Name(), 0));
        item->key = name;
        item->cache = this;
        index = objects.add(Ref00503fb0<Object016b9108>(item));
        FUN_00a84840(&map, &name, key, index);
    }
    Item0138e140 *found = 0;
    if (index >= 0)
        found = static_cast<Item0138e140 *>(objects.at(index).get());
    return found;
}
