/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1392440, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16b4d00 (stored by
 * 0x1392440); 0x16cecc8 (stored by FUN_00b14040); 0x16cecf8 (stored by
 * FUN_00b14040); 0x16ced28 (stored by FUN_00b14040); 0x16ced58 (stored by
 * FUN_00b14040), slot 1 (0x1392630) the deleting destructor calling 0x1392440
 * before operator delete. One body for the 5 vtables. The class form:
 * Object01392620 derives from Object01392440, whose destructor is the one at
 * 0x1392440 (its row named for it, D15), and its own destructor is defined
 * empty out of line. */
class Object01392440 /* derived name */
{
  public:
    virtual ~Object01392440();
};

class Object01392620 : public Object01392440 /* derived name */
{
  public:
    virtual ~Object01392620();
};

Object01392620::~Object01392620() {}
