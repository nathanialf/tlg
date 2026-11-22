/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the nil value a lookup gives when the key is not there
 * (tlg_game_scriptcode.h declares it by its own model) */
extern const HksObject D_1557370;

/* derived name: the value of a number key in a table's hash part, the nil
 * value when it is not there, copied into the value given */
inline void findNumber(const HksTable *table, float key, int hash, HksObject &value)
{
    if (HksNode *nodes = table->nodes) {
        HksNode *node = &nodes[table->mask & hash];
        do {
            if ((node->key.type & 0xf) == 3 && node->key.value.number == key) {
                value = node->value;
                return;
            }
            node = reinterpret_cast<HksNode **>(nodes)[~(node - nodes)];
        } while (node);
    }
    value = D_1557370;
}

/* derived name: a structure's value at an index from 1: its table's array
 * part, else its hash part (the nil value without a table) */
inline HksObject elementOf(const HksStruct *structure, int index)
{
    HksObject value;
    if (const HksTable *table = structure->table) {
        const u32 slot = index - 1;
        if (slot < table->arraySize)
            value = table->array[slot];
        else
            findNumber(table, index, index, value);
    } else {
        value = D_1557370;
    }
    return value;
}

/* hks_obj_rawget_array (the name from its assertion message): the value of
 * a table or a structure at an index from 1: a table's array part only (nil
 * past it), a structure's table's array part, else its hash part (the nil
 * value without a table); the call timed */
// NONMATCHING: at the structure's join the base loads the value's pointer word before its type
// (`mov r8, [rax]; mov esi, [r11]`); the build loads the type first
HksObject FUN_00db9130(lua_State *s, const HksObject *objectToGet, int index)
{
    HksApiTimer timer(s);
    if (!((objectToGet->type & 0xf) == 5 || (objectToGet->type & 0xf) == 12)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xdbbaaa29,
               "HKS_GET_TYPE(*objectToGet) == TTABLE || HKS_GET_TYPE(*objectToGet) == TSTRUCT",
               "hks_obj_rawget_array", "index does not point to a struct/table", HKS_OBJECT_FILE,
               419);
        __builtin_trap();
    }
    if ((objectToGet->type & 0xf) == 5) {
        const HksTable *table = objectToGet->value.table;
        const u32 slot = index - 1;
        if (slot < table->arraySize)
            return table->array[slot];
        HksObject nil;
        nil.type = 0;
        return nil;
    }
    return elementOf(objectToGet->value.structure, index);
}
