/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x016b3f08
 * (config/vtables.derived.base.txt), derived from Object016b9108: a counted
 * reference at +0x28, which its destructor's body empties by
 * compare-and-swap before the member's own destructor and the base's run.
 * FUN_00ae9200, slot 1, is the deleting destructor. The other fields are not
 * traced. */
class Object016b3f08 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b3f08();

  private:
    u8 unknown24[0x4];
    AtomicRef0045c470<Object016b9108> held28; /* +0x28 */
};

Object016b3f08::~Object016b3f08()
{
    held28.clear();
}
