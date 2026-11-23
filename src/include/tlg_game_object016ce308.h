/* src/include/tlg_game_object016ce308.h: the class whose vtable is at
 * 0x16ce308 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE308_H
#define TLG_GAME_OBJECT016CE308_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_object016b9108.h"

/* derived names: an entry of the table of Object016ce308, 0x18 bytes: Names
 * at +0x4 and +0x8 (released last first when it is emptied), the next entry
 * at +0x10 */
struct Entry016ce308 {
    u32 hash;   /* +0x0 */
    Name name4; /* +0x4 */
    Name name8; /* +0x8 */
    u8 unknownc[0x4];
    Entry016ce308 *next; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16ce308
 * (config/vtables.derived.base.txt, stored by its creator FUN_00a19550,
 * leaf_00a19550.cpp, and its destructor FUN_0138ba60), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x368 bytes: from the constructor: locked arrays of Names at
 * +0x38, +0x50, +0x68 and +0x80, locked arrays at +0x98, +0xd0, +0xe8 and
 * +0x100 (their elements have no destructor; not traced), a table of 64
 * buckets of 0x18-byte entries at +0x118 (NameTable), -1 at +0x33c, 1 at
 * +0x340, 0 at +0x348 and a locked array of Names at +0x350; then
 * FUN_00a1bdd0 runs over the object and 1 is stored at +0x338. The
 * destructor is implicit: the complete one, FUN_0138ba30, is a jump to
 * the base-object one, FUN_0138ba60 (the arrays and the table last to
 * first, the table emptied and its blocks freed, then the root's
 * destructor in line), and the deleting one, FUN_0138ba40, calls it: its
 * cost is over the inline limit of 325 (the inline hint). The class has
 * no key function, so the creator's unit emits the vtable with them. */
class Object016ce308 : public Object016b9108 /* derived name */
{
  public:
    Object016ce308(const Name &name)
        : Object016b9108(name), unknown33c(-1), unknown340(1.0f), unknown348(0)
    {
        FUN_00a1bdd0();
        unknown338 = 1;
    }

    void FUN_00a1bdd0(); /* derived name; not traced */

  private:
    u8 unknown24[0x14];
    Array01343a80<Name> names38;  /* +0x38 */
    Array01343a80<Name> names50;  /* +0x50 */
    Array01343a80<Name> names68;  /* +0x68 */
    Array01343a80<Name> names80;  /* +0x80 */
    Array01343a80<int> unknown98; /* +0x98: the element not traced */
    u8 unknownb0[0x20];
    Array01343a80<int> unknownd0;          /* +0xd0: the element not traced */
    Array01343a80<int> unknowne8;          /* +0xe8: the element not traced */
    Array01343a80<int> unknown100;         /* +0x100: the element not traced */
    NameTable<Entry016ce308, 64> table118; /* +0x118 */
    int unknown338;                        /* +0x338: 1 after FUN_00a1bdd0 in the constructor */
    int unknown33c;                        /* +0x33c: -1 from the constructor */
    float unknown340;                      /* +0x340: 1 from the constructor */
    u8 unknown344[0x4];
    int unknown348; /* +0x348: 0 from the constructor */
    u8 unknown34c[0x4];
    Array01343a80<Name> names350; /* +0x350 */
};

#endif
