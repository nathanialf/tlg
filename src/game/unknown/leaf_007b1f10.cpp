/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class of the vtable at 0x16adf38
 * (config/vtables.derived.base.txt; made by FUN_001bd010): owned blocks at
 * +0x10 and +0x28, each followed by the int at +0x18 and +0x30 that the
 * destructor clears first. Its complete destructor 0x7b1f10 stores 0 to
 * both ints, then releases the block at +0x28 and the one at +0x10, and
 * calls no base; the deleting one 0x7b1fd0 is the compiler's. The other
 * members are not traced. */
class Object016adf38 : public Counted00c14bc0 /* derived name */
{
  public:
    virtual ~Object016adf38();

  private:
    OwnedBlock05943280 unknown10; /* +0x10 */
    int unknown18;                /* +0x18 */
    u8 unknown1c[0xc];
    OwnedBlock05943280 unknown28; /* +0x28 */
    int unknown30;                /* +0x30 */
};

Object016adf38::~Object016adf38()
{
    unknown18 = 0;
    unknown30 = 0;
}
