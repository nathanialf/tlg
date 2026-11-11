/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d55b8 (config/vtables.derived.base.txt) and FUN_013f9390, the deleting
 * one. The class holds at +0x8 a collection whose clear zeroes its count (at
 * +0x10 of the object) and resets the object at +0x20 through FUN_00214e10;
 * the destructor clears it, and the collection's own destructor clears it
 * again before the object's destructor FUN_002150c0 runs (a tail call in the
 * complete destructor). That object's class stores the vtable at 0x16a77d0
 * (no row) in FUN_002150c0, whose row is named for it (D15); its reset is
 * leaf_00793ce0.cpp's FUN_00214e10. The fields not named are not traced. The
 * destructor is the class's key function, so this file emits the vtable. */
class Object00214e10 /* derived name */
{
  public:
    virtual ~Object00214e10();

  private:
    u8 unknown8[0x2b8];
};

void FUN_00214e10(Object00214e10 *self);

struct Collection013f9340 /* derived name */
{
    ~Collection013f9340()
    {
        clear();
    }

    void clear()
    {
        count8 = 0;
        FUN_00214e10(&unknown18);
    }

    u8 unknown0[8];
    int count8; /* +0x8 */
    u8 unknownC[0xc];
    Object00214e10 unknown18; /* +0x18 */
};

class Object013f9340 /* derived name */
{
  public:
    virtual ~Object013f9340();

  private:
    Collection013f9340 unknown8; /* +0x8 */
};

Object013f9340::~Object013f9340()
{
    unknown8.clear();
}
