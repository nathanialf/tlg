/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13e1850, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16ca330 (stored by
 * FUN_00f9ab50 0x13e1850); 0x16d3fe0 (stored by FUN_00f9ab50); 0x16d4038
 * (stored by FUN_00f9ab50); 0x16d4aa8 (stored by FUN_00f9ab50); 0x16d4b00
 * (stored by FUN_00f9ab50), slot 1 (0x13e44c0) the deleting destructor
 * calling 0x13e1850 before operator delete. One body for the 5 vtables. The
 * class form: Object013e44b0 derives from Object013e1850, whose destructor is
 * the one at 0x13e1850 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object013e1850 /* derived name */
{
  public:
    virtual ~Object013e1850();
};

class Object013e44b0 : public Object013e1850 /* derived name */
{
  public:
    virtual ~Object013e44b0();
};

Object013e44b0::~Object013e44b0() {}
