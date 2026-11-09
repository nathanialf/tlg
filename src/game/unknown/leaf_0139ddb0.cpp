/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x139dbd0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d01a8 (stored by
 * FUN_00b8c400 0x139dbd0), slot 1 (0x139ddc0) the deleting destructor calling
 * 0x139dbd0 before operator delete. The class form: Object0139ddb0 derives
 * from Object0139dbd0, whose destructor is the one at 0x139dbd0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object0139dbd0 /* derived name */
{
  public:
    virtual ~Object0139dbd0();
};

class Object0139ddb0 : public Object0139dbd0 /* derived name */
{
  public:
    virtual ~Object0139ddb0();
};

Object0139ddb0::~Object0139ddb0() {}
