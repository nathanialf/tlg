/* src/include/tlg_game_object016b85e0.h: the class whose vtable is at
 * 0x16b85e0, a base of many game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B85E0_H
#define TLG_GAME_OBJECT016B85E0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b85e0
 * (config/vtables.derived.base.txt, stored by its constructor 0xc55320 and
 * its complete destructor 0xc55550; both rows named for it, D15), derived
 * from the root class Object016b9108: the constructor first runs the root's
 * (`call 0xcb6310` with the name it was given), the destructor ends in the
 * root's body (the names at +0x10 and +0xc dropped), and slot 2 of the
 * vtable is the root's release 0xcb66f0. Its own fields begin at +0x24, in
 * the root's tail padding, and end at +0x238 (the constructor's last store,
 * a quadword at +0x230); they are not traced, and the classes derived from
 * it declare them in their first pad. The classes derived from it tail-call
 * the destructor from their own (leaf_0080b1e0.cpp and the files that
 * include this header). The destructor is not written, so nothing here
 * emits the vtable. */
class Object016b85e0 : public Object016b9108 /* derived name */
{
  public:
    Object016b85e0(const Name &name); /* 0xc55320, its row named after it (D15) */
    virtual ~Object016b85e0();
    /* slots 3 and 4 of 0x16b85e0: FUN_0134a390 and FUN_0134a3a0, in place
     * of the root's empty bodies; parameters not traced */
    virtual void slot3(); /* derived name; FUN_0134a390 */
    virtual void slot4(); /* derived name; FUN_0134a3a0 */
    /* slots 5 to 9, the class's own (slots 8 and 9 the empty body at
     * 0x1af750); the parameters of 7 to 9 not traced. Slot 5 adds a child
     * (FUN_00c573b0: one with no parent at its +0x28, under this object's
     * lock at +0x30), slot 6 takes one out (FUN_00c575d0: only a child whose
     * parent is this object); the classes derived from it call both under
     * the world's write lock (FUN_00b44ec0, FUN_00b45280) */
    virtual void addChild(Object016b9108 *child);    /* derived name; FUN_00c573b0 */
    virtual void removeChild(Object016b9108 *child); /* derived name; FUN_00c575d0 */
    virtual void slot7();                            /* derived name; FUN_00c59010 */
    virtual void slot8();                            /* derived name; 0x1af750 */
    virtual void slot9();                            /* derived name; 0x1af750 */
};

#endif
