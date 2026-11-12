/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16c73f0
 * (config/vtables.derived.base.txt; made by FUN_001bd010): three Names at
 * +0x14, +0x1c and +0x24. Its complete destructor 0x134b170 releases +0x24,
 * then +0x1c, then +0x14, and calls no base; the deleting one 0x134b430 is
 * the compiler's. The other members are not traced. */
class Object016c73f0 /* derived name */
{
  public:
    virtual ~Object016c73f0();

  private:
    u8 unknown8[0xc];
    Name unknown14; /* +0x14 */
    u8 unknown18[0x4];
    Name unknown1c; /* +0x1c */
    u8 unknown20[0x4];
    Name unknown24; /* +0x24 */
};

Object016c73f0::~Object016c73f0() {}
