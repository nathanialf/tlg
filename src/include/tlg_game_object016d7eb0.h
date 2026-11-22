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
    Array05943280<Array05943280<Pair014715d0>> lists28;
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
    Array05943280<Array05943280<Float4A>> listsa0;
    OwnedBlock05943280 blockb8; /* +0xb8 */
    u8 unknownc0[0xb0];
};

#endif
