/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16d6a90
 * (config/vtables.derived.base.txt; made by FUN_0121a680): an owned block at
 * +0x18 and a Name at +0x30. Its complete destructor 0x147a4d0 releases the
 * Name, then the block; the deleting one 0x147a570 is the compiler's. Slot 2
 * is FUN_01478b40. The other members are not traced. */
class Object016d6a90 /* derived name */
{
  public:
    virtual ~Object016d6a90();

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Name unknown30; /* +0x30 */
};

Object016d6a90::~Object016d6a90() {}
