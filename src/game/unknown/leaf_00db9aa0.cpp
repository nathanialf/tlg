/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: whether a value is nil (its type tag 0) */
static inline bool isNil(const HksObject &value)
{
    return (value.type & 0xf) == 0;
}

/* derived name: the node of the table's hash part whose key is the number,
 * null when there is none (an integer key hashes to itself under the
 * mask) */
static inline const HksNode *findNumber(const HksTable *table, int key)
{
    const float number = key;
    const HksNode *nodes = table->nodes;
    const HksNode *node = &nodes[table->mask & key];
    do {
        if ((node->key.type & 0xf) == 3 && node->key.value.number == number)
            return node;
        node = reinterpret_cast<HksNode *const *>(nodes)[~(node - nodes)];
    } while (node);
    return 0;
}

/* derived name: whether the hash part holds a value other than nil under
 * the number */
static inline bool hasNumber(const HksTable *table, int key)
{
    const HksNode *node = findNumber(table, key);
    return node && !isNil(node->value);
}

/* derived name: Lua's luaH_getn, the length of a table: a border of the
 * array part by a binary search when its last value is nil; the array's
 * size when there is no hash part (its mask all ones); else the hash part
 * searched from the array's size up, the bound doubled until a key is
 * missing and then halved; past 2^31 a linear walk from 1 */
unsigned FUN_00db9aa0(HksTable *table)
{
    unsigned j = table->arraySize;
    if (j > 0 && isNil(table->array[j - 1])) {
        unsigned i = 0;
        while (j - i > 1) {
            const unsigned m = (i + j) / 2;
            if (isNil(table->array[m - 1]))
                j = m;
            else
                i = m;
        }
        return i;
    }
    if (table->mask == 0xffffffff)
        return j;
    unsigned i = j;
    ++j;
    while (hasNumber(table, j)) {
        i = j;
        j *= 2;
        if (j > 0x7fffffff) {
            unsigned k = 1;
            for (; k <= table->arraySize; ++k)
                if (isNil(table->array[k - 1]))
                    return k - 1;
            while (findNumber(table, k))
                ++k;
            return k - 1;
        }
    }
    while (j - i > 1) {
        const unsigned m = (i + j) / 2;
        const HksNode *node = findNumber(table, m);
        if (!node || isNil(node->value))
            j = m;
        else
            i = m;
    }
    return i;
}
