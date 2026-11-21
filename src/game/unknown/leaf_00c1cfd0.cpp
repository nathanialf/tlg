/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b8188
 * (config/vtables.derived.base.txt), derived from Object016b9108: an array
 * of counted references at +0x30 whose elements its destructor's body
 * releases, the block kept for the array's own destructor (0x134f620).
 * FUN_00c1d150, slot 1, is the deleting destructor. The other fields are not
 * traced. */
class Object016b8188 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b8188();

  private:
    u8 unknown24[0xc];
    Object0134f620 unknown30; /* +0x30 */
};

Object016b8188::~Object016b8188()
{
    unknown30.removeAll();
}
