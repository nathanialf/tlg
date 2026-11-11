/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16ba570 (config/vtables.derived.base.txt; stored by FUN_00d48af0
 * FUN_00d48cd0 FUN_00d48d10), slot 0 of it: it stores the vtable, runs the
 * destructors of its members in reverse order, FUN_0134f620 on the one at
 * +0x268 and on the one at +0x250, each written as a free function on its
 * record, then its base's destructor FUN_00c55550 (its row named for it, D15)
 * as a tail call. FUN_00d48d10, slot 1, is the deleting one. The destructor
 * is the class's key function, so this file emits the vtable. */
struct Object0134f620 /* derived name */
{
    u8 unknown0[8];
    int unknown8; /* +0x8: tested first */
};

void FUN_0134f620(Object0134f620 *self); /* derived name */

class Object00c55550 /* derived name */
{
  public:
    virtual ~Object00c55550();
};

class Object00d48cd0 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object00d48cd0();

  private:
    u8 unknown8[0x248];
    Object0134f620 unknown250; /* +0x250 */
    u8 unknown25c[0xc];
    Object0134f620 unknown268; /* +0x268 */
};

Object00d48cd0::~Object00d48cd0()
{
    FUN_0134f620(&unknown268);
    FUN_0134f620(&unknown250);
}
