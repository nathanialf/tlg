/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1368710, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16cb718 (stored by
 * FUN_007204d0); 0x16cb7b0 (stored by FUN_007204d0 0x1368710), slot 1
 * (0x1369c80) the deleting destructor calling 0x1368710 before operator
 * delete. One body for the 2 vtables. The class form: Object01369c70 derives
 * from Object01368710, whose destructor is the one at 0x1368710 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01368710 /* derived name */
{
  public:
    virtual ~Object01368710();
};

class Object01369c70 : public Object01368710 /* derived name */
{
  public:
    virtual ~Object01369c70();
};

Object01369c70::~Object01369c70() {}
