/* src/include/tlg_game_object016d7eb0.h: the two members at +0x220 and
 * +0x390 of the class whose destructor is 0x12ec7e0 and their base (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D7EB0_H
#define TLG_GAME_OBJECT016D7EB0_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16d7eb0
 * (config/vtables.derived.base.txt): three slots (FUN_013e7660,
 * FUN_01495b90, FUN_001af750), no destructor among them. Its destructor,
 * inlined in FUN_012ec7e0 (the vtable kept in r13), stores the vtable and
 * releases the blocks at +0x80 and +0x40, the array at +0x28 (24-byte
 * elements, each a block) and the block at +0x10. The slots are not
 * written; the rest is not traced. */
class Object016d7eb0 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_013e7660 here; not traced */
    virtual void FUN_01495b90(); /* slot 1; not traced */
    virtual void FUN_001af750(); /* slot 2; not traced */

  private:
    u8 unknown8[0x8];
    OwnedBlock05943280 block10; /* +0x10 */
    u8 unknown18[0x10];
    Array05943280<Array05943280<int>> lists28; /* +0x28 */
    OwnedBlock05943280 block40;                /* +0x40 */
    u8 unknown48[0x38];
    OwnedBlock05943280 block80; /* +0x80 */
    u8 unknown88[0x18];
};

/* derived names: the class over it whose vtable is at 0x16d7e68
 * (config/vtables.derived.base.txt): slot 1 is its own (FUN_01495e30), slot
 * 3 too (FUN_01496290). Its destructor, inlined twice in FUN_012ec7e0
 * (`mov [r14+0x390], rax` and `mov [r14+0x220], rax`), stores that vtable and releases the block at +0xb8 and the
 * array at +0xa0 (24-byte elements, each a block) before its base's. The
 * slots are not written; the rest is not traced. */
class Object016d7e68 : public Object016d7eb0 /* derived name */
{
  public:
    virtual void FUN_01495b90(); /* derived name: slot 1, FUN_01495e30 here; not traced */
    virtual void FUN_01496290(); /* slot 3; not traced */

  private:
    Array05943280<Array05943280<int>> listsa0; /* +0xa0 */
    OwnedBlock05943280 blockb8;                /* +0xb8 */
    u8 unknownc0[0xb0];
};

#endif
