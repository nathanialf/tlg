/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00ccfd00.h"

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xccfd00, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16d1a08 (stored by no
 * constructor listed); 0x16d1a78 (stored by FUN_00ccfe60); 0x16d1bc8 (stored
 * by FUN_00cd5380); 0x16d31a0 (stored by FUN_00e903d0), slot 1 (0x13af050)
 * the deleting destructor calling 0xccfd00 before operator delete. One body
 * for the 4 vtables. The class form: Object013af040 derives from
 * Object00ccfd00, whose destructor is the one at 0xccfd00 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object013af040 : public Object00ccfd00 /* derived name */
{
  public:
    virtual ~Object013af040();
};

Object013af040::~Object013af040() {}
