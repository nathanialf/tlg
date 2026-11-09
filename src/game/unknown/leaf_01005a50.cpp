/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c0aa0 (stored by FUN_01005980 FUN_010059c0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01005a50 /* derived name */
{
  public:
    virtual ~Object01005a50();
    virtual void *FUN_01005a70(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

Object01005a50::~Object01005a50() {}

void *Object01005a50::FUN_01005a70()
{
    return &stored;
}
