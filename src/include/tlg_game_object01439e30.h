/* src/include/tlg_game_object01439e30.h: the two 0x150-byte members whose
 * destructors are 0x1439e30 and 0x1491e40, and the 0x500-byte members their
 * holders keep before them (game region; docs/TARGETS.md). Every name here
 * is derived. */
#ifndef TLG_GAME_OBJECT01439E30_H
#define TLG_GAME_OBJECT01439E30_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_object016d7eb0.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object0139b6b0.h"

/* derived names: the class whose vtable is at 0x16d5e90 (three slots; the
 * row of config/vtables.derived.base.txt names it), the part of
 * Object016d5eb8 that FUN_01439e30 destroys after storing this vtable
 * (0x01439e30 + 0x99): four arrays, at +0x10 and +0x80 of 4-byte values (the
 * constructor FUN_014397e0 sizes them 0x14 bytes for five, aligned 4), at
 * +0x28 of lists of pairs (List013e72e0: the constructor sizes it by
 * FUN_013e71b0) and at +0x40 of 32-byte pairs (0x1439a2c: `vmovaps
 * [rdx+rcx], xmm0; vmovaps [rdx+rcx+0x10], xmm1` over `shl rcx, 5`); the
 * fields of Object016d52c8 (tlg_game_object016d7a28.h).
 * No destructor of its own in the executable. The slots are not traced. */
class Object016d5e90 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

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

/* derived names: the class whose vtable is at 0x16d5eb8 (eight slots), over
 * Object016d5e90: 0x150 bytes (two of them 0x150 apart in the class whose
 * constructor is FUN_01142c80). Its destructor FUN_01439e30 is not virtual
 * (no slot holds it) and is called by the holders' destructors; it
 * releases the block of the array of ints at +0xf0 (FUN_014397e0 sizes it
 * 0x14 bytes for five and clears them) and the block at +0xc8 (an array
 * whose elements are not traced: its allocator's index at +0xd8). */
class Object016d5eb8 : public Object016d5e90 /* derived name */
{
  public:
    ~Object016d5eb8();

    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

  private:
    u8 unknowna0[0x28];
    OwnedBlock05943280 blockc8; /* +0xc8 */
    u8 unknownd0[0x20];
    Array05943280<int> arrayf0; /* +0xf0 */
    u8 unknown108[0x48];
};

/* derived names: the class whose vtable is at 0x16d7dc0 (three slots; the
 * row of config/vtables.derived.base.txt names it), the part of
 * Object016d7de8 that FUN_01491e40 destroys after storing this vtable
 * (0x01491e40 + 0x99): four arrays, at +0x10 and +0x80 of 4-byte values (the
 * constructor FUN_014917f0 sizes them 0x14 bytes for five, aligned 4), at
 * +0x28 of lists of pairs (List013e72e0: the constructor sizes it by
 * FUN_013e71b0) and at +0x40 of 32-byte pairs (0x1439a2c: `vmovaps
 * [rdx+rcx], xmm0; vmovaps [rdx+rcx+0x10], xmm1` over `shl rcx, 5`); the
 * fields of Object016d52c8 (tlg_game_object016d7a28.h).
 * No destructor of its own in the executable. The slots are not traced. */
class Object016d7dc0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

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

/* derived names: the class whose vtable is at 0x16d7de8 (eight slots), over
 * Object016d7dc0: 0x150 bytes (two of them 0x150 apart in the class whose
 * constructor is FUN_012e12b0). Its destructor FUN_01491e40 is not virtual
 * (no slot holds it) and is called by the holders' destructors; it
 * releases the block of the array of ints at +0xf0 (FUN_014917f0 sizes it
 * 0x14 bytes for five and clears them) and the block at +0xc8 (an array
 * whose elements are not traced: its allocator's index at +0xd8). */
class Object016d7de8 : public Object016d7dc0 /* derived name */
{
  public:
    ~Object016d7de8();

    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

  private:
    u8 unknowna0[0x28];
    OwnedBlock05943280 blockc8; /* +0xc8 */
    u8 unknownd0[0x20];
    Array05943280<int> arrayf0; /* +0xf0 */
    u8 unknown108[0x48];
};

/* derived names: the class whose vtable is at 0x16d5e60 (four slots; the
 * row of config/vtables.derived.base.txt names it), the member at +0x240 of
 * the class whose destructor is FUN_011436d0, which holds its destructor
 * inlined (0x011436d0 + 0x181: the vtable stored, the block at +0x170
 * released, then `lea rdi, [r14+0x370]; call 0x134f620` and `lea rdi,
 * [r14+0x358]; call 0x1347230`: the arrays at +0x130 and +0x118). No
 * destructor of its own in the executable. 0x500 bytes to the member after
 * it. The slots are not traced. */
class Object016d5e60 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */

  private:
    u8 unknown8[0x110];
    Object01347230 array118; /* +0x118 */
    Object0134f620 array130; /* +0x130 */
    u8 unknown148[0x28];
    OwnedBlock05943280 block170; /* +0x170 */
    u8 unknown178[0x388];
};

/* derived names: the class whose vtable is at 0x16d7d90 (four slots; the
 * row of config/vtables.derived.base.txt names it), the member at +0x240 of
 * the class whose destructor is FUN_012e1d00, which holds its destructor
 * inlined (0x012e1d00 + 0x181: the vtable stored, the block at +0x170
 * released, then `lea rdi, [r14+0x370]; call 0x134f620` and `lea rdi,
 * [r14+0x358]; call 0x1347230`: the arrays at +0x130 and +0x118). No
 * destructor of its own in the executable. 0x500 bytes to the member after
 * it. The slots are not traced. */
class Object016d7d90 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */

  private:
    u8 unknown8[0x110];
    Object01347230 array118; /* +0x118 */
    Object0134f620 array130; /* +0x130 */
    u8 unknown148[0x28];
    OwnedBlock05943280 block170; /* +0x170 */
    u8 unknown178[0x388];
};

#endif
