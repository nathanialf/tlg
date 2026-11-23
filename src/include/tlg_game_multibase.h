/* Game-region classes with several polymorphic bases, known so far through
 * their vtables and the this-adjusting thunks the compiler emits beside a
 * method's definition (all names derived). */
#ifndef TLG_GAME_MULTIBASE_H
#define TLG_GAME_MULTIBASE_H

#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object0137bcf0.h"

/* The class whose vtable is at 0x16cc478 (stored by FUN_009232e0,
 * FUN_013755d0 and FUN_01375710): secondary vtables at offsets 0x10, 0x28,
 * 0x30, 0x38 and 0x40 (their offsets to top). The base at +0x30 has five
 * slots, all overridden: FUN_01376650 (thunk 0x1374770), the getters
 * FUN_0137b9e0 and FUN_0137b9f0 (thunks 0x1374780, 0x1374790), FUN_01376350
 * and FUN_01376380 (thunks 0x13747a0, 0x13747d0). Each overrider also has a
 * slot of its own in the primary vtable (11 and 12 for the getters). */
class Class16cc478Base0 /* derived name */
{
  public:
    /* Slots 0 and 1: FUN_013755d0 and FUN_01375710 store the vtable. */
    virtual ~Class16cc478Base0();
    /* Slots 2 to 5 of 0x16cc478: 0x69a0, FUN_01375860, FUN_00b3d280,
     * FUN_00b3d320. */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */

    u8 unknown8[0x8];
};

/* At +0x10: three slots (the thunk 0x1374700, FUN_0137bfe0, FUN_0137bff0);
 * the first overridden by FUN_0137ba00, which reads the object at +0x8 of this
 * base (+0x18 of the class). */
class Class16cc478Member18 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual int slot7();  /* derived name */
};

class Class16cc478Base10 /* derived name */
{
  public:
    virtual int FUN_01374700() = 0; /* derived name, after its thunk */

    Class16cc478Member18 *member8; /* +0x8 */
    u8 unknown10[0x8];
};

/* At +0x28: one slot; its thunk 0x1374750 calls FUN_01376390 on the object
 * and returns 1. */
class Class16cc478Base28 /* derived name */
{
  public:
    virtual int FUN_01374750() = 0; /* derived name, after its thunk; parameters not traced */
};

/* At +0x30: five slots, all overridden (the thunks 0x1374770 to 0x13747d0). */
class Class16cc478Base30 /* derived name */
{
  public:
    virtual void FUN_01376650() = 0;      /* derived name; parameters not traced */
    virtual int FUN_0137b9e0() const = 0; /* derived name */
    virtual int FUN_0137b9f0() const = 0; /* derived name */
    virtual int FUN_01376350() const = 0; /* derived name; parameters not traced */
    virtual int FUN_01376380() const = 0; /* derived name */
};

/* At +0x38: two slots, the thunk 0x13747e0 and FUN_00b3d2d0. */
class Class16cc478Base38 /* derived name */
{
  public:
    virtual void FUN_00b3d2d0() = 0; /* derived name; parameters not traced */
};

/* At +0x40: one slot, FUN_00b3d480; its size is not traced. */
class Class16cc478Base40 /* derived name */
{
  public:
    virtual void FUN_00b3d480() = 0; /* derived name; parameters not traced */
};

class Class16cc478 /* derived name */
    : public Class16cc478Base0,
      public Class16cc478Base10,
      public Class16cc478Base28,
      public Class16cc478Base30,
      public Class16cc478Base38,
      public Class16cc478Base40
{
  public:
    virtual ~Class16cc478();
    /* Slot 6, FUN_01376230, the first of the class's own slots. */
    virtual void FUN_01376230(); /* derived name; parameters not traced */

    int FUN_0137b9e0() const;
    int FUN_0137b9f0() const;
    int FUN_01376350() const;
    int FUN_01376380() const;
    int FUN_01374700(); /* slot 13, FUN_0137ba00 */

    u8 unknown48[0x58];
    int unknowna0; /* returned by FUN_0137b9f0 */
    int unknowna4; /* returned by FUN_0137b9e0 */
    u8 unknowna8[4];
    int unknownac; /* read by FUN_01376350 */
    u8 unknownb0[0x254 - 0xb0];
    int unknown254; /* returned by FUN_01376380 */
    u8 unknown258[0x380 - 0x258];
    int unknown380; /* tested by FUN_01376350 */
};

