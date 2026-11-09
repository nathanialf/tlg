/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xb40050, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtable at 0x16b5ae8 (stored by
 * FUN_00b3f8e0), slot 1 (0x13974a0) the deleting destructor calling 0xb40050
 * before operator delete. The class form: Object01397490 derives from
 * Object00b40050, whose destructor is the one at 0xb40050 (its row named for
 * it, D15), and its own destructor is defined empty out of line. */
class Object00b40050 /* derived name */
{
  public:
    virtual ~Object00b40050();
};

class Object01397490 : public Object00b40050 /* derived name */
{
  public:
    virtual ~Object01397490();
};

Object01397490::~Object01397490() {}
