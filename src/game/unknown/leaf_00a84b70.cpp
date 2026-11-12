/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c19c80.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc19c80, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b2788 (stored by
 * FUN_00a849f0), slot 1 (0xa84b80) the deleting destructor calling 0xc19c80
 * before operator delete. The class form: Object00a84b70 derives from
 * Object00c19c80, whose destructor is the one at 0xc19c80 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00a84b70 : public Object00c19c80 /* derived name */
{
  public:
    virtual ~Object00a84b70();
};

Object00a84b70::~Object00a84b70() {}