/* The base shared by the classes whose vtables hold the thunks 0x13746b0,
 * 0x13746d0 and 0x13746e0 (32 vtables, the first at 0x16b0c50, stored by
 * FUN_0091b770; 0x16b0cf0 by FUN_00923ef0) and 0x13746f0 (19 vtables):
 * secondary vtables at offsets 0x28 and 0x30. Its methods FUN_0137ba50,
 * FUN_0137ba60 and FUN_0137ba70 are slots 5, 7 and 8 of those primary vtables
 * and override the three slots of the base at +0x30; slot 6, the one slot of
 * the base at +0x28, returns the int at +0x20 in 0x16b0cf0 (its body folded
 * into the library's FUN_00004340, its thunk 0x13746f0). The primary base
 * is Object016b9108 (tlg_game_object016b9108.h). No destructor is declared:
 * the implicit one is inlined whole into each class's complete destructor,
 * the base at +0x30's (Object016cc450) then the root class's, with no vptr
 * store of the classes' own (FUN_01397860, the one body of twenty vtables'
 * slot 0, 0x16b10c8 among them). */
class Class137ba70Base28 /* derived name */
{
  public:
    virtual int FUN_00004340(int mask) const = 0; /* derived name; FUN_0137ba60 passes -1 */
};

/* derived name: the base at +0x30, whose vtable is at 0x16cc450
 * (config/vtables.derived.base.txt): its three slots are pure (no destructor
 * among them) and a counted reference at +0x8 is its member; its destructor
 * stores its vptr and releases the reference (FUN_01397860: `lea rax,
 * [0x16cc460]; mov [r15+0x30], rax; mov r14, [r15+0x38]`, before the root
 * class's names), so it is not trivial and is inlined into the classes'. */
class Object016cc450 /* derived name */
{
  public:
    virtual int FUN_0137ba60() const = 0;    /* derived name */
    virtual void FUN_0137ba50() = 0;         /* derived name */
    virtual void FUN_0137ba70(int bits) = 0; /* derived name */

  private:
    Ref00503fb0<Object016b9108> unknown8; /* +0x8 */
};

class Class137ba70 /* derived name */
    : public Object016b9108,
      public Class137ba70Base28,
      public Object016cc450
{
  public:
    /* inlined in the creators (0x953b3d, 0x96aa1d): the root's constructor
     * a call, then the vptrs at +0x0, +0x28 and +0x30 and the reference at
     * +0x38 cleared; the vptr stores of this class itself are dead under
     * those of the class built on it */
    Class137ba70(const Name &name) : Object016b9108(name) {}

    /* In their primary-vtable order, slots 5 to 8. */
    void FUN_0137ba50();
    int FUN_00004340(int mask) const;
    int FUN_0137ba60() const;
    void FUN_0137ba70(int bits);
};

/* The class whose vtable is at 0x16b57c0 (stored by FUN_00b38190 and
 * FUN_01395730): slots 2, 7 and 8 and the thunks' offsets as Class137ba70's,
 * slots 5 and 6 its own (FUN_00b386b0, the same body as FUN_0137ba50, its
 * thunk FUN_00b386c0 in the base at +0x30; FUN_00b38650), slot 9 FUN_00b383d0
 * not traced. Derived from Class137ba70 as a model of the shared slots. */
class Class16b57c0 : public Class137ba70 /* derived name */
{
  public:
    void FUN_0137ba50();
    int FUN_00004340(int mask) const;

    Class137ba70
        *linked; /* +0x40, derived name: its slot 6 asked with the bit cleared (FUN_00b38650) */
};

