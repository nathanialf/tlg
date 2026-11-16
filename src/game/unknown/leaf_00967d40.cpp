/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ccdf0.h"

/* derived names: an object an entry below points to at +0x40: slot 13 of
 * its vtable answers an int that slot 23 of the class below tests. */
class Target016b1208 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual int slot13();  /* derived name */
};

/* derived names: an element of the array the class below owns: 0x100 bytes,
 * polymorphic, destroyed in place through slot 0 of its vtable
 * (`mov rax, [rdi]; call [rax]`). Its other members are not traced. */
class Entry016b1208 /* derived name */
{
  public:
    virtual ~Entry016b1208();

    u8 unknown8[0x38];
    Target016b1208 *unknown40; /* +0x40 */
    u8 unknown48[0xb8];
};

/* derived names: the class whose vtable is at 0x16b1208
 * (config/vtables.derived.base.txt), derived from Object016ccdf0: its
 * destructor FUN_00967d40 stores that class's vptr and its member's after
 * its own body. Its own fields from +0x50 are traced only where the
 * destructor reads them. */
class Object016b1208 : public Object016ccdf0 /* derived name */
{
  public:
    virtual ~Object016b1208();
    void FUN_001af750();        /* derived name: slot 7, 0x968aa0; not traced */
    void slot8();               /* derived name: 0x968d50; not traced */
    virtual void slot9();       /* derived name; not traced */
    virtual void slot10();      /* derived name; not traced */
    virtual void slot11();      /* derived name; not traced */
    virtual void slot12();      /* derived name; not traced */
    virtual void slot13();      /* derived name; not traced */
    virtual void slot14();      /* derived name; not traced */
    virtual void slot15();      /* derived name; not traced */
    virtual void slot16();      /* derived name; not traced */
    virtual void slot17();      /* derived name; not traced */
    virtual void slot18();      /* derived name; not traced */
    virtual void slot19();      /* derived name; not traced */
    virtual void slot20();      /* derived name; not traced */
    virtual void slot21();      /* derived name; not traced */
    virtual void slot22();      /* derived name; not traced */
    virtual int FUN_00968870(); /* derived name: slot 23 */

  private:
    Entry016b1208 *entries50; /* +0x50: destroyed one by one, then cleared */
    u32 count58;              /* +0x58: the number of entries */
};

/* derived name: the complete destructor: destroys the entries in place where
 * the array is set and clears the pointer; then Object016ccdf0's destructor
 * is inlined. FUN_00967e80, slot 1, is the deleting one. This unit stores
 * Object016ccdf0's vtable, so it emits that class's vtable and its two
 * destructors (FUN_0137f420, FUN_0137f500). */
Object016b1208::~Object016b1208()
{
    if (entries50 != 0) {
        for (u32 i = 0; i < count58; ++i)
            entries50[i].~Entry016b1208();
        entries50 = 0;
    }
}

/* derived name: slot 23: whether the object at +0x40 of any entry answers
 * nonzero from its slot 13, the entries tested in order. */
int Object016b1208::FUN_00968870() /* derived name */
{
    for (u32 i = 0; i < count58; ++i) {
        Target016b1208 *target = entries50[i].unknown40;
        if (target != 0 && target->slot13() != 0)
            return 1;
    }
    return 0;
}
