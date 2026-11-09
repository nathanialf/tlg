/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c2ba0 (stored by FUN_01270c70 FUN_01270cb0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01270d40 /* derived name */
{
  public:
    virtual ~Object01270d40();
    virtual void *FUN_01270d60(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

Object01270d40::~Object01270d40() {}

void *Object01270d40::FUN_01270d60()
{
    return &stored;
}