/* The class whose vtable is at 0x16ccce8 (config/vtables.derived.base.txt;
 * stored by FUN_00953850 and FUN_00953a30 after the root's constructor):
 * the slots of Class137ba70, none of its own; its members follow its vptr
 * stores in both creators: two pointers at +0x40 cleared in one 16-byte
 * store, then seven ints, 2 the fourth (`mov dword [rbx+0x5c], 2`); 0x78
 * bytes with what is built on it (FUN_00953850: `mov edi, 0x78`). */
class Object016ccce8 : public Class137ba70 /* derived name */
{
  public:
    Object016ccce8(const Name &name)
        : Class137ba70(name), linked(0), unknown48(0), unknown50(0), unknown54(0), unknown58(0),
          unknown5c(2), unknown60(0), unknown64(0), unknown68(0)
    {
    }

    Class137ba70
        *linked; /* +0x40, derived name: slot 6 of the class below asks it with the bit cleared */
    void *unknown48; /* +0x48 */
    int unknown50;   /* +0x50 */
    int unknown54;   /* +0x54 */
    int unknown58;   /* +0x58 */
    int unknown5c;   /* +0x5c: 2 from the constructor */
    int unknown60;   /* +0x60 */
    int unknown64;   /* +0x64 */
    int unknown68;   /* +0x68 */
    u8 unknown6c[0xc];
};

/* The class whose vtable is at 0x16b10c8 (stored by FUN_00953850; the vtable
 * at 0x16b1168, stored by FUN_00953a30, holds the same slot 6): the slots of
 * Object016ccce8 but slot 6, its own (FUN_00961140, its thunk in the base at
 * +0x28), and slot 9, 0x42d0's `return 0` (not declared). No members of its
 * own. */
class Class16b10c8 : public Object016ccce8 /* derived name */
{
  public:
    Class16b10c8(const Name &name) : Object016ccce8(name) {}

    int FUN_00004340(int mask) const;
};

/* The class whose vtable is at 0x16b5720 (stored by FUN_00b37fd0): the slots
 * of Class137ba70 but slot 6, its own (FUN_00b38370, its thunk in the base at
 * +0x28). */
class Class16b5720 : public Class137ba70 /* derived name */
{
  public:
    int FUN_00004340(int mask) const;

    Class137ba70 *linked; /* +0x40, derived name: its slot 6 asked with the bit cleared */
};

/* The class whose vtable is at 0x16b5900 (stored by FUN_00b3da40): the slots
 * of Class137ba70 but slot 6, its own (FUN_00b3ddf0, its thunk in the base at
 * +0x28). */
class Class16b5900 : public Class137ba70 /* derived name */
{
  public:
    int FUN_00004340(int mask) const;

    Class137ba70 *linked; /* +0x40, derived name: its slot 6 asked with the bit cleared */
};

/* The class whose vtable is at 0x16cd110 (config/vtables.derived.base.txt;
 * stored by FUN_0096a720 and FUN_0096a910 after the root's constructor),
 * the same slots as 0x16ccce8: its members follow its vptr stores, three
 * pointers at +0x40 cleared (a 16-byte store and a quad), then seven ints,
 * 2 the fourth (`mov dword [rbx+0x64], 2`); 0x78 bytes with the class
 * below (FUN_0096a720: `mov edi, 0x78`). */
class Object016cd110 : public Class137ba70 /* derived name */
{
  public:
    Object016cd110(const Name &name)
        : Class137ba70(name), child40(0), child48(0), child50(0), unknown58(0), unknown5c(0),
          unknown60(0), unknown64(2), unknown68(0), unknown6c(0), unknown70(0)
    {
    }

