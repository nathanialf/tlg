/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the nil value a lookup gives when the key is not there
 * (tlg_game_scriptcode.h declares it by its own model) */
extern const HksObject D_1557370;

/* derived name: the value of an object key (compared by its pointer and
 * its tag) in a table's hash part, the nil value when it is not there, copied into
 * the value given */
inline void findObject(const HksTable *table, const HksObject key, HksObject &value)
{
    if (HksNode *nodes = table->nodes) {
        const u64 pointer = reinterpret_cast<u64>(key.value.pointer);
        HksNode *node = &nodes[table->mask & (pointer ^ (pointer >> 5) ^ (pointer >> 8))];
        do {
            if (node->key.value.pointer == key.value.pointer &&
                (node->key.type & 0xf) == (key.type & 0xf)) {
                value = node->value;
                return;
            }
            node = reinterpret_cast<HksNode **>(nodes)[~(node - nodes)];
        } while (node);
    }
    value = D_1557370;
}

/* derived name: Lua's lua_getmetatable by its arguments: whether an object
 * has a metatable, which is written to `metatable`: a table's, a
 * structure's and a userdata's own, else the one the registry keeps for the
 * object's type (under the global's key for it); a metatable word has its
 * low bit set when the metatable is a structure; the call timed */
// NONMATCHING: the nil value's two addresses are set value word first in the base (`lea r11, D+8;
// lea r14, D`) and the key's tag test is `and ebx, 0xf; je` (the build: D first, `test bl, 0xf`), the
// shape of about 80 sites of the base's script VM, none of them matched yet
int FUN_00d96dd0(lua_State *state, const HksObject *object, HksObject *metatable)
{
    HksApiTimer timer(state);
    const HksObject value = *object;
    const int type = value.type & 0xf;
    u64 word;
    if (type == 5) {
        word = reinterpret_cast<u64>(value.value.table->metatable);
    } else if (type == 7) {
        word = reinterpret_cast<u64>(static_cast<HksUserdata *>(value.value.pointer)->metatable);
    } else if (type == 12) {
        word = reinterpret_cast<u64>(value.value.structure->metatable);
    } else {
        HksGlobal *global = state->global;
        HksObject found;
        findObject(global->registry.value.table, global->unknown208[type + 27], found);
        switch (found.type & 0xf) {
        case 0:
            word = 0;
            break;
        case 12:
            word = reinterpret_cast<u64>(found.value.structure) | 1;
            break;
        default:
            word = reinterpret_cast<u64>(found.value.table);
            break;
        }
    }
    if (!word)
        return 0;
    if (word & 1) {
        metatable->value.pointer = reinterpret_cast<void *>(word & ~static_cast<u64>(1));
        metatable->type = 12;
    } else {
        metatable->value.pointer = reinterpret_cast<void *>(word);
        metatable->type = 5;
    }
    return 1;
}
