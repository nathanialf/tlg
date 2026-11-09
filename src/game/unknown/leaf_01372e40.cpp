/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1372e50, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16cc378 (stored by
 * FUN_00886dc0 FUN_0088b4e0 FUN_008a4490 0x1372e50), slot 1 (0x1373220) the
 * deleting destructor calling 0x1372e50 before operator delete. The class
 * form: Object01372e40 derives from Object01372e50, whose destructor is the
 * one at 0x1372e50 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object01372e50 /* derived name */
{
  public:
    virtual ~Object01372e50();
};

class Object01372e40 : public Object01372e50 /* derived name */
{
  public:
    virtual ~Object01372e40();
};

Object01372e40::~Object01372e40() {}
