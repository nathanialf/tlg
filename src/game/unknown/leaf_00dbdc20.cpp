/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the first entry of a table's hash part from a node on
 * whose value is not nil, its key written to `key` and its value returned;
 * nil without a hash part or past its last node */
static inline HksObject nextNode(const HksTable *table, const HksNode *from, HksObject *key)
{
    HksObject result;
    result.type = 0;
    result.value.pointer = 0;
    const HksNode *nodes = table->nodes;
    if (!nodes)
        return result;
    const size_t count = table->mask + 1;
    for (const HksNode *node = from; node < nodes + count; ++node) {
        if (node->value.type & 0xf) {
            const HksObject next = node->key;
            key->type = next.type;
            key->value = next.value;
            return node->value;
        }
    }
    return result;
}

/* derived name: the entry of a table after `key` when the key is nil or a
 * number of the array part: the next value of the array part that is not
 * nil, its index plus one written to the key as a number; past the array
 * part the first entry of the hash part whose value is not nil, its key
 * written to `key`; nil past the last entry */
HksObject FUN_00dbdc20(HksTable *table, HksObject *key)
{
    unsigned i = 0;
    if (key->type & 0xf)
        i = static_cast<int>(key->value.number);
    for (; i < table->arraySize; ++i)
        if (table->array[i].type & 0xf)
            break;
    if (i == table->arraySize)
        return nextNode(table, table->nodes, key);
    key->value.number = i + 1;
    key->type = 3;
    return table->array[i];
}
