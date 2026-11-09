/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x82f900, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ae4d0 (stored by
 * FUN_00811b30), slot 1 (0x811cf0) the deleting destructor calling 0x82f900
 * before operator delete. The class form: Object00811ce0 derives from
 * Object0082f900, whose destructor is the one at 0x82f900 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object0082f900 /* derived name */
{
  public:
    virtual ~Object0082f900();
};

class Object00811ce0 : public Object0082f900 /* derived name */
{
  public:
    virtual ~Object00811ce0();
};

Object00811ce0::~Object00811ce0() {}
