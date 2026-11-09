/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc19090, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b7860 (stored by
 * FUN_00bdb9d0), slot 1 (0xbdbf60) the deleting destructor calling 0xc19090
 * before operator delete. The class form: Object00bdbf50 derives from
 * Object00c19090, whose destructor is the one at 0xc19090 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00c19090 /* derived name */
{
  public:
    virtual ~Object00c19090();
};

class Object00bdbf50 : public Object00c19090 /* derived name */
{
  public:
    virtual ~Object00bdbf50();
};

Object00bdbf50::~Object00bdbf50() {}
