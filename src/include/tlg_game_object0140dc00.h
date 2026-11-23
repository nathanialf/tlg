/* src/include/tlg_game_object0140dc00.h: five track classes of the shape of
 * Object016d5eb8 (tlg_game_object01439e30.h), whose destructors 0x140dc00,
 * 0x14163d0, 0x1416600, 0x141d4f0 and 0x141d720 are FUN_01439e30's bytes
 * under their own vtables (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT0140DC00_H
#define TLG_GAME_OBJECT0140DC00_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_object016d7eb0.h"

/* derived names: the class whose vtable is at 0x16d5a48 (three slots; the row
 * of config/vtables.derived.base.txt names it), the part its derived
 * class destroys after storing this vtable: the fields of Object016d5e90
 * (tlg_game_object01439e30.h). No destructor of its own in the executable.
 * The slots are not traced. */
class Object016d5a48 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<u32> values10;                       /* +0x10: 4-byte values */
    Array05943280<List013e72e0<Pair014715d0>> lists28; /* +0x28: tlg_game_object016d7eb0.h */
    Array05943280<Pair014715d0> pairs40;               /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<u32> values80; /* +0x80: 4-byte values */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d5a70 (stored by FUN_010d9730), over
 * Object016d5a48: the fields of Object016d5eb8. Its destructor FUN_0140dc00 is
 * not virtual (no slot holds it); it releases the block of the array of
 * ints at +0xf0 and the block at +0xc8, then its part's. */
class Object016d5a70 : public Object016d5a48 /* derived name */
{
  public:
    ~Object016d5a70();

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

/* derived names: the class whose vtable is at 0x16d5bc8 (three slots; the row
 * of config/vtables.derived.base.txt names it), the part its derived
 * classes destroy after storing this vtable: the fields of Object016d5e90
 * (tlg_game_object01439e30.h). No destructor of its own in the executable.
 * The slots are not traced. */
class Object016d5bc8 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<u32> values10;                       /* +0x10: 4-byte values */
    Array05943280<List013e72e0<Pair014715d0>> lists28; /* +0x28: tlg_game_object016d7eb0.h */
    Array05943280<Pair014715d0> pairs40;               /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<u32> values80; /* +0x80: 4-byte values */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d5c40 (stored by FUN_010f2e40), over
 * Object016d5bc8: the fields of Object016d5eb8. Its destructor FUN_014163d0 is
 * not virtual (no slot holds it); it releases the block of the array of
 * ints at +0xf0 and the block at +0xc8, then its part's. */
class Object016d5c40 : public Object016d5bc8 /* derived name */
{
  public:
    ~Object016d5c40();

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

/* derived names: the class whose vtable is at 0x16d5bf0 (stored by FUN_010f2e40), over
 * Object016d5bc8: the fields of Object016d5eb8. Its destructor FUN_01416600 is
 * not virtual (no slot holds it); it releases the block of the array of
 * ints at +0xf0 and the block at +0xc8, then its part's. */
class Object016d5bf0 : public Object016d5bc8 /* derived name */
{
  public:
    ~Object016d5bf0();

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

/* derived names: the class whose vtable is at 0x16d5ce0 (three slots; the row
 * of config/vtables.derived.base.txt names it), the part its derived
 * classes destroy after storing this vtable: the fields of Object016d5e90
 * (tlg_game_object01439e30.h). No destructor of its own in the executable.
 * The slots are not traced. */
class Object016d5ce0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<u32> values10;                       /* +0x10: 4-byte values */
    Array05943280<List013e72e0<Pair014715d0>> lists28; /* +0x28: tlg_game_object016d7eb0.h */
    Array05943280<Pair014715d0> pairs40;               /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<u32> values80; /* +0x80: 4-byte values */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d5dc0 (stored by FUN_0110cc00), over
 * Object016d5ce0: the fields of Object016d5eb8. Its destructor FUN_0141d4f0 is
 * not virtual (no slot holds it); it releases the block of the array of
 * ints at +0xf0 and the block at +0xc8, then its part's. */
class Object016d5dc0 : public Object016d5ce0 /* derived name */
{
  public:
    ~Object016d5dc0();

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

/* derived names: the class whose vtable is at 0x16d5d70 (stored by FUN_0110cc00), over
 * Object016d5ce0: the fields of Object016d5eb8. Its destructor FUN_0141d720 is
 * not virtual (no slot holds it); it releases the block of the array of
 * ints at +0xf0 and the block at +0xc8, then its part's. */
class Object016d5d70 : public Object016d5ce0 /* derived name */
{
  public:
    ~Object016d5d70();

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
