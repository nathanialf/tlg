/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af550 (stored by FUN_0088b4e0 FUN_008af160 FUN_008af1d0): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object008af640 /* derived name */
{
  public:
    virtual ~Object008af640();
    virtual void *FUN_008af660(); /* derived name */

  private:
    unsigned char stored[160]; /* +0x8, 160 bytes copied by slots 0 and 1 */
};

Object008af640::~Object008af640() {}

void *Object008af640::FUN_008af660()
{
    return &stored;
}
