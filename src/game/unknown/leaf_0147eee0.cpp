/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x147d190, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16ca8b0 (stored by
 * FUN_0122be10 0x147d190); 0x16d6bf0 (stored by FUN_0122be10); 0x16d6c48
 * (stored by FUN_0122be10); 0x16d73e8 (stored by FUN_0122be10); 0x16d7440
 * (stored by FUN_0122be10), slot 1 (0x147eef0) the deleting destructor
 * calling 0x147d190 before operator delete. One body for the 5 vtables. The
 * class form: Object0147eee0 derives from Object0147d190, whose destructor is
 * the one at 0x147d190 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object0147d190 /* derived name */
{
  public:
    virtual ~Object0147d190();
};

class Object0147eee0 : public Object0147d190 /* derived name */
{
  public:
    virtual ~Object0147eee0();
};

Object0147eee0::~Object0147eee0() {}