    Class137ba70 *child40; /* +0x40, derived name: asked with the whole mask */
    Class137ba70 *child48; /* +0x48, derived name: asked when bit 1 is set */
    Class137ba70 *child50; /* +0x50, derived name: asked when bit 2 is set */
    int unknown58;         /* +0x58 */
    int unknown5c;         /* +0x5c */
    int unknown60;         /* +0x60 */
    int unknown64;         /* +0x64: 2 from the constructor */
    int unknown68;         /* +0x68 */
    int unknown6c;         /* +0x6c */
    int unknown70;         /* +0x70 */
    u8 unknown74[0x4];
};

/* The classes whose vtables are at 0x16b15a0 (stored by FUN_0096a720 and
 * FUN_0096a910; the class at 0x16b1640, built by FUN_0096a910, keeps this
 * slot 6) and 0x16b5860 (stored by FUN_00b386f0; the class at 0x16b0c50,
 * built by FUN_0091b770, keeps it): the slots of Class137ba70 but slot 6,
 * their own (FUN_0096e630 and FUN_00b3d5e0, one shape: bits 1 and 2 of the
 * mask in the first, bits 0 and 2 in the second; their thunks in the base
 * at +0x28 FUN_0096e6a0 and FUN_00b3d650), and slot 9, 0x42d0's
 * `return 0`. */
class Class16b15a0 : public Object016cd110 /* derived name */
{
  public:
    Class16b15a0(const Name &name) : Object016cd110(name) {}

    int FUN_00004340(int mask) const;
};

/* What the class at 0x16b5860 adds to Class137ba70: a base with no virtual
 * function, so the class's destructor (0x137bac0, slot 0, shared with the
 * class at 0x16b0c50) stores no vptr of its own: the record at +0x60
 * destroyed (0x137bcf0), then the base at +0x30's vptr and reference and the
 * root class's. */
struct Links16b5860 /* derived name */
{
    Class137ba70 *child40; /* +0x40, derived name: asked with the whole mask */
    Class137ba70 *child48; /* +0x48, derived name: asked when bit 0 is set */
    Class137ba70 *child50; /* +0x50, derived name: asked when bit 2 is set */
    u8 unknown58[0x8];
    Object0137bcf0 unknown60; /* +0x60 */
};

class Class16b5860 : public Class137ba70, public Links16b5860 /* derived name */
{
  public:
    int FUN_00004340(int mask) const;
};

/* The class whose vtable is at 0x16cf260 (stored by FUN_00b3de50,
 * FUN_01396a10 and FUN_01396b60): secondary vtables at 0x16cf2f0 (offset to
 * top -0x10), 0x16cf318 (-0x28; slot 0 the thunk 0x1395c20 of FUN_01395de0,
 * slot 1 FUN_00953820) and 0x16cf338 (-0x38). The bases' sizes between their
 * vptrs are those offsets; their other slots and fields are not traced. */
struct Target01395de0; /* derived name */

class Base01395de0_0 /* derived name */
{
  public:
    virtual ~Base01395de0_0();
    /* Slots 2 to 4 of 0x16cf260: 0x69a0, 0x58a0, FUN_01395db0. */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */

    u8 unknown8[8];
};

/* The object at +0x8 of the base at +0x10 (+0x18 of the class): FUN_01396750
 * asks its slot 7. */
class Member01395de0_18 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual int slot7();  /* derived name */
};

class Base01395de0_10 /* derived name */
{
  public:
    /* Overridden by FUN_01396750 (its thunk 0x1395bd0). */
    virtual int FUN_01395bd0() = 0; /* derived name, after its thunk */

    Member01395de0_18 *member8; /* +0x8 */
    u8 unknown10[8];
};

class Base01395de0_28 /* derived name */
{
  public:
    virtual void FUN_01395de0(Target01395de0 *value) = 0; /* derived name */
    virtual void FUN_00953820();                          /* derived name; parameters not traced */

    u8 unknown8[8];
};

class Base01395de0_38 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
};

