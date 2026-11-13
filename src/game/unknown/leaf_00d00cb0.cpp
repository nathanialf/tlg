/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00cbdb30.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xcbdb30, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b9e38 (stored by
 * FUN_00d00a40), slot 1 (0xd00cc0) the deleting destructor calling 0xcbdb30
 * before operator delete. The class form: Object00d00cb0 derives from
 * Object00cbdb30, whose destructor is the one at 0xcbdb30 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00d00cb0 : public Object00cbdb30 /* derived name */
{
  public:
    virtual ~Object00d00cb0();
};

Object00d00cb0::~Object00d00cb0() {}
