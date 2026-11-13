/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00d30550.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xd30550, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d1578 (stored by
 * FUN_00c68720), slot 1 (0x13a9fc0) the deleting destructor calling 0xd30550
 * before operator delete. The class form: Object013a9fb0 derives from
 * Object00d30550, whose destructor is the one at 0xd30550 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object013a9fb0 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object013a9fb0();
};

Object013a9fb0::~Object013a9fb0() {}
