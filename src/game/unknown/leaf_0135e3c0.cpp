/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_types.h"

/* derived names: two ids of the object, at +0x20 and +0x24 */
struct Object0135e3c0 { /* derived name */
    u8 unknown0[0x18];
    int unknown18; /* +0x18 */
    int unknown1c; /* +0x1c */
    int unknown20; /* +0x20 */
    int unknown24; /* +0x24 */
};

/* derived name: the index of the first id equal to `id`, or -1, the ids
 * indexed unsigned (`cmp [rsi+rcx*4], eax; je; inc rcx`) */
static inline int indexOf(const Array05943280<int> &ids, const int &id) /* derived name */
{
    const int *data = ids.begin();
    for (unsigned i = 0; i < ids.size(); ++i)
        if (data[i] == id)
            return i;
    return -1;
}

/* derived name: 1 when the list holds the id at +0x20 or the one at +0x24,
 * else 0 */
int FUN_0135e3c0(const Object0135e3c0 *self, const Array05943280<int> *ids) /* derived name */
{
    if (indexOf(*ids, self->unknown20) != -1)
        return 1;
    return indexOf(*ids, self->unknown24) != -1;
}
