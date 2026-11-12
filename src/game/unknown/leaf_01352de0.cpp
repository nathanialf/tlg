/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16cae20
 * (config/vtables.derived.base.txt; made by FUN_004a8e50): three Names at
 * +0x1c, +0x44 and +0x50. Its complete destructor 0x1352de0 releases +0x50, then +0x44, then +0x1c,
 * and calls no base; the deleting one 0x1352e90 is the compiler's. The other
 * members are not traced. */
class Object016cae20 /* derived name */
{
  public:
    virtual ~Object016cae20();

  private:
    u8 unknown8[0x14];
    Name unknown1c; /* +0x1c */
    u8 unknown20[0x24];
    Name unknown44; /* +0x44 */
    u8 unknown48[0x8];
    Name unknown50; /* +0x50 */
};

Object016cae20::~Object016cae20() {}
