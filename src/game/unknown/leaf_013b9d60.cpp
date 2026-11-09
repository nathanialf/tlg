/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13b9d70, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ba8e0 (stored by
 * FUN_00d5f7d0 0x13b9d70), slot 1 (0x13ba170) the deleting destructor calling
 * 0x13b9d70 before operator delete. The class form: Object013b9d60 derives
 * from Object013b9d70, whose destructor is the one at 0x13b9d70 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013b9d70 /* derived name */
{
  public:
    virtual ~Object013b9d70();
};

class Object013b9d60 : public Object013b9d70 /* derived name */
{
  public:
    virtual ~Object013b9d60();
};

Object013b9d60::~Object013b9d60() {}
