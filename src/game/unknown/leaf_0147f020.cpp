/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x147d810, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16cab48 (stored by
 * 0x147d810 FUN_0147e1f0); 0x16d6e10 (stored by FUN_0122be10); 0x16d6e68
 * (stored by FUN_0122be10); 0x16d6ec0 (stored by FUN_0122be10); 0x16d6f18
 * (stored by FUN_0122be10); 0x16d6f70 (stored by FUN_0122be10); 0x16d6fc8
 * (stored by FUN_0122be10); 0x16d7020 (stored by FUN_0122be10); 0x16d7078
 * (stored by FUN_0122be10), slot 1 (0x147f030) the deleting destructor
 * calling 0x147d810 before operator delete. One body for the 9 vtables. The
 * class form: Object0147f020 derives from Object0147d810, whose destructor is
 * the one at 0x147d810 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object0147d810 /* derived name */
{
  public:
    virtual ~Object0147d810();
};

class Object0147f020 : public Object0147d810 /* derived name */
{
  public:
    virtual ~Object0147f020();
};

Object0147f020::~Object0147f020() {}
