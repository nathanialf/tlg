/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ef8.h"

/* derived names: the class whose vtable is at 0x16ca380
 * (config/vtables.derived.base.txt), derived from Object016d3ef8: slot 2 is
 * its own (FUN_013e1a80: the base's slot 2, then +0x70 cleared), slot 7
 * FUN_00fa67e0 (not traced), the rest the base's. The class of 0x16ca3d0 (slot
 * 7 FUN_00fa6a10) holds the same slot 2, and so do the classes of 0x16d4180
 * and 0x16d41d0 derived from the two: two bodies of one form the link folded,
 * claimed from the lower vtable. Its destructor is the implicit one (slots 0
 * and 1 hold the base's pair): slot 2 is the key function, so this file emits
 * the vtable. */
class Object016ca380 : public Object016d3ef8 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */

  private:
    int unknown70; /* +0x70 */
};

void Object016ca380::slot2()
{
    Object016d3ef8::slot2();
    unknown70 = 0;
}
