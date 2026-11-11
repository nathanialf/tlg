/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16d5120 (config/vtables.derived.base.txt), slot 0, its deleting one
 * FUN_013eb8a0 at slot 1, the vtable also stored by FUN_00fec060 and
 * FUN_00ff1940: it stores the vtable and tail-calls FUN_013e9a00, the
 * destructor of its member at +0x8 (which first tests the int at +0x8 of that
 * member), written as a free function on that record, as the derived complete
 * destructors are. The destructor is the class's key function, so this file
 * emits the vtable. */
struct Object013e9a00 /* derived name */
{
    u8 unknown0[8];
    int unknown8; /* +0x8: tested first */
};

void FUN_013e9a00(Object013e9a00 *self); /* derived name */

class Object013e99e0 /* derived name */
{
  public:
    virtual ~Object013e99e0();

  private:
    Object013e9a00 unknown8; /* +0x8 */
};

Object013e99e0::~Object013e99e0()
{
    FUN_013e9a00(&unknown8);
}
