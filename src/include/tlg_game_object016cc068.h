/* src/include/tlg_game_object016cc068.h: the class whose vtable is at
 * 0x16cc068 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC068_H
#define TLG_GAME_OBJECT016CC068_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16cc068
 * (config/vtables.derived.base.txt, stored by its creator FUN_008587e0,
 * leaf_008587e0.cpp, and its destructor FUN_013710e0), derived from
 * Object01343880: its nine slots are the two destructors and the base's
 * seven. 0x160 bytes: from the constructor: zeros from +0x34, -1 at
 * +0x54, then zeros to +0x148 (one memset from +0x58: 32-byte stores, the
 * last overlapping) holding the Names at +0x60 and +0xb4 and the block,
 * count and capacity of a locked array of Names at +0x130, then zeros at
 * +0x148 and 0 at +0x158; the other fields are not traced. The destructor
 * is implicit: the complete one, FUN_013710d0, is a jump to the
 * base-object one, FUN_013710e0 (the array of Names, its elements
 * released, then the two Names, then the root's destructor in line), and
 * the deleting one, FUN_01371290, calls it: its cost is over the inline
 * limit of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016cc068 : public Object01343880 /* derived name */
{
  public:
    Object016cc068(const Name &name)
        : Object01343880(name), unknown34(), unknown54(-1), unknown58(), unknown64(), unknownb8(),
          unknown148(), unknown158(0)
    {
    }

  private:
    int unknown34[8];             /* +0x34: zeros from the constructor; not traced */
    int unknown54;                /* +0x54: -1 from the constructor */
    int unknown58[2];             /* +0x58: zeros from the constructor; not traced */
    Name name60;                  /* +0x60 */
    int unknown64[20];            /* +0x64: zeros from the constructor; not traced */
    Name nameb4;                  /* +0xb4 */
    int unknownb8[30];            /* +0xb8: zeros from the constructor; not traced */
    Array01343a80<Name> names130; /* +0x130 */
    int unknown148[4];            /* +0x148: zeros from the constructor; not traced */
    int unknown158;               /* +0x158: 0 from the constructor */
    u8 unknown15c[0x4];
};

#endif
