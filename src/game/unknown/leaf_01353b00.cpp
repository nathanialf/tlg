/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1353b30, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16cae48 (stored by
 * FUN_013534f0 0x1353b30), slot 1 (0x1353b10) the deleting destructor calling
 * 0x1353b30 before operator delete. The class form: Object01353b00 derives
 * from Object01353b30, whose destructor is the one at 0x1353b30 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01353b30 /* derived name */
{
  public:
    virtual ~Object01353b30();
};

class Object01353b00 : public Object01353b30 /* derived name */
{
  public:
    virtual ~Object01353b00();
};

Object01353b00::~Object01353b00() {}
