/* src/include/tlg_game_object0143e060.h: four classes of the shape of
 * Object016d5e90 (tlg_game_object01439e30.h), each the part of two
 * 0x150-byte classes whose destructors are of 0x1439e30's shape (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT0143E060_H
#define TLG_GAME_OBJECT0143E060_H

#include "tlg_game_object01439e30.h"

/* derived name: the element of Object016d5fb0's array at +0x28, its own type
 * as Element01491e40 is (one instantiation of the array's destructor for
 * the class) */
struct Element016d5fb0 : Element01439e30 { /* derived name */
};

/* derived names: the class whose vtable is at 0x16d5fb0 (the row of
 * config/vtables.derived.base.txt names it; stored by FUN_0114db30), the part of
 * Object016d6060 and Object016d6010 that their destructors destroy after storing this vtable,
 * laid out as Object016d5e90. The slots are not traced. */
class Object016d5fb0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<int> array10;             /* +0x10 */
    Array05943280<Element016d5fb0> array28; /* +0x28 */
    Array05943280<Element01439a20> array40; /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<int> array80; /* +0x80 */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d6060 (the row of
 * config/vtables.derived.base.txt names it), over Object016d5fb0, laid out as
 * Object016d5eb8; its destructor FUN_0143e060 is not virtual */
class Object016d6060 : public Object016d5fb0 /* derived name */
{
  public:
    ~Object016d6060();

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

/* derived names: the class whose vtable is at 0x16d6010 (the row of
 * config/vtables.derived.base.txt names it), over Object016d5fb0, laid out as
 * Object016d5eb8; its destructor FUN_0143e290 is not virtual */
class Object016d6010 : public Object016d5fb0 /* derived name */
{
  public:
    ~Object016d6010();

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

/* derived name: the element of Object016d6270's array at +0x28, its own type
 * as Element01491e40 is (one instantiation of the array's destructor for
 * the class) */
struct Element016d6270 : Element01439e30 { /* derived name */
};

/* derived names: the class whose vtable is at 0x16d6270 (the row of
 * config/vtables.derived.base.txt names it; stored by FUN_01175460), the part of
 * Object016d62e8 and Object016d6298 that their destructors destroy after storing this vtable,
 * laid out as Object016d5e90. The slots are not traced. */
class Object016d6270 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<int> array10;             /* +0x10 */
    Array05943280<Element016d6270> array28; /* +0x28 */
    Array05943280<Element01439a20> array40; /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<int> array80; /* +0x80 */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d62e8 (the row of
 * config/vtables.derived.base.txt names it), over Object016d6270, laid out as
 * Object016d5eb8; its destructor FUN_01449a40 is not virtual */
class Object016d62e8 : public Object016d6270 /* derived name */
{
  public:
    ~Object016d62e8();

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

/* derived names: the class whose vtable is at 0x16d6298 (the row of
 * config/vtables.derived.base.txt names it), over Object016d6270, laid out as
 * Object016d5eb8; its destructor FUN_01449c70 is not virtual */
class Object016d6298 : public Object016d6270 /* derived name */
{
  public:
    ~Object016d6298();

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

/* derived name: the element of Object016d6408's array at +0x28, its own type
 * as Element01491e40 is (one instantiation of the array's destructor for
 * the class) */
struct Element016d6408 : Element01439e30 { /* derived name */
};

/* derived names: the class whose vtable is at 0x16d6408 (the row of
 * config/vtables.derived.base.txt names it; stored by FUN_01197560), the part of
 * Object016d6468 and Object016d64d8 that their destructors destroy after storing this vtable,
 * laid out as Object016d5e90. The slots are not traced. */
class Object016d6408 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<int> array10;             /* +0x10 */
    Array05943280<Element016d6408> array28; /* +0x28 */
    Array05943280<Element01439a20> array40; /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<int> array80; /* +0x80 */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d6468 (the row of
 * config/vtables.derived.base.txt names it), over Object016d6408, laid out as
 * Object016d5eb8; its destructor FUN_014591d0 is not virtual */
class Object016d6468 : public Object016d6408 /* derived name */
{
  public:
    ~Object016d6468();

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

/* derived names: the class whose vtable is at 0x16d64d8 (the row of
 * config/vtables.derived.base.txt names it), over Object016d6408, laid out as
 * Object016d5eb8; its destructor FUN_01459400 is not virtual */
class Object016d64d8 : public Object016d6408 /* derived name */
{
  public:
    ~Object016d64d8();

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

/* derived name: the element of Object016d65f0's array at +0x28, its own type
 * as Element01491e40 is (one instantiation of the array's destructor for
 * the class) */
struct Element016d65f0 : Element01439e30 { /* derived name */
};

/* derived names: the class whose vtable is at 0x16d65f0 (the row of
 * config/vtables.derived.base.txt names it; stored by FUN_011bd1d0), the part of
 * Object016d6668 and Object016d6618 that their destructors destroy after storing this vtable,
 * laid out as Object016d5e90. The slots are not traced. */
class Object016d65f0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<int> array10;             /* +0x10 */
    Array05943280<Element016d65f0> array28; /* +0x28 */
    Array05943280<Element01439a20> array40; /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<int> array80; /* +0x80 */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d6668 (the row of
 * config/vtables.derived.base.txt names it), over Object016d65f0, laid out as
 * Object016d5eb8; its destructor FUN_01467f40 is not virtual */
class Object016d6668 : public Object016d65f0 /* derived name */
{
  public:
    ~Object016d6668();

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

/* derived names: the class whose vtable is at 0x16d6618 (the row of
 * config/vtables.derived.base.txt names it), over Object016d65f0, laid out as
 * Object016d5eb8; its destructor FUN_01468170 is not virtual */
class Object016d6618 : public Object016d65f0 /* derived name */
{
  public:
    ~Object016d6618();

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
