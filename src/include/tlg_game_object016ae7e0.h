/* src/include/tlg_game_object016ae7e0.h: the class whose vtable is at
 * 0x16ae7e0, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE7E0_H
#define TLG_GAME_OBJECT016AE7E0_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_array01343a80.h"

/* derived names: the class whose vtable is at 0x16ae7e0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00818b00 and
 * its complete destructor 0x818d10, its row named for it, D15), derived from
 * Object016b9108 (the creator calls 0xcb6310 on the new object, the
 * destructor ends in that class's: the vptr 0x16b9118, the names at +0x10
 * and +0xc). 0x9c bytes of data: the creator allocates 0xa0 and stores
 * +0x98 last, and the class at 0x16ae838 (leaf_008190a0.cpp) keeps a name
 * at +0x9c, in the tail. The classes derived from it tail-call its
 * destructor from their own. Only the members the destructor releases are
 * traced; the creator zeroes +0x28, +0x50 to +0x60 and +0x98, makes the
 * arrays' locks free (+0x7c, +0x94) and stores a constant at +0x30 (0x1537fd0: its +0x3c is 1). The slots from 5 on
 * (0x58a0, 0x1343880, 0x818e60, 0x818e90) are not traced. */
class Object016ae7e0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ae7e0(); /* 0x818d10 */

  private:
    u8 unknown24[0x14];
    Name name38; /* +0x38: released by the destructor, last of its names */
    u8 unknown3c[0x18];
    Name name54; /* +0x54 */
    Name name58; /* +0x58: the first name released */
    u8 unknown5c[0xc];
    Array01343a80<Ref00503fb0<Object016b9108>> held68; /* +0x68: released after +0x80 */
    Array01343a80<Ref00503fb0<Object016b9108>> held80; /* +0x80: the first member released */
    int unknown98;                                     /* +0x98: zero from the creator */
};

#endif
