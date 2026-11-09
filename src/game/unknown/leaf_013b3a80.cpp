/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xc324b0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b9cb0 (stored by
 * FUN_001afd70), slot 1 (0xc32920) the deleting destructor calling 0xc324b0
 * before operator delete. The class form: Object013b3a80 derives from
 * Object00c324b0, whose destructor is the one at 0xc324b0 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00c324b0 /* derived name */
{
  public:
    virtual ~Object00c324b0();
};

class Object013b3a80 : public Object00c324b0 /* derived name */
{
  public:
    virtual ~Object013b3a80();
};

Object013b3a80::~Object013b3a80() {}
