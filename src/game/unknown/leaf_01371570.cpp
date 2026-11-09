/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1370f10, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16af078 (stored by
 * FUN_0085e360 FUN_0085e950 0x1370f10), slot 1 (0x1371580) the deleting
 * destructor calling 0x1370f10 before operator delete. The class form:
 * Object01371570 derives from Object01370f10, whose destructor is the one at
 * 0x1370f10 (its row named for it, D15), and its own destructor is defined
 * empty out of line. */
class Object01370f10 /* derived name */
{
  public:
    virtual ~Object01370f10();
};

class Object01371570 : public Object01370f10 /* derived name */
{
  public:
    virtual ~Object01371570();
};

Object01371570::~Object01371570() {}
