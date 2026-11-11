/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16b98b0 (config/vtables.derived.base.txt; stored by FUN_00cd91f0): slot 0
 * the complete destructor, slot 1 the deleting one (operator delete of the
 * object), slot 2 FUN_00cef2e0, which returns 1 (leaf_00cef2e0.cpp writes it
 * as a free function). FUN_00cd91f0 creates one, keeps it at +0x370 of its
 * owner and returns what its slot 2 returns: the call is direct, the vtable
 * being this file's (the destructor is the key function). */
class Object00cd91f0 /* derived name */
{
  public:
    virtual ~Object00cd91f0();
    virtual int FUN_00cef2e0(); /* derived name */
};

Object00cd91f0::~Object00cd91f0() {}

struct Owner00cd91f0 /* derived name */
{
    u8 unknown0[0x370];
    Object00cd91f0 *unknown370; /* +0x370 */
};

int FUN_00cd91f0(Owner00cd91f0 *self) /* derived name */
{
    Object00cd91f0 *object = new Object00cd91f0;
    self->unknown370 = object;
    return object->FUN_00cef2e0();
}
