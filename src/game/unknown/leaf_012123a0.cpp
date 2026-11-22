/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d68e8.h"

/* derived names: the class whose vtable is at 0x16c2050
 * (config/vtables.derived.base.txt), derived from Object016d68e8: slot 2 is
 * its own (FUN_012123a0: the base's slot 2, then every listener of the model told
 * of the object through its slot 5, the count read again after each one,
 * then the int at +0x70 cleared), slots 3 and 4 FUN_01212400 and
 * FUN_01212450 (not traced), the rest the base's; the class of
 * 0x16c2008's (FUN_01211da0) is its twin through slot 2. Its destructor is the
 * implicit one (slots 0 and 1 hold the base's pair): slot 2 is the key
 * function, so this file emits the vtable. */
class Object016c2050 : public Object016d68e8 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */

  private:
    int unknown70; /* +0x70: cleared after the listeners are told */
};

/* the counter is unsigned and the array's index an int: the index is
 * sign-extended at each use (`movsxd`), not widened */
void Object016c2050::slot2()
{
    Object016d68e8::slot2();
    for (unsigned i = 0; i < model->listeners.size(); ++i)
        model->listeners.at(i).listener->slot5(this);
    unknown70 = 0;
}
