/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16ab448 (stored by FUN_0052c710 FUN_0052d570 FUN_0052dcd0): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object0052dd70 /* derived name */
{
  public:
    virtual ~Object0052dd70();
    virtual void *FUN_0052dd90(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

Object0052dd70::~Object0052dd70() {}

void *Object0052dd70::FUN_0052dd90()
{
    return &stored;
}
