/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x774560, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16aca58 (stored by no
 * constructor listed), slot 1 (0x765610) the deleting destructor calling
 * 0x774560 before operator delete. The class form: Object00765600 derives
 * from Object00774560, whose destructor is the one at 0x774560 (its row named
 * for it, D15), and its own destructor is defined empty out of line. */
class Object00774560 /* derived name */
{
  public:
    virtual ~Object00774560();
};

class Object00765600 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object00765600();
};

Object00765600::~Object00765600() {}
