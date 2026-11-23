/* src/include/tlg_game_object016ce240.h: the class whose vtable is at
 * 0x16ce240 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE240_H
#define TLG_GAME_OBJECT016CE240_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: an entry of the table of Object016ce240, 0x18 bytes: Names
 * at +0x4 and +0x8 (released last first when it is emptied), the next entry
 * at +0x10 */
struct Entry016ce240 {
    u32 hash;   /* +0x0 */
    Name name4; /* +0x4 */
    Name name8; /* +0x8 */
    u8 unknownc[0x4];
    Entry016ce240 *next; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16ce240
 * (config/vtables.derived.base.txt, stored by its creator FUN_00a17690,
 * leaf_00a17690.cpp, and its destructor FUN_0138a8c0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x328 bytes: from the constructor: empty Names at +0x24 and
 * +0x28, locked arrays at +0x38, +0x70 and +0x88 (their elements have no
 * destructor; not traced), empty counted references at +0x60, +0x68 and
 * +0xa0, a table of 64 buckets of 0x18-byte entries at +0xa8 (NameTable;
 * one memset from +0xa0), empty Names at +0x2c8 and +0x2cc, 0 at +0x30c
 * and a locked array of Names at +0x310; then FUN_00a17930 runs over the
 * object. The destructor is implicit: the complete one, FUN_0138a890, is
 * a jump to the base-object one, FUN_0138a8c0 (the array of Names, the
 * Names, the table emptied and its blocks freed, the references and
 * arrays last to first, then the root's destructor in line), and the
 * deleting one, FUN_0138a8a0, calls it: its cost is over the inline limit
 * of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016ce240 : public Object016b9108 /* derived name */
{
  public:
    Object016ce240(const Name &name) : Object016b9108(name), unknown30c(0)
    {
        FUN_00a17930();
    }

    void FUN_00a17930(); /* derived name; not traced */

  private:
    Name name24; /* +0x24 */
    Name name28; /* +0x28 */
    u8 unknown2c[0xc];
    Array01343a80<int> unknown38; /* +0x38: the element not traced */
    u8 unknown50[0x10];
    Ref00503fb0<Object016b9108> unknown60; /* +0x60 */
    Ref00503fb0<Object016b9108> unknown68; /* +0x68 */
    Array01343a80<int> unknown70;          /* +0x70: the element not traced */
    Array01343a80<int> unknown88;          /* +0x88: the element not traced */
    Ref00503fb0<Object016b9108> unknowna0; /* +0xa0 */
    NameTable<Entry016ce240, 64> tablea8;  /* +0xa8 */
    Name name2c8;                          /* +0x2c8 */
    Name name2cc;                          /* +0x2cc */
    u8 unknown2d0[0x3c];
    int unknown30c;               /* +0x30c: 0 from the constructor */
    Array01343a80<Name> names310; /* +0x310 */
};

#endif
