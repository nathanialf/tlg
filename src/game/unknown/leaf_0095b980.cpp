/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the non-virtual thunk of FUN_0095b960 (slot 10 of the vtable
 * at 0x16c7b78, its pointer at 0x16c7bd8) for the base at +0x128: slot 0 of
 * the secondary vtable whose pointer is at 0x16c7c28 (offset to top -0x128),
 * the body inlined after the adjustment. The secondary vtables beside it hold
 * one slot each (offset to top -0x120: 0x95a1b0; -0x130). FUN_0095b960 calls
 * FUN_0095b640 on the object when the int at +0x1f0 is set, FUN_0095b160
 * otherwise, as tail calls; leaf_0095b960.cpp keeps its free-function form.
 * The bases' sizes between their vptrs are those offsets; their other slots
 * and fields are not traced. */
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
    void FUN_0095b960();

    u8 unknown130[0x1f0 - 0x130];
    int unknown1f0;
};

void FUN_0095b640(Object0095b960 *self); /* derived name */
void FUN_0095b160(Object0095b960 *self); /* derived name */

void Object0095b960::FUN_0095b960()
{
    if (unknown1f0) {
        FUN_0095b640(this);
    } else {
        FUN_0095b160(this);
    }
}
