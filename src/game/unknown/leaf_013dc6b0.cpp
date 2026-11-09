/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13dc6c0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d4b58 (stored by
 * FUN_00f96270 0x13dc6c0), slot 1 (0x13e02d0) the deleting destructor calling
 * 0x13dc6c0 before operator delete. The class form: Object013dc6b0 derives
 * from Object013dc6c0, whose destructor is the one at 0x13dc6c0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013dc6c0 /* derived name */
{
  public:
    virtual ~Object013dc6c0();
};

class Object013dc6b0 : public Object013dc6c0 /* derived name */
{
  public:
    virtual ~Object013dc6b0();
};

Object013dc6b0::~Object013dc6b0() {}
