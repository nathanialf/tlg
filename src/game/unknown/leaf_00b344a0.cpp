/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the destructor of a record that owns two blocks, each
 * holding two arrays (at +0x0 and +0x10 of the first, +0x0 and +0x8 of the
 * second), every array freed when set and each block deleted; the callers
 * delete the record the same way (`call 0xb344a0` then operator delete, at
 * 0x90da9b for the pointer at +0x3a8 of its owner and at 0xb3394d for +0x168).
 * The arrays' element types are not traced. */
struct Arrays00b344a0_0 { /* derived name */

    ~Arrays00b344a0_0()
    {
        if (first)
            delete[] first;
        if (second)
            delete[] second;
    }

    u8 *first; /* +0x0 */
    u8 unknown8[8];
    u8 *second; /* +0x10 */
};

struct Arrays00b344a0_8 { /* derived name */

    ~Arrays00b344a0_8()
    {
        if (first)
            delete[] first;
        if (second)
            delete[] second;
    }

    u8 *first;  /* +0x0 */
    u8 *second; /* +0x8 */
};

class Object00b344a0 /* derived name */
{
  public:
    ~Object00b344a0();

  private:
    Arrays00b344a0_0 *first;  /* +0x0 */
    Arrays00b344a0_8 *second; /* +0x8 */
};

Object00b344a0::~Object00b344a0()
{
    delete first;
    delete second;
}
