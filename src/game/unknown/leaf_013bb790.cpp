/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0139d760.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x139d760, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16bab08 (stored by
 * FUN_00b7d020 FUN_00d70ae0 FUN_00d88310 0x139d760), slot 1 (0x13bb7a0) the
 * deleting destructor calling 0x139d760 before operator delete. The class
 * form: Object013bb790 derives from Object0139d760, whose destructor is the
 * one at 0x139d760 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object013bb790 : public Object0139d760 /* derived name */
{
  public:
    virtual ~Object013bb790();
};

Object013bb790::~Object013bb790() {}
