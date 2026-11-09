/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x147d450, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16caa48 (stored by
 * 0x147d450 FUN_0147ddb0); 0x16d70d0 (stored by FUN_0122be10); 0x16d7128
 * (stored by FUN_0122be10); 0x16d7180 (stored by FUN_0122be10); 0x16d71d8
 * (stored by FUN_0122be10); 0x16d7230 (stored by FUN_0122be10); 0x16d7288
 * (stored by FUN_0122be10); 0x16d72e0 (stored by FUN_0122be10); 0x16d7338
 * (stored by FUN_0122be10), slot 1 (0x147f060) the deleting destructor
 * calling 0x147d450 before operator delete. One body for the 9 vtables. The
 * class form: Object0147f050 derives from Object0147d450, whose destructor is
 * the one at 0x147d450 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object0147d450 /* derived name */
{
  public:
    virtual ~Object0147d450();
};

class Object0147f050 : public Object0147d450 /* derived name */
{
  public:
    virtual ~Object0147f050();
};

Object0147f050::~Object0147f050() {}
