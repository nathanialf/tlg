/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x83df00, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16cd900 (stored by
 * FUN_009b4960), slot 1 (0x1383fc0) the deleting destructor calling 0x83df00
 * before operator delete. The class form: Object01383fb0 derives from
 * Object0083df00, whose destructor is the one at 0x83df00 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object0083df00 /* derived name */
{
  public:
    virtual ~Object0083df00();
};

class Object01383fb0 : public Object0083df00 /* derived name */
{
  public:
    virtual ~Object01383fb0();
};

Object01383fb0::~Object01383fb0() {}
