/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c2bf0 (stored by FUN_01270d70 FUN_01270dc0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01270e70 /* derived name */
{
  public:
    virtual ~Object01270e70();
    virtual void *FUN_01270e90(); /* derived name */

  private:
    unsigned char stored[16]; /* +0x8, 16 bytes copied by slots 0 and 1 */
};

Object01270e70::~Object01270e70() {}

void *Object01270e70::FUN_01270e90()
{
    return &stored;
}
