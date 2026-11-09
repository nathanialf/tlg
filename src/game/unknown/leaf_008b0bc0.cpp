/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16afa00 (stored by FUN_008b0ae0 FUN_008b0b20): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b0bc0 /* derived name */
{
  public:
    virtual ~Object008b0bc0();
    virtual void *FUN_008b0be0(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

Object008b0bc0::~Object008b0bc0() {}

void *Object008b0bc0::FUN_008b0be0()
{
    return &stored;
}
