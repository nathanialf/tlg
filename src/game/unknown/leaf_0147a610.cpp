/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x147a620, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d7498 (stored by
 * FUN_01227740 0x147a620), slot 1 (0x147bc10) the deleting destructor calling
 * 0x147a620 before operator delete. The class form: Object0147a610 derives
 * from Object0147a620, whose destructor is the one at 0x147a620 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object0147a620 /* derived name */
{
  public:
    virtual ~Object0147a620();
};

class Object0147a610 : public Object0147a620 /* derived name */
{
  public:
    virtual ~Object0147a610();
};

Object0147a610::~Object0147a610() {}
