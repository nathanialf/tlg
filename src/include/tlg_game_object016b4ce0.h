/* src/include/tlg_game_object016b4ce0.h: the class whose vtable is at
 * 0x16b4ce0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4CE0_H
#define TLG_GAME_OBJECT016B4CE0_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object Object016b4ce0 holds, found by the int at +0x310
 * (FUN_01390e90); nothing else is traced */
struct Entry016b4ce0 : Object016b9108 /* derived name */
{
    u8 unknown24[0x2ec];
    int id310; /* +0x310 */
};

/* derived names: the class whose vtable is at 0x16b4ce0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b12590
 * and its destructor 0xb129d0, its row named for it, D15), 0x100 bytes (a
 * member at +0x98 of Object00875120, leaf_00875120.cpp); the destructor is
 * not written. Its fields are traced only where FUN_00b12e50 and
 * FUN_01390e90 read them: the last entry found at +0x10, the entries at
 * +0x20, the counted reference at +0x98. */
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
    AtomicRef0045c470<Object016b9108> found10; /* +0x10 */
    u8 unknown18[0x8];
    Array05943280<Entry016b4ce0 *> entries; /* +0x20 */
    u8 unknown38[0x60];
    AtomicRef0045c470<Object016b9108> held98; /* +0x98 */
    u8 unknownA0[0x60];
};

/* derived name: called with 1 by stop(); not traced */
void FUN_00b127e0(Object016b4ce0 *self, int unknown);

/* derived name: a counted reference another thread may replace, emptied by
 * stop(); its readers are not traced */
extern AtomicRef0045c470<Object016b9108> D_5832910;

#endif
