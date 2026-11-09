/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x137e6e0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16c7b78 (stored by
 * FUN_00958460 0x137e6e0), slot 1 (0x137e240) the deleting destructor calling
 * 0x137e6e0 before operator delete. The class form: Object0137e230 derives
 * from Object0137e6e0, whose destructor is the one at 0x137e6e0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object0137e6e0 /* derived name */
{
  public:
    virtual ~Object0137e6e0();
};

class Object0137e230 : public Object0137e6e0 /* derived name */
{
  public:
    virtual ~Object0137e230();
};

Object0137e230::~Object0137e230() {}
