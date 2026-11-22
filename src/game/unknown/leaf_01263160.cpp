/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d7840.h"

/* derived names: the class whose vtable is at 0x16c2870
 * (config/vtables.derived.base.txt), derived from Object016d7840: slot 2 is
 * its own (FUN_01263160: the base's slot 2 alone, a tail call), slot 3
 * FUN_01263170 and slot 4 FUN_01263180 (not traced), the rest the base's. Its
 * destructor is the implicit one (slots 0 and 1 hold the base's pair): slot 2
 * is the key function, so this file emits the vtable. */
class Object016c2870 : public Object016d7840 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */
};

void Object016c2870::slot2()
{
    Object016d7840::slot2();
}
