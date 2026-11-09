/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x83df00, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b65f8 (stored by
 * FUN_00b4c8b0), slot 1 (0xb4ca30) the deleting destructor calling 0x83df00
 * before operator delete. The class form: Object00b4ca20 derives from
 * Object0083df00, whose destructor is the one at 0x83df00 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object0083df00 /* derived name */
{
  public:
    virtual ~Object0083df00();
};

class Object00b4ca20 : public Object0083df00 /* derived name */
{
  public:
    virtual ~Object00b4ca20();
};

Object00b4ca20::~Object00b4ca20() {}
