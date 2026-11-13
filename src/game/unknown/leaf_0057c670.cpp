/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01358d70.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1358d70, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ab6b0 (stored by
 * FUN_0057c270), slot 1 (0x57c680) the deleting destructor calling 0x1358d70
 * before operator delete. The class form: Object0057c670 derives from
 * Object01358d70, whose destructor is the one at 0x1358d70 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object0057c670 : public Object01358d70 /* derived name */
{
  public:
    virtual ~Object0057c670();
};

Object0057c670::~Object0057c670() {}
