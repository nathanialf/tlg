/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16ab358 (stored by FUN_0052c710 FUN_0052d4b0 FUN_0052d9c0): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object0052dae0 /* derived name */
{
  public:
    virtual ~Object0052dae0();
    virtual void *FUN_0052db00(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

Object0052dae0::~Object0052dae0() {}

void *Object0052dae0::FUN_0052db00()
{
    return &stored;
}
