/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c1b7f0.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc1b7f0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16bd7b0 (stored by
 * FUN_00e0eca0), slot 1 (0xe0f490) the deleting destructor calling 0xc1b7f0
 * before operator delete. The class form: Object00e0f480 derives from
 * Object00c1b7f0, whose destructor is the one at 0xc1b7f0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00e0f480 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object00e0f480();
};

Object00e0f480::~Object00e0f480() {}
