/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

class Object016b9330;

/* derived names: what an Object016b9330 is linked with at +0x48: it points
 * back at +0x20. Nothing else of it is traced. */
struct Link00cd37e0 { /* derived name */
    u8 unknown0[0x20];
    Object016b9330 *owner20; /* +0x20 */
};

/* derived names: the class whose vtable is at 0x16b9330
 * (config/vtables.derived.base.txt, stored by FUN_00cd36c0), derived from
 * Object016b9108, linked both ways with the object at +0x48. Its complete
 * destructor (0xcd37e0; the deleting one 0xcd3890) breaks the link from both
 * ends when the other end still points to an object, then the base's
 * destructor is inlined (the two names). The destructor is the class's key
 * function, so this file emits the vtable. */
class Object016b9330 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b9330();

  private:
    u8 unknown24[0x24];
    Link00cd37e0 *link48; /* +0x48 */
};

Object016b9330::~Object016b9330()
{
    Link00cd37e0 *link = link48;
    if (link && link->owner20) {
        link->owner20->link48 = 0;
        link->owner20 = 0;
    }
}
