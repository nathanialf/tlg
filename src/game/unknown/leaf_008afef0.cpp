/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af730 (stored by FUN_008afdd0 FUN_008afe20): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008afef0 /* derived name */
{
  public:
    virtual ~Object008afef0();
    virtual void *FUN_008aff10(); /* derived name */

  private:
    unsigned char stored[16]; /* +0x8, 16 bytes copied by slots 0 and 1 */
};

Object008afef0::~Object008afef0() {}

void *Object008afef0::FUN_008aff10()
{
    return &stored;
}
