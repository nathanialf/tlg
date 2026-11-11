/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16b55a0 (config/vtables.derived.base.txt; stored by FUN_00908b80 FUN_00b32dd0 FUN_00b32f80 FUN_00b32fc0),
 * slot 0 of it: it stores the vtable, calls the class's FUN_00b337e0 on the
 * object, then runs the destructors of its members in reverse order, FUN_0134f620 on the one at +0x1f0,
 * each written as a free function on its record, then its base's destructor
 * FUN_00b34150 (which stores its own class's vtable first; its row named for it,
 * D15) as a tail call. FUN_00b32fc0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
struct Object0134f620 /* derived name */
{
    u8 unknown0[8];
    int unknown8; /* +0x8: tested first */
};

void FUN_0134f620(Object0134f620 *self); /* derived name */

class Object00b34150 /* derived name */
{
  public:
    virtual ~Object00b34150();
};

class Object00b32f80 : public Object00b34150 /* derived name */
{
  public:
    virtual ~Object00b32f80();
    void FUN_00b337e0(); /* derived name */

  private:
    u8 unknown8[0x1e8];
    Object0134f620 unknown1f0; /* +0x1f0 */
};

Object00b32f80::~Object00b32f80()
{
    FUN_00b337e0();
    FUN_0134f620(&unknown1f0);
}
