/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00cf7fb0.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xcf7fb0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16d1ee8 (stored by
 * FUN_00cf8300); 0x16d1f28 (stored by FUN_00cf8af0); 0x16d1fe8 (stored by
 * FUN_00cfa710); 0x16d20a0 (stored by FUN_00cfe310), slot 1 (0xcf8100) the
 * deleting destructor calling 0xcf7fb0 before operator delete. One body for
 * the 4 vtables. The class form: Object013b34e0 derives from Object00cf7fb0,
 * whose destructor is the one at 0xcf7fb0 (its row named for it, D15), and
 * its own destructor is defined empty out of line. */
class Object013b34e0 : public Object00cf7fb0 /* derived name */
{
  public:
    virtual ~Object013b34e0();
};

Object013b34e0::~Object013b34e0() {}
