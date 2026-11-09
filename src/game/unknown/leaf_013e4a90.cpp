/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13e1ea0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16ca5b8 (stored by
 * FUN_00fba720 0x13e1ea0); 0x16d48f0 (stored by FUN_00fba720), slot 1
 * (0x13e4aa0) the deleting destructor calling 0x13e1ea0 before operator
 * delete. One body for the 2 vtables. The class form: Object013e4a90 derives
 * from Object013e1ea0, whose destructor is the one at 0x13e1ea0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013e1ea0 /* derived name */
{
  public:
    virtual ~Object013e1ea0();
};

class Object013e4a90 : public Object013e1ea0 /* derived name */
{
  public:
    virtual ~Object013e4a90();
};

Object013e4a90::~Object013e4a90() {}
