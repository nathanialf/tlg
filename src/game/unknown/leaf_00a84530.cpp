/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c19c80.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b2740
 * (config/vtables.derived.base.txt, stored by its creator FUN_00a84380),
 * derived from Object00c19c80, with an array of counted references at +0x48.
 * Its destructor (its key function) empties the array, the block kept (the
 * references released first to last, then `mov dword [r15+0x50], 0`), then
 * the array is torn down (FUN_0134f620) and the base's destructor
 * tail-called (0xa84530; FUN_00a84630 the deleting one). The fields from
 * +0x30 are not traced. */
class Object016b2740 : public Object00c19c80 /* derived name */
{
  public:
    virtual ~Object016b2740();

  private:
    u8 unknown30[0x18];
    Object0134f620 unknown48; /* +0x48 */
};

Object016b2740::~Object016b2740()
{
    unknown48.removeAll();
}
