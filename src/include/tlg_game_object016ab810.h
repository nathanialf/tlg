/* src/include/tlg_game_object016ab810.h: the class whose vtable is at
 * 0x16ab810 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB810_H
#define TLG_GAME_OBJECT016AB810_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16ab810
 * (config/vtables.derived.base.txt, stored by its creator FUN_0057ec00, where
 * its constructor is inlined after Object016b9108Kind's), derived from Object016b9108Kind. 0x68 bytes
 * (`mov edi, 0x68` before operator new in the creator). Its fields are traced only where the creator sets them. Its destructor is its
 * key function (defined out of line, leaf_0057edc0.cpp): the deleting one
 * FUN_0057ef90 calls it. Its own slots: slot 5 the empty body at 0x1af750, slot
 * 6 FUN_00c1b350. */
class Object016ab810 : public Object016b9108Kind /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name (0 at +0x24), the vptr,
     * four floats from +0x28 (one 16-byte constant), 0.1 and 1.0, the ints 1,
     * 1 and 2 from +0x40, the array at +0x50 (its owner index from the
     * thread's heap, its lock free), then 0x6a at +0x24 */
    Object016ab810(const Name &name)
        : Object016b9108Kind(name), unknown28(0.0f), unknown2c(20.0f), unknown30(0.85f),
          unknown34(3.40282347e+38f), unknown38(0.1f), unknown3c(1.0f), unknown40(1), unknown44(1),
          unknown48(2)
    {
        kind = 0x6a;
    }

    virtual ~Object016ab810();
    virtual void slot5(); /* derived name; the empty body at 0x1af750 */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    float unknown28; /* +0x28: 0.0 from the constructor */
    float unknown2c; /* +0x2c: 20.0 from the constructor */
    float unknown30; /* +0x30: 0.85 from the constructor */
    float unknown34; /* +0x34: the largest float from the constructor */
    float unknown38; /* +0x38: 0.1 from the constructor */
    float unknown3c; /* +0x3c: 1.0 from the constructor */
    int unknown40;   /* +0x40: 1 from the constructor */
    int unknown44;   /* +0x44: 1 from the constructor */
    int unknown48;   /* +0x48: 2 from the constructor */
    u8 unknown4c[0x4];
    /* +0x50: an array of references with its lock (the word at +0x64), empty
     * from the constructor; emptied to no capacity by the destructor, then torn down (`call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array50;
};

#endif
