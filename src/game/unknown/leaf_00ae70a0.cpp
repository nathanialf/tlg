/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x016b3cd8
 * (config/vtables.derived.base.txt), derived from Object016b9108: counted
 * references at +0x30 and +0x38, which its destructor's body empties by
 * compare-and-swap, the first first, before the members' own destructors
 * and the base's run. FUN_00ae7370, slot 1, is the deleting destructor. The
 * other fields are not traced. */
class Object016b3cd8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b3cd8();

  private:
    u8 unknown24[0xc];
    AtomicRef0045c470<Object016b9108> held30; /* +0x30 */
    AtomicRef0045c470<Object016b9108> held38; /* +0x38 */
};

Object016b3cd8::~Object016b3cd8()
{
    held30.clear();
    held38.clear();
}
