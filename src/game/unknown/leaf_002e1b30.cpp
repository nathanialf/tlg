/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_object016c7d08.h"

/* derived names: a range of values of a link (48 bytes): from `low` up to
 * `high` (a negative high has no bound: 99999), and with flag 2 a name of
 * its own at +0x10 */
struct Range002e1b30 { /* derived name */
    int low;           /* +0x0 */
    int high;          /* +0x4 */
    unsigned flags;    /* +0x8: bit 1, the range has its own name */
    u8 unknownc[0x4];
    Name name; /* +0x10 */
    u8 unknown14[0x1c];
};

/* derived names: a link of a chain: its length at +0x10, its kind at +0x14
 * (-1, 0 or 1 end the chain), the name of the link after it at +0x1c and
 * its ranges at +0x40, the first two of which are not searched */
struct Link002e1b30 { /* derived name */

    /* the name a value starts from: the first range searched that holds
     * it gives its own name when it has one; else the link's. Returned by
     * value: each return copies its name into the caller's (the two
     * reference raises apart, the index read after them from either) */
    Name nameOf(int value) const /* derived name */
    {
        for (unsigned i = 2; i < ranges.size(); ++i) {
            const Range002e1b30 &range = ranges.at(i);
            int high = range.high < 0 ? 99999 : range.high;
            if (range.low <= value && value < high) {
                if (range.flags & 2)
                    return range.name;
                break;
            }
        }
        return next;
    }

    u8 unknown0[0x10];
    float length; /* +0x10 */
    int kind;     /* +0x14 */
    u8 unknown18[0x4];
    Name next; /* +0x1c */
    u8 unknown20[0x20];
    Array05943280<Range002e1b30> ranges; /* +0x40 */
};

/* derived names: an entry of the links' table by name (24 bytes) */
struct LinkEntry002e1b30 {   /* derived name */
    unsigned hash;           /* +0x0 */
    Name name;               /* +0x4 */
    Link002e1b30 *value;     /* +0x8 */
    LinkEntry002e1b30 *next; /* +0x10 */
};

/* derived names: the object at +0x8b8 of the game's world, whose links by
 * name are a table of ten buckets at +0x29c8 */
struct Links002e1b30 { /* derived name */
    u8 unknown0[0x29c8];
    NameTable<LinkEntry002e1b30, 10> links; /* +0x29c8 */
};

struct World057c9390 { /* derived name */
    u8 unknown0[0x8b8];
    Links002e1b30 *links; /* +0x8b8 */
};

/* derived names: a walk along the chain of links from a link: whether the
 * names passed are collected, whether the lengths count negative, the value
 * the first name is chosen by, the link */
struct Walk002e1b30 { /* derived name */
    int collect;      /* +0x0 */
    int negate;       /* +0x4 */
    int value;        /* +0x8 */
    u8 unknownc[0x4];
    Link002e1b30 *link; /* +0x10 */
};

/* derived name: the length of up to six links of the chain, the first named
 * by the walk's link for its value, each named by the one before it, the
 * names collected when asked; the walk ends at a name the table does not
 * hold or at a link of kind -1, 0 or 1 */
// NONMATCHING: 14/199 at 768 bytes against 770 (round 546E; first difference at instruction 12,
// the spill below; aligned side by side the rest is equal in order up to register
// allocation): (a) the names' pointer is spilled at the entry where the base spills it in the
// push's growth block (a region split of its live range); (b) the first range's name raised in
// its own block with rcx, so the two raises' tails (equal after allocation) are merged by the
// branch folder where the base's take rdx in the found path and stay apart. The IR has both
// raises apart and the index load after them (InstCombine's load-through-phi), as the base.
float FUN_002e1b30(const Walk002e1b30 *walk, Array05943280<Name> *names) /* derived name */
{
    float total = 0.0f;
    if (!walk->link)
        return total;
    Name name = walk->link->nameOf(walk->value);
    for (unsigned step = 0; step < 6; ++step) {
        Links002e1b30 *links = D_57c9390->world38->links;
        if (!links)
            break;
        LinkEntry002e1b30 *entry = links->links.find(name.index);
        if (!entry)
            break;
        Link002e1b30 *link = entry->value;
        if (!link)
            break;
        float length = link->length;
        if (walk->negate)
            length = -length;
        if (walk->collect)
            names->push(name);
        total += length;
        if (link->kind >= -1 && link->kind <= 1)
            break;
        name = link->next;
    }
    return total;
}
