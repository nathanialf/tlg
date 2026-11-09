/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x818d10, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16aef38 (stored by
 * FUN_00845fb0), slot 1 (0x846b10) the deleting destructor calling 0x818d10
 * before operator delete. The class form: Object00846b00 derives from
 * Object00818d10, whose destructor is the one at 0x818d10 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00818d10 /* derived name */
{
  public:
    virtual ~Object00818d10();
};

class Object00846b00 : public Object00818d10 /* derived name */
{
  public:
    virtual ~Object00846b00();
};

Object00846b00::~Object00846b00() {}
