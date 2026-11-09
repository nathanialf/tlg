/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x8227e0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16ab140 (stored by
 * FUN_00510fa0); 0x16c7608 (stored by FUN_00344a60); 0x16cb520 (stored by
 * FUN_006743e0), slot 1 (0x511170) the deleting destructor calling 0x8227e0
 * before operator delete. One body for the 3 vtables. The class form:
 * Object00511160 derives from Object008227e0, whose destructor is the one at
 * 0x8227e0 (its row named for it, D15), and its own destructor is defined
 * empty out of line. */
class Object008227e0 /* derived name */
{
  public:
    virtual ~Object008227e0();
};

class Object00511160 : public Object008227e0 /* derived name */
{
  public:
    virtual ~Object00511160();
};

Object00511160::~Object00511160() {}
