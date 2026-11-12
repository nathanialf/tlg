/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16a7620
 * (config/vtables.derived.base.txt; made by FUN_001b0a40): three Names at
 * +0xc, +0x10 and +0x14. Its complete destructor 0x13cd140 releases +0x14, then +0x10, then +0xc,
 * and calls no base; the deleting one 0x13cd1f0 is the compiler's. The other
 * members are not traced. */
class Object016a7620 /* derived name */
{
  public:
    virtual ~Object016a7620();

  private:
    u8 unknown8[0x4];
    Name unknownc;  /* +0xc */
    Name unknown10; /* +0x10 */
    Name unknown14; /* +0x14 */
};

Object016a7620::~Object016a7620() {}
