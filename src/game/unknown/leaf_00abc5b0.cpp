/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: an entry of the list FUN_00abc5b0 appends to: an int key
 * and a counted reference, 16 bytes */
struct Entry00abc5b0 {                       /* derived name */
    int key;                                 /* +0x0 */
    AtomicRef0045c470<Object016b9108> value; /* +0x8 */
};

/* derived name: the class of the value given, over the entry's (the value
 * compared first, `cmp rdx, rbx`); not traced */
class Value00abc5b0 : public Object016b9108 /* derived name */
{
};

/* derived names: the list: four entries from +0x8 and their count at +0x48
 * (signed: `movsxd rax, [rdi+0x48]`) */
struct List00abc5b0 { /* derived name */
    u8 unknown0[8];
    Entry00abc5b0 entries[4]; /* +0x8 */
    int count;                /* +0x48 */
};

/* derived name: appends an entry, the count raised first, then the key and
 * the reference stored (no bound test); called from 0x4473f2, 0xac0cf1 and
 * ten more sites */
void FUN_00abc5b0(List00abc5b0 *list, int key, Value00abc5b0 *value)
{
    Entry00abc5b0 &entry = list->entries[list->count++];
    entry.key = key;
    entry.value.set(value);
}
