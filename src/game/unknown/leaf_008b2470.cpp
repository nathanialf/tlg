/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16afe60 (stored by FUN_008b21e0 FUN_008b2230): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b2470 /* derived name */
{
  public:
    virtual ~Object008b2470();
    virtual void *FUN_008b2490(); /* derived name */

  private:
    unsigned char stored[48]; /* +0x8, 48 bytes copied by slots 0 and 1 */
};

Object008b2470::~Object008b2470() {}

void *Object008b2470::FUN_008b2490()
{
    return &stored;
}
