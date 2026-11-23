/* src/include/tlg_game_object016d7a28.h: the polymorphic members of the
 * classes whose destructors are 0x1281820, 0x10351b0 and 0x1016ab0 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D7A28_H
#define TLG_GAME_OBJECT016D7A28_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_object0140ccc0.h"
#include "tlg_game_object016d7eb0.h"

/* derived names: the member whose complete destructor is 0x13f4200 (its row
 * named for it, D15): at +0xe0 of the classes below. Not polymorphic; not
 * written, and its fields are not traced. */
class Object013f4200 /* derived name */
{
  public:
    ~Object013f4200();

  private:
    u8 unknown0[0x450];
};

/* derived names: the class whose vtable is at 0x16d7a28
 * (config/vtables.derived.base.txt): three slots (FUN_013e7660,
 * FUN_01486d60, FUN_001af750), no destructor among them, the fields of
 * Object016d7eb0 (tlg_game_object016d7eb0.h). Its destructor is inlined in
 * FUN_01281820 (the vtable kept in r12). The slots are not written; the rest
 * is not traced. */
class Object016d7a28 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_013e7660 here; not traced */
    virtual void FUN_01486d60(); /* slot 1; not traced */
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

/* derived names: the class over it whose vtable is at 0x16d7a50
 * (config/vtables.derived.base.txt): slot 1 its own (FUN_01487000), slot 3
 * too (FUN_014873b0). Its destructor, inlined in FUN_01281820 (the member at
 * +0xc40), stores that vtable and releases the block at +0xa8 before its
 * base's. The slots are not written; the rest is not traced. */
class Object016d7a50 : public Object016d7a28 /* derived name */
{
  public:
    virtual void FUN_01486d60(); /* derived name: slot 1, FUN_01487000 here; not traced */
    virtual void FUN_014873b0(); /* slot 3; not traced */

  private:
    u8 unknowna0[0x8];
    OwnedBlock05943280 blocka8; /* +0xa8 */
};

/* derived names: the class whose vtable is at 0x16d7a88
 * (config/vtables.derived.base.txt; slots FUN_013e8390, FUN_013e84b0,
 * FUN_001af750, FUN_01486be0): its destructor, inlined in FUN_01281820 (the
 * member at +0x250), stores the vtable and destroys the parts at +0x530
 * (FUN_013e8670) and +0xe0 (FUN_013f4200). The slots are not written; the
 * rest is not traced. */
class Object016d7a88 /* derived name */
{
  public:
    virtual void FUN_013e8390(); /* slot 0; not traced */
    virtual void FUN_013e84b0(); /* slot 1; not traced */
    virtual void FUN_001af750(); /* slot 2; not traced */
    virtual void FUN_01486be0(); /* slot 3; not traced */

  private:
    u8 unknown8[0xd8];
    Object013f4200 parte0;  /* +0xe0 */
    Object013e8670 part530; /* +0x530 */
};

/* derived names: the class whose vtable is at 0x16d5498
 * (config/vtables.derived.base.txt): three slots (FUN_013e7660,
 * FUN_013f5820, FUN_001af750), no destructor among them, the fields of
 * Object016d7eb0 (tlg_game_object016d7eb0.h). Its destructor is inlined in
 * FUN_010351b0 (the vtable kept in r12). The slots are not written; the rest
 * is not traced. */
class Object016d5498 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_013e7660 here; not traced */
    virtual void FUN_013f5820(); /* slot 1; not traced */
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

/* derived names: the class over it whose vtable is at 0x16d54c0
 * (config/vtables.derived.base.txt): slot 1 its own (FUN_013f5ac0), slot 3
 * too (FUN_013f5e70). Its destructor, inlined in FUN_010351b0 (the member at
 * +0xc60), stores that vtable and releases the block at +0xa8 before its
 * base's. The slots are not written; the rest is not traced. */
class Object016d54c0 : public Object016d5498 /* derived name */
{
  public:
    virtual void FUN_013f5820(); /* derived name: slot 1, FUN_013f5ac0 here; not traced */
    virtual void FUN_013f5e70(); /* slot 3; not traced */

  private:
    u8 unknowna0[0x8];
    OwnedBlock05943280 blocka8; /* +0xa8 */
};

/* derived names: the class whose vtable is at 0x16d54f8
 * (config/vtables.derived.base.txt; slots FUN_013e8390, FUN_013e84b0,
 * FUN_001af750, FUN_013f56a0): its destructor, inlined in FUN_010351b0 (the
 * member at +0x270), stores the vtable and destroys the parts at +0x530
 * (FUN_013e8670) and +0xe0 (FUN_013f4200). The slots are not written; the
 * rest is not traced. */
class Object016d54f8 /* derived name */
{
  public:
    virtual void FUN_013e8390(); /* slot 0; not traced */
    virtual void FUN_013e84b0(); /* slot 1; not traced */
    virtual void FUN_001af750(); /* slot 2; not traced */
    virtual void FUN_013f56a0(); /* slot 3; not traced */

  private:
    u8 unknown8[0xd8];
    Object013f4200 parte0;  /* +0xe0 */
    Object013e8670 part530; /* +0x530 */
};

/* derived names: the class whose vtable is at 0x16d52c8
 * (config/vtables.derived.base.txt): three slots (FUN_013e7660,
 * FUN_013f0120, FUN_001af750), no destructor among them, the fields of
 * Object016d7eb0 (tlg_game_object016d7eb0.h). Its destructor is inlined in
 * FUN_01016ab0 (the vtable kept in r12). The slots are not written; the rest
 * is not traced. */
class Object016d52c8 /* derived name */
{
  public:
    virtual void slot0();        /* derived name: slot 0, FUN_013e7660 here; not traced */
    virtual void FUN_013f0120(); /* slot 1; not traced */
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

/* derived names: the class over it whose vtable is at 0x16d52f0
 * (config/vtables.derived.base.txt): slot 1 its own (FUN_013f03c0), slot 3
 * too (FUN_013f0770). Its destructor, inlined in FUN_01016ab0 (the member at
 * +0x2b0), stores that vtable and releases the block at +0xa8 before its
 * base's. The slots are not written; the rest is not traced. */
class Object016d52f0 : public Object016d52c8 /* derived name */
{
  public:
    virtual void FUN_013f0120(); /* derived name: slot 1, FUN_013f03c0 here; not traced */
    virtual void FUN_013f0770(); /* slot 3; not traced */

  private:
    u8 unknowna0[0x8];
    OwnedBlock05943280 blocka8; /* +0xa8 */
};

#endif
