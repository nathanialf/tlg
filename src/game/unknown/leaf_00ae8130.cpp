/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b8188
 * (config/vtables.derived.base.txt), derived from Object016b9108: a
 * counted reference at +0x28 and an array of counted references at +0x30 whose elements its destructor's body
 * releases, the block kept for the array's own destructor (0x134f620).
 * FUN_00ae8330, slot 1, is the deleting destructor. The other fields are not
 * traced. */
class Object016b3de8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b3de8();

  private:
    u8 unknown24[0x4];
    Ref00503fb0<Object016b9108> held28; /* +0x28 */
    Object0134f620 unknown30;           /* +0x30 */
};

Object016b3de8::~Object016b3de8()
{
    unknown30.removeAll();
}
