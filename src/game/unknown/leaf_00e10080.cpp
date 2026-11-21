/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd868
 * (config/vtables.derived.base.txt; stored by FUN_00e0fda0), derived from
 * Object016b9108: a Name at +0x2c and a counted reference at +0x50, which
 * its destructor's body empties by compare-and-swap before the members' own
 * destructors (the reference's, then the Name's) and the base's run.
 * FUN_00e10260, slot 1, is the deleting destructor. The other fields are
 * not traced. */
class Object016bd868 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bd868();

  private:
    u8 unknown24[0x8];
    Name unknown2c; /* +0x2c */
    u8 unknown30[0x20];
    AtomicRef0045c470<Object016b9108> held50; /* +0x50 */
};

Object016bd868::~Object016bd868()
{
    held50.clear();
}
