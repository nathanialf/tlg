/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d5140.h"

/* derived names: the class whose vtable is at 0x16c0758
 * (config/vtables.derived.base.txt), derived from Object016d5140: slot 2 is
 * its own (FUN_00ffe1e0: the base's slot 2 alone, a tail call), slot 4
 * FUN_00ffe1f0 (not traced), the rest the base's. Its destructor FUN_00ffe050
 * (slot 0; not written) is declared, the class's key function: the vtable is
 * emitted with it, in no file yet. */
class Object016c0758 : public Object016d5140 /* derived name */
{
  public:
    virtual ~Object016c0758();
    virtual void slot2(); /* derived name */
};

void Object016c0758::slot2()
{
    Object016d5140::slot2();
}
