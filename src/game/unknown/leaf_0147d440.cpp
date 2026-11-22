/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d6b08.h"

/* derived names: the class whose vtable is at 0x16ca9f8
 * (config/vtables.derived.base.txt), derived from Object016d6b08: slot 2 is
 * its own (FUN_0147d440: the base's slot 2 alone, a tail call), slot 7
 * FUN_0123ed80 (not traced); 0x16d6ca0 is derived from it, the rest the
 * base's. Its destructor is the implicit one (slots 0 and 1 hold the base's
 * pair): slot 2 is the key function, so this file emits the vtable. */
class Object016ca9f8 : public Object016d6b08 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */
};

void Object016ca9f8::slot2()
{
    Object016d6b08::slot2();
}
