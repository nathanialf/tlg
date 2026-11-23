/* src/include/tlg_game_object016cbe98.h: the class whose vtable is at
 * 0x16cbe98 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBE98_H
#define TLG_GAME_OBJECT016CBE98_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016c7020.h"

/* derived name: the class of the objects the array at +0x178 of
 * Object016cbe98 holds; not traced */
class Element016cbe98;

/* derived names: the class whose vtable is at 0x16cbe98
 * (config/vtables.derived.base.txt, stored by its creator FUN_007b0720,
 * leaf_007b0720.cpp, and its destructor FUN_0136e990), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x190 bytes: from the constructor: a locked array of Names at
 * +0x28, an Object016c7020 at +0x40 (its constructor inlined), a locked
 * array of Names at +0x160 and one of counted references at +0x178, then
 * 0 at +0x24 in the body. The destructor is written in the class: it empties the
 * array of references first; the complete one, FUN_0136e980, is a jump to
 * the base-object one, FUN_0136e990 (the array emptied, then the members
 * last to first, Object016c7020's destructor in line, then the root's), and
 * the deleting one, FUN_0136edf0, calls it (its cost is over the 225 of a
 * body written in the class). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016cbe98 : public Object016b9108 /* derived name */
{
  public:
    Object016cbe98(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0;
    }

    /* the references emptied and their block given back first (Array::
     * clear(), `mov dword [r14+0x180], 0; cmp dword [r14+0x184], 0`), then
     * the members destroyed */
    virtual ~Object016cbe98()
    {
        references178.clear();
    }

  private:
    int unknown24;                /* +0x24: 0 from the constructor's body */
    Array01343a80<Name> names28;  /* +0x28 */
    Object016c7020 unknown40;     /* +0x40 */
    Array01343a80<Name> names160; /* +0x160 */
    Array01343a80<Ref00503fb0<Element016cbe98>> references178; /* +0x178 */
};

#endif