class Object01395de0 /* derived name */
    : public Base01395de0_0,
      public Base01395de0_10,
      public Base01395de0_28,
      public Base01395de0_38
{
  public:
    virtual ~Object01395de0();

    /* Slot 5 of the primary vtable (its pointer at 0x16cf298). */
    void FUN_01395de0(Target01395de0 *value);
    /* Slots 6 and 7, FUN_00953730 and FUN_01395df0. */
    virtual void FUN_00953730(); /* derived name; parameters not traced */
    virtual void FUN_01395df0(); /* derived name; parameters not traced */
    /* Slot 13 (its pointer at 0x16cf2d8), FUN_01396750. */
    int FUN_01395bd0();

    u8 unknown40[0x60 - 0x40];
    Target01395de0 *unknown60;
};

/* The class whose vtable is at 0x16c7b78 (stored by FUN_00958460 and
 * FUN_0137e6e0): secondary vtables whose pointers are at 0x16c7c28 (offset to
 * top -0x128; slot 0 the thunk 0x95b980 of FUN_0095b960) and beside it one
 * slot each (offsets to top -0x120: 0x95a1b0), two slots (-0x130, both
 * pure) and three (-0x140: slot 0 pure, FUN_0137bfe0, FUN_0137e0f0). The
 * bases' sizes between their vptrs are those offsets; their other slots and
 * fields are not traced. Slots 2 to 4 of the primary vtable are
 * Object016b9108's (FUN_00cb66f0 and the two empty ones), 13 and 14 pure. */
class Base0095b960_0 : public Object016b9108 /* derived name */
{
  public:
    /* Slots 5 and 6: 0x58a0, FUN_01343880. */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */

    u8 unknown24[0x120 - 0x24];
};

class Base0095b960_120 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; 0x95a1b0, not traced */
};

class Base0095b960_128 /* derived name */
{
  public:
    virtual void FUN_0095b960() = 0; /* derived name */
};

class Base0095b960_130 /* derived name */
{
  public:
    virtual void slot0() = 0; /* derived name; not traced */
    virtual void slot1() = 0; /* derived name; not traced */

    u8 unknown8[8];
};

/* The object at +0x8 of the base at +0x140 (+0x148 of the class): slot 11
 * (FUN_0137e150) calls its slot 5, the overrider in 0x16b0fb0 its slot 7. */
class Member0095b960_148 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual int slot7();  /* derived name */
};

class Base0095b960_140 /* derived name */
{
  public:
    /* Overridden by FUN_0137e1e0 in the class at 0x16b0fb0 (its thunk
     * 0x137e100). */
    virtual int FUN_0137e100() = 0; /* derived name, after its thunk */
    virtual void slot1();           /* derived name; FUN_0137bfe0, not traced */
    virtual void slot2();           /* derived name; FUN_0137e0f0, not traced */

    Member0095b960_148 *member8; /* +0x8 */
};

class Object0095b960 /* derived name */
    : public Base0095b960_0,
      public Base0095b960_120,
      public Base0095b960_128,
      public Base0095b960_130,
      public Base0095b960_140
{
  public:
    /* Slots 7 to 9: FUN_00958920, FUN_00958c20, FUN_00959ad0. */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
    /* Slot 10 of the primary vtable (its pointer at 0x16c7bd8). */
    void FUN_0095b960();
    /* Slots 11 and 12: FUN_0137e150, FUN_0137e170; 13 and 14 pure (in the
     * class at 0x16b0fb0 FUN_0137e180 and FUN_0137e190). */
    virtual void slot11();     /* derived name; not traced */
    virtual void slot12();     /* derived name; not traced */
    virtual void slot13() = 0; /* derived name; not traced */
    virtual void slot14() = 0; /* derived name; not traced */

    u8 unknown150[0x1f0 - 0x150];
    int unknown1f0;
};

/* The class whose vtable is at 0x16b0fb0 (stored by FUN_00958460 after the
 * vtable of its base at 0x16c7b78): slots 15 and 16 its own (FUN_0095c380,
 * FUN_0095d150), slot 17 FUN_0137e1e0, the overrider of the base at
 * +0x140's slot 0. */
