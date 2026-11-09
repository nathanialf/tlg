/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13d35e0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d3b48 (stored by
 * FUN_013d31a0 0x13d35e0), slot 1 (0x13d6900) the deleting destructor calling
 * 0x13d35e0 before operator delete. The class form: Object013d68f0 derives
 * from Object013d35e0, whose destructor is the one at 0x13d35e0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013d35e0 /* derived name */
{
  public:
    virtual ~Object013d35e0();
};

class Object013d68f0 : public Object013d35e0 /* derived name */
{
  public:
    virtual ~Object013d68f0();
};

Object013d68f0::~Object013d68f0() {}
