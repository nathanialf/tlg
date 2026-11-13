/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c298a0.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc298a0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16cec58 (stored by
 * FUN_00b0d4c0), slot 1 (0xc29a40) the deleting destructor calling 0xc298a0
 * before operator delete. The class form: Object0138fd50 derives from
 * Object00c298a0, whose destructor is the one at 0xc298a0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object0138fd50 : public Object00c298a0 /* derived name */
{
  public:
    virtual ~Object0138fd50();
};

Object0138fd50::~Object0138fd50() {}
