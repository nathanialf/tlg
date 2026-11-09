/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include "tlg_types.h"

/* derived names: the thunk of FUN_01395de0 (slot 5 of the primary vtable at
 * 0x16cf260, stored by FUN_00b3de50 FUN_01396a10 FUN_01396b60) for the base at
 * +0x28: slot 0 of the secondary vtable at 0x16cf318 (offset to top -0x28, its
 * pointer at 0x16cf328; slot 1 FUN_00953820), this - 0x28, the body inlined
 * into it (the store at +0x60 of the object made at +0x38 of the base, then
 * FUN_009531c0 as a tail call). The group's other secondary vtables are at
 * 0x16cf2f0 (offset to top -0x10) and 0x16cf338 (-0x38). The bases' sizes
 * between their vptrs are those offsets; their other slots and fields are not
 * traced. leaf_01395de0.cpp holds the primary entry as a function of the
 * object. Only the thunk is claimed here. */
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

    void FUN_01395de0(Target01395de0 *value);

    u8 unknown40[0x60 - 0x40];
    Target01395de0 *unknown60;
};

void FUN_009531c0(Object01395de0 *self); /* derived name */

void Object01395de0::FUN_01395de0(Target01395de0 *value)
{
    unknown60 = value;
    FUN_009531c0(this);
}
