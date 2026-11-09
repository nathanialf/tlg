/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xbde1c0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b3e30 (stored by
 * FUN_00ae8350), slot 1 (0xae8580) the deleting destructor calling 0xbde1c0
 * before operator delete. The class form: Object00ae8570 derives from
 * Object00bde1c0, whose destructor is the one at 0xbde1c0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00bde1c0 /* derived name */
{
  public:
    virtual ~Object00bde1c0();
};

class Object00ae8570 : public Object00bde1c0 /* derived name */
{
  public:
    virtual ~Object00ae8570();
};

Object00ae8570::~Object00ae8570() {}