class Object016b0fb0 : public Object0095b960 /* derived name */
{
  public:
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    int FUN_0137e100();    /* slot 17 */
};

/* The classes whose vtables are at 0x16b13b8 (stored by FUN_00961a00),
 * 0x16b1468 (FUN_00969cd0) and 0x16b59a0 (FUN_00b3dc00)
 * (config/vtables.derived.base.txt), each over Class137ba70 with an array of
 * counted references of its own (+0x48 in the first, +0x58 in the others),
 * its secondary vtables at offsets 0x28 and 0x30 (their offsets to top):
 * slot 5 their own (FUN_009666d0, FUN_0096a290, FUN_00b3e270, the overriders
 * of FUN_0137ba50, their thunks in the base at +0x30 0x9667c0, 0x96a380 and
 * 0xb3e360), slot 6 Class137ba70's (0x4340) in the first and its own in the
 * others (FUN_0096a170, FUN_00b3e130, their thunks in the base at +0x28
 * 0x96a280 and 0xb3e260), slot 8 Class137ba70's but in 0x16b1468
 * (FUN_0096a390, its thunk 0x96a480). The destructor is each class's key
 * function: its complete destructor stores the three vptrs, tears the array
 * down (`lea rdi, [r15+0x48]; call 0x134f620`), then the bases' (FUN_0137eb00,
 * FUN_0137faa0, FUN_013967a0; the deleting ones beside them in slot 1). */
class Object016b13b8 : public Class137ba70 /* derived name */
{
  public:
    virtual ~Object016b13b8();
    void FUN_0137ba50(); /* FUN_009666d0 */
    /* Slots 9 to 11: FUN_00967110, FUN_009667d0, FUN_009668e0. */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */

  private:
    u8 unknown40[8];
    Object0134f620 unknown48; /* +0x48 */
};

class Object016b1468 : public Class137ba70 /* derived name */
{
  public:
    virtual ~Object016b1468();
    void FUN_0137ba50();              /* FUN_0096a290 */
    int FUN_00004340(int mask) const; /* FUN_0096a170 */
    void FUN_0137ba70(int bits);      /* FUN_0096a390 */
    /* Slot 9: FUN_0096a0a0. */
    virtual void slot9(); /* derived name; not traced */

  private:
    u8 unknown40[0x18];
    Object0134f620 unknown58; /* +0x58 */
};

class Object016b59a0 : public Class137ba70 /* derived name */
{
  public:
    virtual ~Object016b59a0();
    void FUN_0137ba50();              /* FUN_00b3e270 */
    int FUN_00004340(int mask) const; /* FUN_00b3e130 */
    /* Slot 9: FUN_00b3de50. */
    virtual void slot9(); /* derived name; not traced */

  private:
    u8 unknown40[0x18];
    Object0134f620 unknown58; /* +0x58 */
};

/* The class whose vtable is at 0x16cd098 (config/vtables.derived.base.txt,
 * stored by FUN_0096a0a0, the creator of the class over it at 0x16b1508):
 * three bases, at +0x0 (slot 2 0x69a0, slots 3 and 4 pure), +0x10
 * (Object016cc450) and +0x20 (one pure slot), their offsets to top in the
 * vtable. Its destructor is its key function and holds only the base at
 * +0x10's (FUN_0137fe90: the vptr at +0x10, the reference at +0x18); the
 * deleting one is FUN_0137ff30. */
class Base016cd098_0 /* derived name */
{
  public:
    virtual ~Base016cd098_0() {}

    virtual void slot2(); /* derived name; 0x69a0, not traced */

    u8 unknown8[8];
};

class Base016cd098_20 /* derived name */
{
  public:
    virtual void slot0() = 0; /* derived name; not traced */
};

class Object016cd098 /* derived name */
    : public Base016cd098_0,
      public Object016cc450,
      public Base016cd098_20
{
  public:
    virtual ~Object016cd098();
    virtual void slot3() = 0; /* derived name; not traced */
    virtual void slot4() = 0; /* derived name; not traced */
};

#endif
