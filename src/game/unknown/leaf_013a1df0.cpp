/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13a1e00, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16d05f8 (stored by
 * 0x13a1e00), slot 1 (0x13a2160) the deleting destructor calling 0x13a1e00
 * before operator delete. The class form: Object013a1df0 derives from
 * Object013a1e00, whose destructor is the one at 0x13a1e00 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object013a1e00 /* derived name */
{
  public:
    virtual ~Object013a1e00();
};

class Object013a1df0 : public Object013a1e00 /* derived name */
{
  public:
    virtual ~Object013a1df0();
};

Object013a1df0::~Object013a1df0() {}
