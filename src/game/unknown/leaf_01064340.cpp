/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c10d8 (stored by FUN_01061610 FUN_01064210 FUN_01064250): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object01064340 /* derived name */
{
  public:
    virtual ~Object01064340();
    virtual void *FUN_01064360(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

Object01064340::~Object01064340() {}

void *Object01064340::FUN_01064360()
{
    return &stored;
}
