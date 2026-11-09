/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13b3ae0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d20e0 (stored by
 * FUN_00d0ae60 0x13b3ae0), slot 1 (0x13b3ac0) the deleting destructor calling
 * 0x13b3ae0 before operator delete. The class form: Object013b3ab0 derives
 * from Object013b3ae0, whose destructor is the one at 0x13b3ae0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013b3ae0 /* derived name */
{
  public:
    virtual ~Object013b3ae0();
};

class Object013b3ab0 : public Object013b3ae0 /* derived name */
{
  public:
    virtual ~Object013b3ab0();
};

Object013b3ab0::~Object013b3ab0() {}
