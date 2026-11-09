/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af4b0 (stored by FUN_0088b4e0 FUN_008aef30 FUN_008aef70): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object008af030 /* derived name */
{
  public:
    virtual ~Object008af030();
    virtual void *FUN_008af050(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

Object008af030::~Object008af030() {}

void *Object008af030::FUN_008af050()
{
    return &stored;
}
