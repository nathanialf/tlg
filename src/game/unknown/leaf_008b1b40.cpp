/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16afd20 (stored by FUN_008b1a60 FUN_008b1aa0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b1b40 /* derived name */
{
  public:
    virtual ~Object008b1b40();
    virtual void *FUN_008b1b60(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

Object008b1b40::~Object008b1b40() {}

void *Object008b1b40::FUN_008b1b60()
{
    return &stored;
}
