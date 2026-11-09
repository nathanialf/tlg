/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x822190, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ab058 (stored by
 * FUN_00510870), slot 1 (0x510ca0) the deleting destructor calling 0x822190
 * before operator delete. The class form: Object00510c90 derives from
 * Object00822190, whose destructor is the one at 0x822190 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00822190 /* derived name */
{
  public:
    virtual ~Object00822190();
};

class Object00510c90 : public Object00822190 /* derived name */
{
  public:
    virtual ~Object00510c90();
};

Object00510c90::~Object00510c90() {}
