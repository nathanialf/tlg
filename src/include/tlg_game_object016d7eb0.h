/* src/include/tlg_game_object016d7eb0.h: the two members at +0x220 and
 * +0x390 of the class whose destructor is 0x12ec7e0 and their base (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D7EB0_H
#define TLG_GAME_OBJECT016D7EB0_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16d7eb0
 * (config/vtables.derived.base.txt): three slots (FUN_013e7660,
 * FUN_01495b90, FUN_001af750), no destructor among them. Its destructor,
 * inlined in FUN_012ec7e0 (the vtable kept in r13), stores the vtable and
 * releases the blocks at +0x80 and +0x40, the array at +0x28 (24-byte
 * elements, each a block) and the block at +0x10. The slots are not
 * written; the rest is not traced. */
/* derived names: an element of the lists at +0x28: two aligned four-float
 * values (32 bytes), assigned one value at a time (two `vmovaps` pairs from
 * one source address, 0x14715f3; the implicit assignment is one 32-byte
 * copy, `vmovups ymm0`); not traced further */
struct Pair014715d0 { /* derived name */

    Pair014715d0 &operator=(const Pair014715d0 &other)
    {
        first = other.first;
        second = other.second;
        return *this;
    }

    Float4A first;
    Float4A second;
};

/* derived names: the lists at +0x28 and at +0xa0: a list made with two
 * elements, its capacity made 2 exactly and both default-constructed: the
 * constructors FUN_013e72e0 (pairs, a 0x40-byte block: the zero vector and
 * the vector at 0x5acf2c0) and FUN_013fcc20 (vectors, a 0x20-byte block:
 * zero), of the same shape, out of line in the stretch of inline functions,
 * called for each list by the outer arrays' resize (FUN_013e71b0,
 * FUN_0108d540). Not the array template: that one starts empty. The list
 * gives its block back through FUN_00ebf3f0, a block's release outside the
 * arrays (tlg_game_block.h); its elements need no destructor. With it the
 * destructors of the classes that hold these lists are inlined whole where
 * the base has them (FUN_01016ab0, FUN_010351b0, FUN_01281820); with the
 * array template's inline release they stay calls. The slot 1 copies
 * (FUN_013f0120 and five of the same bytes) store the pairs at a stride of
 * 32 (`shl rcx, 5`) in lists 24 bytes apart. The constructors are not
 * written. */
template <class T> class List013e72e0 /* derived name */
{
  public:
    List013e72e0();

    ~List013e72e0()
    {
        FUN_00ebf3f0(items);
    }

    T &at(int index)
    {
        return items[index];
    }

  private:
    T *items;           /* +0x0 */
    unsigned count;     /* +0x8 */
    unsigned capacity;  /* +0xc */
    unsigned allocator; /* +0x10 */
};

class Object016d7eb0 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_013e7660 here; not traced */
    virtual void FUN_01495b90(); /* slot 1; not traced */
    virtual void FUN_001af750(); /* slot 2; not traced */

  protected:
    u8 unknown8[0x8];
    OwnedBlock05943280 block10; /* +0x10 */
    u8 unknown18[0x10];
    /* +0x28: five lists (at least: slot 5 of 0x16d7e68 copies within five),
     * each a block; their elements are 32 bytes */
    Array05943280<List013e72e0<Pair014715d0>> lists28;
    OwnedBlock05943280 block40; /* +0x40 */
    u8 unknown48[0x38];
    OwnedBlock05943280 block80; /* +0x80 */
    u8 unknown88[0x18];
};

/* derived names: the class over it whose vtable is at 0x16d7e68
 * (config/vtables.derived.base.txt): slot 1 is its own (FUN_01495e30), slot
 * 3 too (FUN_01496290). Its destructor, inlined twice in FUN_012ec7e0
 * (`mov [r14+0x390], rax` and `mov [r14+0x220], rax`), stores that vtable and releases the block at +0xb8 and the
 * array at +0xa0 (24-byte elements, each a block) before its base's. Slots
 * 1, 3, 4 and 6 are not written; the rest is not traced. */
class Object016d7e68 : public Object016d7eb0 /* derived name */
{
  public:
    virtual void FUN_01495b90(); /* derived name: slot 1, FUN_01495e30 here; not traced */
    virtual void FUN_01496290(); /* slot 3; not traced */
    virtual void slot4();        /* derived name; FUN_014965f0, not written */
    /* slot 5, FUN_014715d0: the element `from` of each of the five lists at
     * +0x28 and at +0xa0 copied over the element `to` */
    virtual void slot5(int to, int from); /* derived name */

  private:
    /* +0xa0: five lists (at least) whose elements are 16 bytes */
    Array05943280<List013e72e0<Float4A>> listsa0;
    OwnedBlock05943280 blockb8; /* +0xb8 */
    u8 unknownc0[0xb0];
};

#endif
