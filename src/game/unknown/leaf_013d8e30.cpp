/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13d8e40, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d3e10 (stored by 0x13d8e40
 * FUN_013d93b0), slot 1 (0x13d8f80) the deleting destructor calling 0x13d8e40
 * before operator delete. The class form: Object013d8e30 derives from
 * Object013d8e40, whose destructor is the one at 0x13d8e40 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object013d8e40 /* derived name */
{
  public:
    virtual ~Object013d8e40();
};

class Object013d8e30 : public Object013d8e40 /* derived name */
{
  public:
    virtual ~Object013d8e30();
};

Object013d8e30::~Object013d8e30() {}
