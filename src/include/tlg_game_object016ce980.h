/* src/include/tlg_game_object016ce980.h: the class whose vtable is at
 * 0x16ce980 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE980_H
#define TLG_GAME_OBJECT016CE980_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_object016b9108.h"

/* derived names: an entry of the table of Object016ce980, 0x30 bytes:
 * Names at +0x4, +0x18 and +0x1c (released last to first when the entry is
 * emptied), the next entry at +0x28; the rest is not traced */
struct Entry016ce980 {
    u32 hash;   /* +0x0 */
    Name name4; /* +0x4 */
    u8 unknown8[0x10];
    Name name18; /* +0x18 */
    Name name1c; /* +0x1c */
    u8 unknown20[0x8];
    Entry016ce980 *next; /* +0x28 */
};

/* derived names: the class whose vtable is at 0x16ce980
 * (config/vtables.derived.base.txt, stored by its creator FUN_00ae6380,
 * leaf_00ae6380.cpp, and its destructor FUN_0138e840), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0xd8 bytes: a table of 16 buckets of 0x30-byte entries at +0x28
 * (NameTable: the buckets and its two lists one memset from the
 * constructor, 16 and 0x30 after them, the count at +0xc0), two empty
 * Names at +0xc8 and +0xcc and 0 at +0xd0 and +0xd4, all from the
 * constructor. The destructor is implicit: the complete one,
 * FUN_0138e830, is a jump to the base-object one, FUN_0138e840 (the two
 * Names, the table emptied and its blocks freed, then the root's
 * destructor in line), and the deleting one, FUN_0138ea90, calls it: its
 * cost is over the inline limit of 325 (the inline hint). The class has
 * no key function, so the creator's unit emits the vtable with them. */
class Object016ce980 : public Object016b9108 /* derived name */
{
  public:
    Object016ce980(const Name &name) : Object016b9108(name), unknownd0(0), unknownd4(0) {}

  private:
    u8 unknown24[0x4];
    NameTable<Entry016ce980, 16> table28; /* +0x28 */
    Name namec8;                          /* +0xc8 */
    Name namecc;                          /* +0xcc */
    int unknownd0;                        /* +0xd0: 0 from the constructor */
    int unknownd4;                        /* +0xd4: 0 from the constructor */
};

#endif
