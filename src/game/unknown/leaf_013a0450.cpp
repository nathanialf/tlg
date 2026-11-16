/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16d0300
 * (config/vtables.derived.base.txt, stored by FUN_00bfa840 FUN_00bfb1c0 FUN_00bfbb40 and 17 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013a0450 tears them down
 * (the block at +0x28); the rest are not traced. */
class Object016d0300 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d0300();

  private:
    u8 unknown24[0x4];
    /* +0x28: an owned block, released by the destructor (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block28;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_013a0520, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016d0300::~Object016d0300() {}

/* derived names: called by the destructors of the classes below with the
 * object, four of them 0x13a0090, two 0x139fb70; not traced */
void FUN_013a0090(Object016d0300 *self); /* derived name */
void FUN_0139fb70(Object016d0300 *self); /* derived name */

/* derived names: the class whose vtable is at 0x16d0338
 * (config/vtables.derived.base.txt), derived from Object016d0300. Its own
 * fields from +0x30 are traced only where its destructor FUN_0139ef10 tears
 * them down (the blocks at +0x50 and +0x68); the rest are not traced. */
class Object016d0338 : public Object016d0300 /* derived name */
{
  public:
    virtual ~Object016d0338();

  private:
    u8 unknown30[0x20];
    OwnedBlock05943280 block50; /* +0x50 */
    u8 unknown58[0x10];
    OwnedBlock05943280 block68; /* +0x68 */
};

/* derived name: the complete destructor: FUN_013a0090 on the object, then
 * the members released, last first, and the base's destructor inlined.
 * FUN_0139f070, slot 1, is the deleting one. */
// NONMATCHING: the deleting destructor (FUN_0139f070 for this class, and the
// five below) calls the complete one where the base inlines it (5/94): the
// destructor wants the inline hint, and nothing in the tree then emits the
// vtable (its creator FUN_00bfa840 is not written).
Object016d0338::~Object016d0338()
{
    FUN_013a0090(this);
}

/* derived names: the class whose vtable is at 0x16d03a8, laid out as
 * Object016d0338 above; its destructor FUN_0139f1d0 calls FUN_013a0090.
 * FUN_0139f330, slot 1, is the deleting one. */
class Object016d03a8 : public Object016d0300 /* derived name */
{
  public:
    virtual ~Object016d03a8();

  private:
    u8 unknown30[0x20];
    OwnedBlock05943280 block50; /* +0x50 */
    u8 unknown58[0x10];
    OwnedBlock05943280 block68; /* +0x68 */
};

Object016d03a8::~Object016d03a8()
{
    FUN_013a0090(this);
}

/* derived names: the class whose vtable is at 0x16d0418, laid out as
 * Object016d0338 above; its destructor FUN_0139f490 calls FUN_013a0090.
 * FUN_0139f5f0, slot 1, is the deleting one. */
class Object016d0418 : public Object016d0300 /* derived name */
{
  public:
    virtual ~Object016d0418();

  private:
    u8 unknown30[0x20];
    OwnedBlock05943280 block50; /* +0x50 */
    u8 unknown58[0x10];
    OwnedBlock05943280 block68; /* +0x68 */
};

Object016d0418::~Object016d0418()
{
    FUN_013a0090(this);
}

/* derived names: the class whose vtable is at 0x16d0488, laid out as
 * Object016d0338 above; its destructor FUN_0139f750 calls FUN_0139fb70.
 * FUN_0139f8b0, slot 1, is the deleting one. */
class Object016d0488 : public Object016d0300 /* derived name */
{
  public:
    virtual ~Object016d0488();

  private:
    u8 unknown30[0x20];
    OwnedBlock05943280 block50; /* +0x50 */
    u8 unknown58[0x10];
    OwnedBlock05943280 block68; /* +0x68 */
};

Object016d0488::~Object016d0488()
{
    FUN_0139fb70(this);
}

/* derived names: the class whose vtable is at 0x16d04f8, laid out as
 * Object016d0338 above; its destructor FUN_0139fa10 calls FUN_0139fb70.
 * FUN_0139fdd0, slot 1, is the deleting one. */
class Object016d04f8 : public Object016d0300 /* derived name */
{
  public:
    virtual ~Object016d04f8();

  private:
    u8 unknown30[0x20];
    OwnedBlock05943280 block50; /* +0x50 */
    u8 unknown58[0x10];
    OwnedBlock05943280 block68; /* +0x68 */
};

Object016d04f8::~Object016d04f8()
{
    FUN_0139fb70(this);
}

/* derived names: the class whose vtable is at 0x16d0568, laid out as
 * Object016d0338 above; its destructor FUN_0139ff30 calls FUN_013a0090.
 * FUN_013a02f0, slot 1, is the deleting one. */
class Object016d0568 : public Object016d0300 /* derived name */
{
  public:
    virtual ~Object016d0568();

  private:
    u8 unknown30[0x20];
    OwnedBlock05943280 block50; /* +0x50 */
    u8 unknown58[0x10];
    OwnedBlock05943280 block68; /* +0x68 */
};

Object016d0568::~Object016d0568()
{
    FUN_013a0090(this);
}
