/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d5140.h"

/* derived names: the class whose vtable is at 0x16c06c8
 * (config/vtables.derived.base.txt), derived from Object016d5140: slot 2 is
 * its own (FUN_00ff6a90: the base's slot 2 alone, a tail call), slot 3
 * FUN_00ff6aa0 and slot 4 FUN_00ff6ab0 (not traced), the rest the base's. Its
 * destructor is the implicit one (slots 0 and 1 hold the base's pair): slot 2
 * is the key function, so this file emits the vtable. */
class Object016c06c8 : public Object016d5140 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */
};

void Object016c06c8::slot2()
{
    Object016d5140::slot2();
}
