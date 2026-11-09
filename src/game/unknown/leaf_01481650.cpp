/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1481660, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16c2a68 (stored by
 * FUN_0124f080); 0x16d74e8 (stored by FUN_0124f080 0x1481660), slot 1
 * (0x1481a50) the deleting destructor calling 0x1481660 before operator
 * delete. One body for the 2 vtables. The class form: Object01481650 derives
 * from Object01481660, whose destructor is the one at 0x1481660 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01481660 /* derived name */
{
  public:
    virtual ~Object01481660();
};

class Object01481650 : public Object01481660 /* derived name */
{
  public:
    virtual ~Object01481650();
};

Object01481650::~Object01481650() {}
