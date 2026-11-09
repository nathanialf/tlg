/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x131fdb0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16d7f58 (stored by
 * FUN_01306590); 0x16d7f80 (stored by FUN_01309e50), slot 1 (0x131fe80) the
 * deleting destructor calling 0x131fdb0 before operator delete. One body for
 * the 2 vtables. The class form: Object01496c00 derives from Object0131fdb0,
 * whose destructor is the one at 0x131fdb0 (its row named for it, D15), and
 * its own destructor is defined empty out of line. */
class Object0131fdb0 /* derived name */
{
  public:
    virtual ~Object0131fdb0();
};

class Object01496c00 : public Object0131fdb0 /* derived name */
{
  public:
    virtual ~Object01496c00();
};

Object01496c00::~Object01496c00() {}
