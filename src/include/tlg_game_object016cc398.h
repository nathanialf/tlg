/* src/include/tlg_game_object016cc398.h: the class whose vtable is at
 * 0x16cc398, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC398_H
#define TLG_GAME_OBJECT016CC398_H

#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"

/* derived names: the record FUN_013b2e90 works on (leaf_00812390.cpp's) */
struct Object013b2e90 /* derived name */
{
    u8 unknown0[0x18];
};

void FUN_013b2e90(Object013b2e90 *self); /* derived name */

/* derived names: the class whose vtable is at 0x16cc398
 * (config/vtables.derived.base.txt), over the root class (its slots 2 to 4
 * are the root's, and the root's destructor follows inline in its own: the
 * vptr store, then the two names): a record at +0x38 and the heap block it
 * owns at +0x50, as leaf_00812390.cpp's class holds them; the rest is not
 * traced. Its destructor is inline (below): the class has no key function,
 * so a unit that stores its vtable emits the vtable and both destructors
 * (0xb225a0, 0xb22670), and the classes derived from it with an empty
 * destructor hold its body (0x8f5760). */
class Object016b8d40;

class Object016cc398 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cc398();
    /* slots 5 to 11: 0x40b0 (true) and empty bodies (0x1af750) in this
     * class's vtable; the classes derived from it override some */
    virtual bool slot5(); /* derived name */
    virtual void slot6(); /* derived name; not traced */
    /* slots 7 and 8: an Object016b8d40 of this object's type name added to
     * and taken from the list at +0x38 (0xca34c0 calls slot 7 with the new
     * object in rsi after linking it; 0xca38f0 calls slot 8 with the object
     * being destroyed) */
    virtual void slot7(Object016b8d40 *object); /* derived name */
    virtual void slot8(Object016b8d40 *object); /* derived name */
    virtual void slot9();                       /* derived name */
    virtual void slot10();                      /* derived name */
    virtual void slot11();                      /* derived name; not traced */

  private:
    u8 unknown24[0x14];
    Object013b2e90 unknown38; /* +0x38 */
    void *block50;            /* +0x50 */
};

/* derived names: the complete destructor: FUN_013b2e90 on the record, the
 * block released (tlg_game_block.h), then the root's destructor inline */
inline Object016cc398::~Object016cc398()
{
    FUN_013b2e90(&unknown38);
    FUN_00ebf3f0(block50);
}

#endif
