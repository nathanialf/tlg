/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x8227e0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16aaf60 (stored by
 * FUN_00510130), slot 1 (0x510310) the deleting destructor calling 0x8227e0
 * before operator delete. The class form: Object00510300 derives from
 * Object008227e0, whose destructor is the one at 0x8227e0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object008227e0 /* derived name */
{
  public:
    virtual ~Object008227e0();
};

class Object00510300 : public Object008227e0 /* derived name */
{
  public:
    virtual ~Object00510300();
};

Object00510300::~Object00510300() {}
