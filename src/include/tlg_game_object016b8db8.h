/* src/include/tlg_game_object016b8db8.h: the class whose vtable is at
 * 0x16b8db8 and the class over it at 0x16b9048 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8DB8_H
#define TLG_GAME_OBJECT016B8DB8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the record the pointer at +0x38 of Object016b8db8 holds:
 * slot 5 stores it, slot 8 returns the address of its field at +0x68, slot
 * 15 clears it; the class at 0x16b9048 reads its int at +0x50 (slot 7) and
 * its pointers at +0x80 and +0x88 (slot 6). Its other fields are not traced. */
struct Target016b8db8 /* derived name */
{
    u8 unknown0[0x50];
    int unknown50; /* +0x50 */
    u8 unknown54[0x80 - 0x54];
    void *unknown80; /* +0x80 */
    void *unknown88; /* +0x88 */

    /* the pointer at +0x88 when it is set, else the one at +0x80 */
    void *const &current() const /* derived name */
    {
        return unknown88 ? unknown88 : unknown80;
    }
};

/* derived names: the class whose vtable is at 0x16b8db8
 * (config/vtables.derived.base.txt, stored by FUN_00ca3e70), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 15 its own
 * (declared; their bodies are not written here). Slots 6 and 7 are typed as
 * the class at 0x16b9048 overrides them (a pointer and an int, both const).
 * Its own fields from +0x24 (the root's tail) to +0x38 are not traced. */
class Object016b8db8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b8db8();
    virtual void slot5();        /* derived name; FUN_00ca41a0, not traced */
    virtual void *slot6() const; /* derived name; FUN_008f08d0 */
    virtual int slot7() const;   /* derived name; FUN_008f08f0 */
    virtual void slot8();        /* derived name; FUN_01373fc0, not traced */
    virtual void slot9();        /* derived name; FUN_013abfd0, not traced */
    virtual void slot10();       /* derived name; FUN_000042d0, not traced */
    virtual void slot11();       /* derived name; FUN_000042d0, not traced */
    virtual void slot12();       /* derived name; FUN_001af750, not traced */
    virtual void slot13();       /* derived name; FUN_00ca41b0, not traced */
    virtual void slot14();       /* derived name; FUN_001af750, not traced */
    virtual void slot15();       /* derived name; FUN_01373fd0, not traced */

  private:
    u8 unknown24[0x38 - 0x24];

  protected:
    Target016b8db8 *unknown38; /* +0x38: stored by slot 5, cleared by slot 15 */
};

/* derived names: a counted object the class at 0x16b9048 holds at +0x40,
 * active when its ints at +0x50 and +0x30 are both set (slots 6 and 7) */
class Active016b9048 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x30 - 0x24];
    int unknown30; /* +0x30 */
    u8 unknown34[0x50 - 0x34];
    int unknown50; /* +0x50 */
};

/* derived names: the class whose vtable is at 0x16b9048
 * (config/vtables.derived.base.txt, stored by FUN_00cb3170, its
 * constructor, not written), over Object016b8db8: slots 6, 7, 13 and 14
 * overridden. Slot 6 is its first virtual not defined in the class, so
 * leaf_00cb3ce0.cpp, which defines it, emits the vtable and with it the
 * inline destructor: its complete destructor 0x13ad5e0 a jump to the
 * base-object one 0x13ad610 (D45), its deleting destructor 0x13ad5f0. */
class Object016b9048 : public Object016b8db8 /* derived name */
{
  public:
    /* the base-object destructor FUN_013ad610: the body is empty; the
     * references at +0x48 and +0x40 are released in that order, then the
     * base's (Object016b8db8's empty body, Object016b9108's names) */
    virtual ~Object016b9048() {}

    /* slot 6, FUN_00cb3ce0: the pointer at +0x48 when the object at +0x40 is
     * active, else the current pointer of the record at +0x38 */
    virtual void *slot6() const;

    /* slot 7, FUN_00cb3d20: 0 when the object at +0x40 is active, else the
     * int at +0x50 of the record at +0x38 */
    virtual int slot7() const;

    virtual void slot13(); /* derived name; FUN_00cb3d40, not traced */
    virtual void slot14(); /* derived name; FUN_00cb4080, not traced */

  private:
    /* whether the object at +0x40 is there with its ints at +0x50 and +0x30
     * both set (slots 6 and 7: the +0x50 one read first) */
    bool active() const /* derived name */
    {
        const Active016b9048 *object = held40.get();
        return object && object->unknown50 && object->unknown30;
    }

    Ref00503fb0<Active016b9048> held40; /* +0x40: released by the destructor */
    Ref00503fb0<Object016b9108> held48; /* +0x48: released by the destructor; returned by slot 6 */
};

#endif
