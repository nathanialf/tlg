/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x135e680, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16cb318 (stored by
 * FUN_00615670 FUN_007204d0 0x135e680); 0x16cb358 (stored by FUN_00615670
 * FUN_007204d0), slot 1 (0x135f620) the deleting destructor calling 0x135e680
 * before operator delete. One body for the 2 vtables. The class form:
 * Object0135f4d0 derives from Object0135e680, whose destructor is the one at
 * 0x135e680 (its row named for it, D15), and its own destructor is defined
 * empty out of line. */
class Object0135e680 /* derived name */
{
  public:
    virtual ~Object0135e680();
};

class Object0135f4d0 : public Object0135e680 /* derived name */
{
  public:
    virtual ~Object0135f4d0();
};

Object0135f4d0::~Object0135f4d0() {}
