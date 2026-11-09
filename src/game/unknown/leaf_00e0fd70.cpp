/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc1b7f0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16bd830 (stored by
 * FUN_00e0f650), slot 1 (0xe0fd80) the deleting destructor calling 0xc1b7f0
 * before operator delete. The class form: Object00e0fd70 derives from
 * Object00c1b7f0, whose destructor is the one at 0xc1b7f0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object00c1b7f0();
};

class Object00e0fd70 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object00e0fd70();
};

Object00e0fd70::~Object00e0fd70() {}
