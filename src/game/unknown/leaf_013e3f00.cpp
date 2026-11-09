/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13e4200, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ca608 (stored by
 * FUN_013e2990 0x13e4200), slot 1 (0x13e3f10) the deleting destructor calling
 * 0x13e4200 before operator delete. The class form: Object013e3f00 derives
 * from Object013e4200, whose destructor is the one at 0x13e4200 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013e4200 /* derived name */
{
  public:
    virtual ~Object013e4200();
};

class Object013e3f00 : public Object013e4200 /* derived name */
{
  public:
    virtual ~Object013e3f00();
};

Object013e3f00::~Object013e3f00() {}
