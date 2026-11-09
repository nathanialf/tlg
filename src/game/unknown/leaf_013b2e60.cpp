/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xced570, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b9958 (stored by
 * FUN_00cef2f0), slot 1 (0x13b2e70) the deleting destructor calling 0xced570
 * before operator delete. The class form: Object013b2e60 derives from
 * Object00ced570, whose destructor is the one at 0xced570 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00ced570 /* derived name */
{
  public:
    virtual ~Object00ced570();
};

class Object013b2e60 : public Object00ced570 /* derived name */
{
  public:
    virtual ~Object013b2e60();
};

Object013b2e60::~Object013b2e60() {}
