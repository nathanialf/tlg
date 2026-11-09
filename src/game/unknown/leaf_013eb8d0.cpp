/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13eb8e0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16c0938 (stored by
 * FUN_00fe2710); 0x16d4de8 (stored by FUN_00fe2710 0x13eb8e0), slot 1
 * (0x13ebcd0) the deleting destructor calling 0x13eb8e0 before operator
 * delete. One body for the 2 vtables. The class form: Object013eb8d0 derives
 * from Object013eb8e0, whose destructor is the one at 0x13eb8e0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013eb8e0 /* derived name */
{
  public:
    virtual ~Object013eb8e0();
};

class Object013eb8d0 : public Object013eb8e0 /* derived name */
{
  public:
    virtual ~Object013eb8d0();
};

Object013eb8d0::~Object013eb8d0() {}
