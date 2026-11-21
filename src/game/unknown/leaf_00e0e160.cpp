/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x016bd6d8
 * (config/vtables.derived.base.txt), derived from Object016b9108: a counted
 * reference at +0x30, which its destructor's body empties by
 * compare-and-swap before the member's own destructor and the base's run.
 * FUN_00e0e300, slot 1, is the deleting destructor. The other fields are not
 * traced. */
class Object016bd6d8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bd6d8();

  private:
    u8 unknown24[0xc];
    AtomicRef0045c470<Object016b9108> held30; /* +0x30 */
};

Object016bd6d8::~Object016bd6d8()
{
    held30.clear();
}
