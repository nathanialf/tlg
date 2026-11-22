/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ad0.h"

/* derived names: the class whose vtable is at 0x16bf3f8
 * (config/vtables.derived.base.txt), derived from Object016d3ad0: slot 2 is
 * its own (FUN_00f65c20: the base's slot 2 alone, a tail call), slot 4
 * FUN_00f65c30 (not traced), the rest the base's. Its destructor is the
 * implicit one (slots 0 and 1 hold the base's pair): slot 2 is the key
 * function, so this file emits the vtable. */
class Object016bf3f8 : public Object016d3ad0 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */
};

void Object016bf3f8::slot2()
{
    Object016d3ad0::slot2();
}
