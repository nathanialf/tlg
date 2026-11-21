/* src/include/tlg_game_object016b4ce0.h: the class whose vtable is at
 * 0x16b4ce0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4CE0_H
#define TLG_GAME_OBJECT016B4CE0_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: an object Object016b4ce0 holds, found by the int at +0x310
 * (FUN_01390e90); nothing else is traced */
struct Entry016b4ce0 : Object016b9108 /* derived name */
{
    u8 unknown24[0x2ec];
    int id310; /* +0x310 */
};

/* derived names: a record of the array at +0xa0, 40 bytes (`lea rsi,
 * [rcx + 4*rcx]` over the index, then `[rdx + 8*rsi]`), a name at +0x0
 * the only part with a destructor; the rest is not traced */
struct RecordA0016b4ce0 { /* derived name */
    Name name;            /* +0x0 */
    u8 unknown4[0x24];
};

/* derived names: the class whose vtable is at 0x16b4ce0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b12590
 * and its destructor 0xb129d0, its row named for it, D15), 0x100 bytes (a
 * member at +0x98 of Object00875120, leaf_00875120.cpp). Its fields are
 * traced where FUN_00b12e50 and FUN_01390e90 read them and where the
 * destructor (leaf_00b129d0.cpp) tears them down: the last entry found at
 * +0x10, a counted reference at +0x18, the entries at +0x20 (counted
 * references: their array's destructor is 0x134f620), an array of arrays of
 * counted references at +0x38, three more at +0x50, +0x68 and +0x80, the
 * counted reference at +0x98, the records at +0xa0, two arrays of names at
 * +0xc0 and +0xd8 and a heap block at +0xf8. */
class Object016b4ce0 /* derived name */
{
  public:
    virtual ~Object016b4ce0();

    /* 0xb12e50: FUN_00b127e0 with 1, then the reference at 0x5832910 and
     * the one at +0x98 emptied (the destructor calls it first; so does
     * FUN_001f4f10 for the member at +0x98 of the object at +0xf0 of its
     * own) */
    void stop(); /* derived name */

    /* 0x1390e90: the entry whose int at +0x310 is `id`: the last one found
     * when it is, else the first of the array, kept as the last found; null
     * when none is (its callers pass the pointer at 0x581e3a8) */
    Entry016b4ce0 *find(const int &id); /* derived name */

  private:
    u8 unknown8[0x8];
    AtomicRef0045c470<Object016b9108> found10;                          /* +0x10 */
    Ref00503fb0<Object016b9108> held18;                                 /* +0x18 */
    Array05943280<Ref00503fb0<Object016b9108>> entries;                 /* +0x20 */
    Array05943280<Array05943280<Ref00503fb0<Object016b9108>>> arrays38; /* +0x38 */
    Array05943280<Ref00503fb0<Object016b9108>> array50;                 /* +0x50 */
    Array05943280<Ref00503fb0<Object016b9108>> array68;                 /* +0x68 */
    Array05943280<Ref00503fb0<Object016b9108>> array80;                 /* +0x80 */
    AtomicRef0045c470<Object016b9108> held98;                           /* +0x98 */
    Array05943280<RecordA0016b4ce0> recordsA0;                          /* +0xa0 */
    u8 unknownB8[0x8];
    Array05943280<Name> namesC0; /* +0xc0 */
    Array05943280<Name> namesD8; /* +0xd8 */
    u8 unknownF0[0x8];
    OwnedBlock05943280 blockF8; /* +0xf8 */
};

/* derived name: called with 1 by stop(); not traced */
void FUN_00b127e0(Object016b4ce0 *self, int unknown);

/* derived name: a counted reference another thread may replace, emptied by
 * stop(); its readers are not traced */
extern AtomicRef0045c470<Object016b9108> D_5832910;

#endif
