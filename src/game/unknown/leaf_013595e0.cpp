/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1358d70, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16cb108 (stored by
 * FUN_013589f0 0x1358d70), slot 1 (0x13595f0) the deleting destructor calling
 * 0x1358d70 before operator delete. The class form: Object013595e0 derives
 * from Object01358d70, whose destructor is the one at 0x1358d70 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01358d70 /* derived name */
{
  public:
    virtual ~Object01358d70();
};

class Object013595e0 : public Object01358d70 /* derived name */
{
  public:
    virtual ~Object013595e0();
};

Object013595e0::~Object013595e0() {}
