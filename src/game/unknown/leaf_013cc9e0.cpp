/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0xeb2af0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16be710 (stored by no
 * constructor listed); 0x16be7c0 (stored by no constructor listed); 0x16be950
 * (stored by no constructor listed), slot 1 (0x13cc9f0) the deleting
 * destructor calling 0xeb2af0 before operator delete. One body for the 3
 * vtables. The class form: Object013cc9e0 derives from Object00eb2af0, whose
 * destructor is the one at 0xeb2af0 (its row named for it, D15), and its own
 * destructor is defined empty out of line. */
class Object00eb2af0 /* derived name */
{
  public:
    virtual ~Object00eb2af0();
};

class Object013cc9e0 : public Object00eb2af0 /* derived name */
{
  public:
    virtual ~Object013cc9e0();
};

Object013cc9e0::~Object013cc9e0() {}
