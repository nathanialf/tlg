/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_types.h"

/* derived names: an entry held by two lists of the owner below, each entry
 * keeping its place in each (-1 when it is in none): at +0x3c and +0x40 for
 * FUN_006e1870, at +0x38 and +0x3c for FUN_007b2350 */
struct Entry006e1870 { /* derived name */
    u8 unknown0[0x3c];
    int index3c; /* +0x3c */
    int index40; /* +0x40 */
};

struct Entry007b2350 { /* derived name */
    u8 unknown0[0x38];
    int index38; /* +0x38 */
    int index3c; /* +0x3c */
};

/* derived names: the two lists, at +0x10 and +0x28 */
template <class T> struct Owner006e1870 { /* derived name */
    u8 unknown0[0x10];
    Array05943280<T *> first;  /* +0x10 */
    Array05943280<T *> second; /* +0x28 */
};

/* derived names: the entry taken out of each list it is in: the last entry
 * of the list told its new place (unless the list holds one entry, or the
 * entry's place equals the count), the entry replaced by the last
 * (Array05943280::removeSwap, the place read again) and its place cleared */
// NONMATCHING: instruction order only (round 365B, single unit, 49/51, same size; FUN_007b2350
// the same): after the last entry is told its place in the second list, the base reads the count
// again before the place (`mov ecx, [rdi+0x30]; mov eax, [rsi+0x40]`), the build the place
// first; the first list's two reads are in the build's order in the base too
void FUN_006e1870(Owner006e1870<Entry006e1870> *owner, Entry006e1870 *entry) /* derived name */
{
    if (entry->index3c >= 0) {
        const int count = owner->first.size();
        if (count > 1 && count != entry->index3c)
            owner->first.at(count - 1)->index3c = entry->index3c;
        owner->first.removeSwap(entry->index3c);
        entry->index3c = -1;
    }
    if (entry->index40 >= 0) {
        const int count = owner->second.size();
        if (count > 1 && count != entry->index40)
            owner->second.at(count - 1)->index40 = entry->index40;
        owner->second.removeSwap(entry->index40);
        entry->index40 = -1;
    }
}

/* derived names: the same over the places at +0x38 and +0x3c */
void FUN_007b2350(Owner006e1870<Entry007b2350> *owner, Entry007b2350 *entry) /* derived name */
{
    if (entry->index38 >= 0) {
        const int count = owner->first.size();
        if (count > 1 && count != entry->index38)
            owner->first.at(count - 1)->index38 = entry->index38;
        owner->first.removeSwap(entry->index38);
        entry->index38 = -1;
    }
    if (entry->index3c >= 0) {
        const int count = owner->second.size();
        if (count > 1 && count != entry->index3c)
            owner->second.at(count - 1)->index3c = entry->index3c;
        owner->second.removeSwap(entry->index3c);
        entry->index3c = -1;
    }
}
