/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c55550.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc55550, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16ae2c8 (stored by
 * FUN_0080b010); 0x16ba5d0 (stored by FUN_00d48d60); 0x16d0708 (stored by
 * FUN_00c2a5d0); 0x16d2608 (stored by FUN_00d768b0), slot 1 (0x80b1f0) the
 * deleting destructor calling 0xc55550 before operator delete. One body for
 * the 4 vtables. The class form: Object0080b1e0 derives from Object00c55550,
 * whose destructor is the one at 0xc55550 (its row named for it, D15), and
 * its own destructor is defined empty out of line. */
class Object0080b1e0 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object0080b1e0();
};

Object0080b1e0::~Object0080b1e0() {}
