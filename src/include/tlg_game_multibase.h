/* Game-region classes with several polymorphic bases, known so far through
 * their vtables and the this-adjusting thunks the compiler emits beside a
 * method's definition (all names derived). */
#ifndef TLG_GAME_MULTIBASE_H
#define TLG_GAME_MULTIBASE_H

#include "tlg_types.h"

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

    u8 unknown8[0x8];
};

/* At +0x10: three slots (the thunk 0x1374700, FUN_0137bfe0, FUN_0137bff0),
 * not traced. */
class Class16cc478Base10 /* derived name */
{
  public:
    virtual void FUN_01374700() = 0; /* derived name, after its thunk; not traced */

    u8 unknown8[0x10];
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

    int FUN_0137b9e0() const;
    int FUN_0137b9f0() const;
    int FUN_01376380() const;

    u8 unknown48[0x58];
    int unknowna0; /* returned by FUN_0137b9f0 */
    int unknowna4; /* returned by FUN_0137b9e0 */
    u8 unknowna8[0x254 - 0xa8];
    int unknown254; /* returned by FUN_01376380 */
};

/* The base shared by the classes whose vtables hold the thunks 0x13746b0,
 * 0x13746d0 and 0x13746e0 (32 vtables, the first at 0x16b0c50, stored by
 * FUN_0091b770; 0x16b0cf0 by FUN_00923ef0) and 0x13746f0 (19 vtables):
 * secondary vtables at offsets 0x28 and 0x30. Its methods FUN_0137ba50,
 * FUN_0137ba60 and FUN_0137ba70 are slots 5, 7 and 8 of those primary vtables
 * and override the three slots of the base at +0x30; slot 6, the one slot of
 * the base at +0x28, returns the int at +0x20 in 0x16b0cf0 (its body folded
 * into the library's FUN_00004340, its thunk 0x13746f0). */
class Class137ba70Base0 /* derived name */
{
  public:
    /* Slots 0 and 1 hold the derived classes' destructors (FUN_01397860 and
     * FUN_01397980 in 0x16b0cf0); slots 2 to 4 (FUN_00cb66f0 and two empty
     * bodies) are not traced. */
    virtual ~Class137ba70Base0();
    virtual void FUN_00cb66f0(); /* derived name; parameters not traced */
    virtual void slot3();        /* derived name; 0x1af750, not traced */
    virtual void slot4();        /* derived name; 0x1af750, not traced */

    u8 unknown8[0x18];
    int flags; /* derived name: bits set by FUN_0137ba70, 0x30 cleared by FUN_0137ba50 */
};

class Class137ba70Base28 /* derived name */
{
  public:
    virtual int FUN_00004340(int mask) const = 0; /* derived name; FUN_0137ba60 passes -1 */
};

class Class137ba70Base30 /* derived name */
{
  public:
    virtual int FUN_0137ba60() const = 0;    /* derived name */
    virtual void FUN_0137ba50() = 0;         /* derived name */
    virtual void FUN_0137ba70(int bits) = 0; /* derived name */
};

class Class137ba70 /* derived name */
    : public Class137ba70Base0,
      public Class137ba70Base28,
      public Class137ba70Base30
{
  public:
    virtual ~Class137ba70();

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

    u8 unknown8[8];
};

class Base01395de0_10 /* derived name */
{
  public:
    virtual void FUN_01395bd0(); /* derived name; parameters not traced */

    u8 unknown8[0x10];
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

    u8 unknown40[0x60 - 0x40];
    Target01395de0 *unknown60;
};

/* The class whose vtable is at 0x16c7b78 (stored by FUN_00958460 and
 * FUN_0137e6e0): secondary vtables whose pointers are at 0x16c7c28 (offset to
 * top -0x128; slot 0 the thunk 0x95b980 of FUN_0095b960) and beside it one
 * slot each (offsets to top -0x120: 0x95a1b0; -0x130). The bases' sizes
 * between their vptrs are those offsets; their other slots and fields are not
 * traced. */
class Base0095b960_0 /* derived name */
{
  public:
    virtual ~Base0095b960_0();

    u8 unknown8[0x118];
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

class Object0095b960 /* derived name */
    : public Base0095b960_0,
      public Base0095b960_120,
      public Base0095b960_128
{
  public:
    /* Slot 10 of the primary vtable (its pointer at 0x16c7bd8). */
    void FUN_0095b960();

    u8 unknown130[0x1f0 - 0x130];
    int unknown1f0;
};

#endif
