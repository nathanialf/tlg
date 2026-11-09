/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xd237d0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16ae900 (stored by no
 * constructor listed); 0x16d18b0 (stored by FUN_00ccaa30); 0x16d2ed0 (stored
 * by FUN_00e82bb0), slot 1 (0x81b380) the deleting destructor calling
 * 0xd237d0 before operator delete. One body for the 3 vtables. The class
 * form: Object0081b370 derives from Object00d237d0, whose destructor is the
 * one at 0xd237d0 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object00d237d0 /* derived name */
{
  public:
    virtual ~Object00d237d0();
};

class Object0081b370 : public Object00d237d0 /* derived name */
{
  public:
    virtual ~Object0081b370();
};

Object0081b370::~Object0081b370() {}
