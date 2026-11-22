/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d51e0.h"

/* derived names: the class whose vtable is at 0x16c0c50
 * (config/vtables.derived.base.txt), derived from Object016d51e0: slot 2 is
 * its own (FUN_013eeec0: the base's slot 2, then +0xb0 cleared, +0xd4 cleared,
 * +0xb4 cleared), slot 4 FUN_01011560 (not traced), the rest the base's. Its
 * destructor is the implicit one (slots 0 and 1 hold the base's pair): slot 2
 * is the key function, so this file emits the vtable. */
class Object016c0c50 : public Object016d51e0 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */

  private:
    u8 unknown70[0x40];
    float unknownb0; /* +0xb0: a float: the base keeps its zero apart from the int's at +0xb4 */
    int unknownb4;   /* +0xb4 */
    u8 unknownb8[0x1c];
    int unknownd4; /* +0xd4 */
};

void Object016c0c50::slot2()
{
    Object016d51e0::slot2();
    unknownb0 = 0.0f;
    unknownd4 = 0;
    unknownb4 = 0;
}
