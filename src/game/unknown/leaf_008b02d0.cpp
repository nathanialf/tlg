/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af820 (stored by FUN_008b01c0 FUN_008b0210): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b02d0 /* derived name */
{
  public:
    virtual ~Object008b02d0();
    virtual void *FUN_008b02f0(); /* derived name */

  private:
    unsigned char stored[16]; /* +0x8, 16 bytes copied by slots 0 and 1 */
};

Object008b02d0::~Object008b02d0() {}

void *Object008b02d0::FUN_008b02f0()
{
    return &stored;
}
