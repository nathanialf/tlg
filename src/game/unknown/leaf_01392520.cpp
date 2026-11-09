/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1392530, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b4d58 (stored by
 * FUN_00b14040 0x1392530), slot 1 (0x1392600) the deleting destructor calling
 * 0x1392530 before operator delete. The class form: Object01392520 derives
 * from Object01392530, whose destructor is the one at 0x1392530 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01392530 /* derived name */
{
  public:
    virtual ~Object01392530();
};

class Object01392520 : public Object01392530 /* derived name */
{
  public:
    virtual ~Object01392520();
};

Object01392520::~Object01392520() {}
