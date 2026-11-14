/* src/include/tlg_game_object01439e30.h: the two 0x150-byte members whose
 * destructors are 0x1439e30 and 0x1491e40 (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT01439E30_H
#define TLG_GAME_OBJECT01439E30_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"

/* derived names: the 24-byte element of the array at +0x28 of those
 * classes: a block at +0x0, released for each element when the array is
 * destroyed (0x1439f70: `lea rax, [rax+rax*2]; mov rax, [rcx+rax*8]`). The
 * rest is not traced. */
struct Element01439e30 {      /* derived name */
    OwnedBlock05943280 block; /* +0x0 */
    u8 unknown8[0x10];
};

/* derived names: the 32-byte element of the array at +0x40: two 16-byte
 * values stored aligned by the constructor (0x1439a2c: `vmovaps [rdx+rcx],
 * xmm0; vmovaps [rdx+rcx+0x10], xmm1` over `shl rcx, 5`). */
struct Element01439a20 { /* derived name */
    float unknown0[4];
    float unknown10[4];
};

/* derived names: the class whose vtable is at 0x16d5e90 (three slots; the
 * row of config/vtables.derived.base.txt names it), the part of
 * Object016d5eb8 that FUN_01439e30 destroys after storing this vtable
 * (0x01439e30 + 0x99): four arrays, at +0x10 and +0x80 of ints (the
 * constructor FUN_014397e0 sizes them 0x14 bytes for five, aligned 4), at
 * +0x28 of 24-byte elements that own a block and at +0x40 of 32-byte ones.
 * No destructor of its own in the executable. The slots are not traced. */
class Object016d5e90 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<int> array10;             /* +0x10 */
    Array05943280<Element01439e30> array28; /* +0x28 */
    Array05943280<Element01439a20> array40; /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<int> array80; /* +0x80 */
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

    virtual void slot1(); /* derived name; not traced */
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
 * (0x01491e40 + 0x99): four arrays, at +0x10 and +0x80 of ints (the
 * constructor FUN_014917f0 sizes them 0x14 bytes for five, aligned 4), at
 * +0x28 of 24-byte elements that own a block and at +0x40 of 32-byte ones.
 * No destructor of its own in the executable. The slots are not traced. */
class Object016d7dc0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<int> array10;             /* +0x10 */
    Array05943280<Element01439e30> array28; /* +0x28 */
    Array05943280<Element01439a20> array40; /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<int> array80; /* +0x80 */
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

    virtual void slot1(); /* derived name; not traced */
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

#endif
