/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc1b7f0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b81d0 (stored by
 * FUN_00c1ce60), slot 1 (0xc1d570) the deleting destructor calling 0xc1b7f0
 * before operator delete. The class form: Object00c1d560 derives from
 * Object00c1b7f0, whose destructor is the one at 0xc1b7f0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object00c1b7f0();
};

class Object00c1d560 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object00c1d560();
};

Object00c1d560::~Object00c1d560() {}
