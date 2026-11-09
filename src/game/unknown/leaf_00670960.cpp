/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x822440, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16a8980 (stored by
 * FUN_0035b210); 0x16ac108 (stored by FUN_00670560), slot 1 (0x670970) the
 * deleting destructor calling 0x822440 before operator delete. One body for
 * the 2 vtables. The class form: Object00670960 derives from Object00822440,
 * whose destructor is the one at 0x822440 (its row named for it, D15), and
 * its own destructor is defined empty out of line. */
class Object00822440 /* derived name */
{
  public:
    virtual ~Object00822440();
};

class Object00670960 : public Object00822440 /* derived name */
{
  public:
    virtual ~Object00670960();
};

Object00670960::~Object00670960() {}
