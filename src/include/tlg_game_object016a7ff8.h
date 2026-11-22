/* src/include/tlg_game_object016a7ff8.h: the class whose vtable is at 0x16a7ff8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7FF8_H
#define TLG_GAME_OBJECT016A7FF8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_math.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7ff8
 * (config/vtables.derived.base.txt, stored by FUN_002bc420 FUN_002bc5b0), 0x90 bytes
 * (`mov edi, 0x90` before operator new in its creator FUN_002bc2c0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002bc420 and its destructor FUN_002bc5b0, the key function, are in
 * leaf_002bc5b0.cpp: each puts the fields back to empty (reset(), the
 * array given room for 10 by the constructor and none by the destructor,
 * which first hands the object to FUN_002bc7f0). */
class Object016a7ff8 : public Object016b9108 /* derived name */
{
  public:
    Object016a7ff8(const Name &name); /* FUN_002bc420 */
    virtual ~Object016a7ff8();

  private:
    /* the ints at +0x24 to +0x2c cleared, the array emptied to `capacity`,
     * the reference at +0x48 emptied by compare-and-swap, +0x50 cleared,
     * the Name emptied */
    void reset(unsigned capacity); /* derived name */

    int unknown24; /* +0x24: FUN_002bc7f0 tests it for 1; not traced */
    int unknown28; /* +0x28: not traced */
    int unknown2c; /* +0x2c: not traced */
    Array01343a80<Ref00503fb0<Object016b9108>> array30; /* +0x30 */
    AtomicRef0045c470<Object016b9108> held48;           /* +0x48 */
    void *unknown50;                                    /* +0x50: not traced */
    Name name58;                                        /* +0x58 */
    Float4A unknown60; /* +0x60: (0, 0, 0, 1) from the constructor; not traced */
    Float4A unknown70; /* +0x70: (0, 0, 0, 1) from the constructor; not traced */
    void *unknown80;   /* +0x80: an object FUN_002bc7f0 sets flags of; not traced */
    u8 unknown88[0x8];
};

#endif
