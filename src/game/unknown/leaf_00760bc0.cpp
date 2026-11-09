/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x204320, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ac868 (stored by
 * FUN_007609e0), slot 1 (0x760bd0) the deleting destructor calling 0x204320
 * before operator delete. The class form: Object00760bc0 derives from
 * Object00204320, whose destructor is the one at 0x204320 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00204320 /* derived name */
{
  public:
    virtual ~Object00204320();
};

class Object00760bc0 : public Object00204320 /* derived name */
{
  public:
    virtual ~Object00760bc0();
};

Object00760bc0::~Object00760bc0() {}
