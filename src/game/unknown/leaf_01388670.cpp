/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1388680, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ce038 (stored by
 * FUN_00a036a0 0x1388680), slot 1 (0x1388750) the deleting destructor calling
 * 0x1388680 before operator delete. The class form: Object01388670 derives
 * from Object01388680, whose destructor is the one at 0x1388680 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01388680 /* derived name */
{
  public:
    virtual ~Object01388680();
};

class Object01388670 : public Object01388680 /* derived name */
{
  public:
    virtual ~Object01388670();
};

Object01388670::~Object01388670() {}
