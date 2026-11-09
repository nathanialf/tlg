/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13e4510, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d4348 (stored by
 * FUN_013dfef0 0x13e4510), slot 1 (0x13e44f0) the deleting destructor calling
 * 0x13e4510 before operator delete. The class form: Object013e44e0 derives
 * from Object013e4510, whose destructor is the one at 0x13e4510 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013e4510 /* derived name */
{
  public:
    virtual ~Object013e4510();
};

class Object013e44e0 : public Object013e4510 /* derived name */
{
  public:
    virtual ~Object013e44e0();
};

Object013e44e0::~Object013e44e0() {}
