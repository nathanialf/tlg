/* src/include/tlg_game_object016d6730.h: the members at +0x4a0 and +0x2d0
 * of the classes whose destructors are 0x11cf340 and 0x129f5b0 and their
 * bases (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D6730_H
#define TLG_GAME_OBJECT016D6730_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_object0140ccc0.h"
#include "tlg_game_object016d7eb0.h"

/* derived names: the class whose vtable is at 0x16d6708
 * (config/vtables.derived.base.txt): three slots (FUN_013e7660,
 * FUN_01473dd0, FUN_001af750), no destructor among them. The destructor,
 * inlined at 0x11cf58a, stores the vtable and releases the arrays at +0x80
 * and +0x40, the array of lists at +0x28 (24-byte elements, each a list)
 * and the array at +0x10: the fields of Object016d7eb0
 * (tlg_game_object016d7eb0.h). The rest is not traced. */
class Object016d6708 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_013e7660 here; not traced */
    virtual void FUN_01473dd0(); /* slot 1; not traced */
    virtual void FUN_001af750(); /* slot 2; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<u32>
        values10; /* +0x10: 4-byte values, made one for each key (the count at +0x98) */
    Array05943280<List013e72e0<Pair014715d0>> lists28; /* +0x28: tlg_game_object016d7eb0.h */
    Array05943280<Pair014715d0> pairs40;               /* +0x40: made one for each key */
    u8 unknown58[0x28];
    Array05943280<u32> values80; /* +0x80: 4-byte values, made one for each key */
    u8 unknown98[0x80];
};

/* derived names: the class over it whose vtable is at 0x16d6730
 * (config/vtables.derived.base.txt): slot 0 is its own (FUN_01471f40), slot
 * 3 its own (FUN_014741f0). Its destructor, inlined at 0x11cf501, stores
 * that vtable and releases the blocks at +0x138 and +0x118. The two slots
 * are not written; the rest is not traced. */
class Object016d6730 : public Object016d6708 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_01471f40 here; not traced */
    virtual void FUN_014741f0(); /* slot 3; not traced */

  private:
    OwnedBlock05943280 block118; /* +0x118 */
    u8 unknown120[0x18];
    OwnedBlock05943280 block138; /* +0x138 */
    u8 unknown140[0x80];
};

/* derived names: the member at +0x4a0 of the class whose destructor is
 * 0x11cf340: a class over Object016d6730 with no slot of its own, so its
 * vtable has the same content as its base's: the base stores ONE address
 * for both (0x16d6730: `lea rbx, [rip+...]; mov [r14+0x4a0], rbx` at
 * 0x11cf4a6, again at 0x11cf501 after its own members; the constructor
 * 0x11ce120 likewise). Its destructor releases the part at +0x1540
 * (FUN_0140ccc0) and the block at +0x1c0. The rest is not traced. */
class Member011cf340 : public Object016d6730 /* derived name */
{
  private:
    OwnedBlock05943280 block1c0; /* +0x1c0 */
    u8 unknown1c8[0x1378];
    Object0140ccc0 part1540; /* +0x1540 */
};

/* derived names: the member at +0x2d0 of the class whose destructor is
 * 0x129f5b0 and its two bases, the same construction: the class whose
 * vtable is at 0x16d7bb0 (slots FUN_013e7660, FUN_0148a850, FUN_001af750;
 * the fields of Object016d6708), the class over it whose vtable is at
 * 0x16d7bd8 (the same three slots in the base: its slot 1 is its own, of
 * the same bytes; blocks at +0xa8 and +0xc8), and the member over that
 * with no slot of its own (a block at +0x2e0, the part at +0x300 destroyed
 * by FUN_013f7ea0): 0x16d7bd8 is stored for both (0x129f716, 0x129f771). */
class Object016d7bb0 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_013e7660 here; not traced */
    virtual void FUN_0148a850(); /* slot 1; not traced */
    virtual void FUN_001af750(); /* slot 2; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<u32>
        values10; /* +0x10: 4-byte values, made one for each key (the count at +0x98) */
    Array05943280<List013e72e0<Pair014715d0>> lists28; /* +0x28: tlg_game_object016d7eb0.h */
    Array05943280<Pair014715d0> pairs40;               /* +0x40: made one for each key */
    u8 unknown58[0x28];
    Array05943280<u32> values80; /* +0x80: 4-byte values, made one for each key */
    u8 unknown98[0x8];
};

class Object016d7bd8 : public Object016d7bb0 /* derived name */
{
  public:
    virtual void FUN_0148a850(); /* derived name: slot 1; not traced */

  private:
    u8 unknowna0[0x8];
    OwnedBlock05943280 blocka8; /* +0xa8 */
    u8 unknownb0[0x18];
    OwnedBlock05943280 blockc8; /* +0xc8 */
};

/* derived names: the part at +0x300 of the member below (FUN_013f7ea0, its
 * row named for it, D15); not written, not traced */
class Object013f7ea0 /* derived name */
{
  public:
    ~Object013f7ea0();

  private:
    u8 unknown0[0x10];
};

class Member0129f5b0 : public Object016d7bd8 /* derived name */
{
  private:
    u8 unknownd0[0x210];
    OwnedBlock05943280 block2e0; /* +0x2e0 */
    u8 unknown2e8[0x18];
    Object013f7ea0 part300; /* +0x300 */
};

#endif
