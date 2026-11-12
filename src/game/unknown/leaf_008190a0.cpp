/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16ae838
 * (config/vtables.derived.base.txt; made by FUN_00818ea0), derived from the
 * class whose destructor is 0x818d10 (leaf_00846b00.cpp): two Names at +0x9c
 * and +0xa0. Its complete destructor 0x8190a0 releases +0xa0, then +0x9c,
 * then runs the base's as a tail call; the deleting one 0x819140 is the
 * compiler's. Slot 2 is FUN_00cb66f0. The other members are not traced. */
class Object00818d10 /* derived name */
{
  public:
    virtual ~Object00818d10();
};

class Object016ae838 : public Object00818d10 /* derived name */
{
  public:
    virtual ~Object016ae838();

  private:
    u8 unknown8[0x94];
    Name unknown9c; /* +0x9c */
    Name unknowna0; /* +0xa0 */
};

Object016ae838::~Object016ae838() {}
