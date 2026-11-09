/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16aac30 (stored by FUN_00506a00 FUN_00506a40): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object00506ac0 /* derived name */
{
  public:
    virtual ~Object00506ac0();
    virtual void *FUN_00506ae0(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

Object00506ac0::~Object00506ac0() {}

void *Object00506ac0::FUN_00506ae0()
{
    return &stored;
}
