/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xbdcda0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16ce9b8 (stored by
 * FUN_00ae88e0), slot 1 (0xbdd0b0) the deleting destructor calling 0xbdcda0
 * before operator delete. The class form: Object0138eab0 derives from
 * Object00bdcda0, whose destructor is the one at 0xbdcda0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00bdcda0 /* derived name */
{
  public:
    virtual ~Object00bdcda0();
};

class Object0138eab0 : public Object00bdcda0 /* derived name */
{
  public:
    virtual ~Object0138eab0();
};

Object0138eab0::~Object0138eab0() {}
