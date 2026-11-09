/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x147ec30, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16caa98 (stored by
 * FUN_0122be10 0x147ec30), slot 1 (0x147ec10) the deleting destructor calling
 * 0x147ec30 before operator delete. The class form: Object0147ec00 derives
 * from Object0147ec30, whose destructor is the one at 0x147ec30 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object0147ec30 /* derived name */
{
  public:
    virtual ~Object0147ec30();
};

class Object0147ec00 : public Object0147ec30 /* derived name */
{
  public:
    virtual ~Object0147ec00();
};

Object0147ec00::~Object0147ec00() {}
