/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc55550, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16bdf18 (stored by
 * FUN_00e64640), slot 1 (0xe647b0) the deleting destructor calling 0xc55550
 * before operator delete. The class form: Object00e647a0 derives from
 * Object00c55550, whose destructor is the one at 0xc55550 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00c55550 /* derived name */
{
  public:
    virtual ~Object00c55550();
};

class Object00e647a0 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object00e647a0();
};

Object00e647a0::~Object00e647a0() {}
