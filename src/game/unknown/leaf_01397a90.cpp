/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1397620, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16b5a40 (stored by
 * FUN_00b3ec10); 0x16b5c48 (stored by FUN_00b404d0 0x1397620), slot 1
 * (0x1397aa0) the deleting destructor calling 0x1397620 before operator
 * delete. One body for the 2 vtables. The class form: Object01397a90 derives
 * from Object01397620, whose destructor is the one at 0x1397620 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01397620 /* derived name */
{
  public:
    virtual ~Object01397620();
};

class Object01397a90 : public Object01397620 /* derived name */
{
  public:
    virtual ~Object01397a90();
};

Object01397a90::~Object01397a90() {}
