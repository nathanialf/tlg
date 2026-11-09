/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13752a0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16cc5b8 (stored by
 * FUN_009232e0 0x13752a0), slot 1 (0x1375570) the deleting destructor calling
 * 0x13752a0 before operator delete. The class form: Object01375290 derives
 * from Object013752a0, whose destructor is the one at 0x13752a0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013752a0 /* derived name */
{
  public:
    virtual ~Object013752a0();
};

class Object01375290 : public Object013752a0 /* derived name */
{
  public:
    virtual ~Object01375290();
};

Object01375290::~Object01375290() {}
