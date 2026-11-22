/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d5140.h"

/* derived names: the class whose vtable is at 0x16c0710
 * (config/vtables.derived.base.txt), derived from Object016d5140: slot 2 is
 * its own (FUN_00ff8a20: the base's slot 2, then +0x80 set to 1), slot 3
 * FUN_00ff8a40 and slot 4 FUN_00ffaab0 (not traced), the rest the base's. Its
 * destructor FUN_00ff8880 (slot 0; not written) is declared, the class's key
 * function: the vtable is emitted with it, in no file yet. */
class Object016c0710 : public Object016d5140 /* derived name */
{
  public:
    virtual ~Object016c0710();
    virtual void slot2(); /* derived name */

  private:
    u8 unknown70[0x10];
    int unknown80; /* +0x80 */
};

void Object016c0710::slot2()
{
    Object016d5140::slot2();
    unknown80 = 1;
}
