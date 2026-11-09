/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x822190, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16a8910 (stored by
 * FUN_0035b0a0); 0x16aae78 (stored by FUN_0050b980), slot 1 (0x50c190) the
 * deleting destructor calling 0x822190 before operator delete. One body for
 * the 2 vtables. The class form: Object0050c180 derives from Object00822190,
 * whose destructor is the one at 0x822190 (its row named for it, D15), and
 * its own destructor is defined empty out of line. */
class Object00822190 /* derived name */
{
  public:
    virtual ~Object00822190();
};

class Object0050c180 : public Object00822190 /* derived name */
{
  public:
    virtual ~Object0050c180();
};

Object0050c180::~Object0050c180() {}
