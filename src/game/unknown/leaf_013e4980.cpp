/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13e1b30, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16ca568 (stored by
 * 0x13e1b30 FUN_013e30b0); 0x16d4630 (stored by FUN_00fbaf70); 0x16d4688
 * (stored by FUN_00fbaf70); 0x16d46e0 (stored by FUN_00fbadf0); 0x16d4738
 * (stored by FUN_00fbadf0); 0x16d4790 (stored by FUN_00fbac70); 0x16d47e8
 * (stored by FUN_00fbac70); 0x16d4840 (stored by FUN_00fbaaf0); 0x16d4898
 * (stored by FUN_00fbaaf0), slot 1 (0x13e4990) the deleting destructor
 * calling 0x13e1b30 before operator delete. One body for the 9 vtables. The
 * class form: Object013e4980 derives from Object013e1b30, whose destructor is
 * the one at 0x13e1b30 (its row named for it, D15), and its own destructor is
 * defined empty out of line. */
class Object013e1b30 /* derived name */
{
  public:
    virtual ~Object013e1b30();
};

class Object013e4980 : public Object013e1b30 /* derived name */
{
  public:
    virtual ~Object013e4980();
};

Object013e4980::~Object013e4980() {}
