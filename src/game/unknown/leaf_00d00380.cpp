/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xd693d0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b9d90 (stored by no
 * constructor listed), slot 1 (0xd00390) the deleting destructor calling
 * 0xd693d0 before operator delete. The class form: Object00d00380 derives
 * from Object00d693d0, whose destructor is the one at 0xd693d0 (its row named
 * for it, D15), and its own destructor is defined empty out of line. */
class Object00d693d0 /* derived name */
{
  public:
    virtual ~Object00d693d0();
};

class Object00d00380 : public Object00d693d0 /* derived name */
{
  public:
    virtual ~Object00d00380();
};

Object00d00380::~Object00d00380() {}
