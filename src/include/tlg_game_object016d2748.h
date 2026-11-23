/* src/include/tlg_game_object016d2748.h: the class whose vtable is at
 * 0x16d2748 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D2748_H
#define TLG_GAME_OBJECT016D2748_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16d2748
 * (config/vtables.derived.base.txt, stored by its creator FUN_00d7f280,
 * leaf_00d7f280.cpp, and its destructor FUN_013bbd00), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0xe0 bytes: from the constructor: (1, 1, 0, 1) at +0x30, zeros
 * at +0x40, 1 at +0x50, a locked array at +0xa8 (its elements have no
 * destructor; not traced) and two empty counted references at +0xc8 and
 * +0xd0, then, in its body, the 84 bytes from +0x54 cleared (the base's
 * 32-byte stores, the last overlapping, come after the array's: a memset
 * of its own, not merged with the members' zero stores). The destructor
 * is implicit: the complete one, FUN_013bbcd0, is a jump to the
 * base-object one, FUN_013bbd00 (the references released last to first,
 * the array's block, then the root's destructor in line), and the
 * deleting one, FUN_013bbce0, calls it: its cost is over the inline limit
 * of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016d2748 : public Object016b9108 /* derived name */
{
  public:
    Object016d2748(const Name &name)
        : Object016b9108(name), unknown30(1.0f, 1.0f, 0.0f, 1.0f),
          unknown40(0.0f, 0.0f, 0.0f, 0.0f), unknown50(1.0f)
    {
        memset(unknown54, 0, sizeof(unknown54));
    }

  private:
    u8 unknown24[0xc];
    Float4 unknown30;             /* +0x30: (1, 1, 0, 1) from the constructor */
    Float4 unknown40;             /* +0x40: zeros from the constructor */
    float unknown50;              /* +0x50: 1 from the constructor */
    float unknown54[21];          /* +0x54: zeros from the constructor's body; not traced */
    Array01343a80<int> unknowna8; /* +0xa8: the element not traced */
    u8 unknownc0[0x8];
    Ref00503fb0<Object016b9108> unknownc8; /* +0xc8 */
    Ref00503fb0<Object016b9108> unknownd0; /* +0xd0 */
    u8 unknownd8[0x8];
};

#endif
