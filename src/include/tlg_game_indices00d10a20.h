/* src/include/tlg_game_indices00d10a20.h: the object whose two tables of
 * indices by name FUN_00d10a20 and FUN_00d10b60 read (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_INDICES00D10A20_H
#define TLG_GAME_INDICES00D10A20_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: an entry of a table of indices by name, 0x18 bytes: the
 * hash (the name's index) at +0x0, the name at +0x4, the index at +0x8
 * (negative for none), the next entry at +0x10 */
struct IndexEntry00d10a20 { /* derived name */
    u32 hash;               /* +0x0 */
    Name name;              /* +0x4 */
    int value;              /* +0x8 */
    u8 unknownc[0x4];
    IndexEntry00d10a20 *next; /* +0x10 */
};

typedef NameTable<IndexEntry00d10a20, 64> IndexTable00d10a20; /* derived name */

/* derived names: the object FUN_00786cb0 passes to both (its fields before
 * +0x4b8 not traced) */
struct Indices00d10a20 { /* derived name */
    u8 unknown0[0x4b8];
    IndexTable00d10a20 first;  /* +0x4b8: FUN_00d10a20 */
    IndexTable00d10a20 second; /* +0x6d8: FUN_00d10b60 */

    /* the indices of the names found in a table, each one that is not
     * negative appended to `indices` in the names' order (the index read
     * once, before the growth: `mov r13d, [rdx+8]`; the names' count and
     * block read again after each append) */
    static void collect(const IndexTable00d10a20 &table, Array05943280<int> &indices,
                        const Array05943280<Name> &names)
    {
        for (unsigned i = 0; i < names.size(); ++i)
            if (IndexEntry00d10a20 *entry = table.find(names.at(i).index)) {
                int index = entry->value;
                if (index >= 0)
                    indices.push(index);
            }
    }
};

#endif
