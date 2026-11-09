/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13671a0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16be190 (stored by
 * FUN_00e8ed90); 0x16cb7d0 (stored by 0x13671a0); 0x16d1930 (stored by
 * FUN_00ccafe0); 0x16d1cf8 (stored by FUN_00cd7490), slot 1 (0x13cbb20) the
 * deleting destructor calling 0x13671a0 before operator delete. One body for
 * the 4 vtables. The class form: Object013cbb10 derives from Object013671a0,
 * whose destructor is the one at 0x13671a0 (its row named for it, D15), and
 * its own destructor is defined empty out of line. */
class Object013671a0 /* derived name */
{
  public:
    virtual ~Object013671a0();
};

class Object013cbb10 : public Object013671a0 /* derived name */
{
  public:
    virtual ~Object013cbb10();
};

Object013cbb10::~Object013cbb10() {}
