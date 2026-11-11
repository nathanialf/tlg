/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16ccc98 (config/vtables.derived.base.txt), slot 0 of it: it stores the
 * vtable and, when the pointer at +0x10 is set, passes it to FUN_00951740,
 * which releases it, then clears the pointer and the 8 bytes after it (one
 * 16-byte store). FUN_0137cf60, slot 1, is the deleting one (the clears dead
 * before operator delete). The destructor is the class's key function, so
 * this file emits the vtable. The released object's type is not traced. */
struct Object00951740; /* derived name */

void FUN_00951740(Object00951740 *object); /* derived name */

class Object0137cf20 /* derived name */
{
  public:
    virtual ~Object0137cf20();

  private:
    u8 unknown8[8];
    Object00951740 *unknown10; /* +0x10 */
    u64 unknown18;             /* +0x18: cleared with it */
};

Object0137cf20::~Object0137cf20()
{
    if (unknown10) {
        FUN_00951740(unknown10);
        unknown10 = 0;
        unknown18 = 0;
    }
}
