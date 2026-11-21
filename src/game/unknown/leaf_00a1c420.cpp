/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00a1c420: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"
#include "tlg_game_name.h"

/* derived names: a map from a name to a name in 64 chains picked by the low
 * six bits of the key's index (its hash); each 0x18-byte node holds the
 * hash, the key, the value and the next node. FUN_00a18f00 finds the key's
 * node or adds one from the map's pool (the blocks at +0x200, the free
 * nodes at +0x208), the key and the value copied in. */
struct Node00a18f00 {   /* derived name */
    u32 hash;           /* +0x0 */
    Name key;           /* +0x4 */
    Name value;         /* +0x8 */
    Node00a18f00 *next; /* +0x10 */
};

struct Map00a18f00 {          /* derived name */
    Node00a18f00 *chains[64]; /* +0x0 */
    u8 unknown200[0x18];
};

void FUN_00a18f00(Map00a18f00 *map, const Name &key, u32 hash,
                  const Name &value); /* derived name */

/* derived names: the object the caller at 0x1b3bb6 reaches through the
 * pointer at 0x57c9390 (+0x108, then +0x30): the map at +0x118 under the
 * spin lock at +0x348. Its other fields are not traced. */
struct Object00a1c420 { /* derived name */
    u8 unknown0[0x118];
    Map00a18f00 map; /* +0x118 */
    u8 unknown330[0x18];
    Lock059458a4 lock; /* +0x348 */
};

/* derived name: adds the key with its value under the lock where the map
 * does not hold it yet */
void FUN_00a1c420(Object00a1c420 *self, const Name &key, const Name &value) /* derived name */
{
    self->lock.lock();
    u32 hash = key.index;
    Node00a18f00 *node = self->map.chains[hash & 0x3f];
    while (node && !(node->hash == hash && node->key.index == hash))
        node = node->next;
    if (!node)
        FUN_00a18f00(&self->map, key, hash, value);
    self->lock.unlock();
}
