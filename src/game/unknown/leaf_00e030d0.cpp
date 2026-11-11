/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose vtable is at 0x16bd600 (stored by FUN_00c027c0
 * FUN_00e030d0): slot 0, FUN_00e030d0, the complete destructor, which clears
 * the two pointers at +0x60 and +0x68 (one 16-byte store), slot 1,
 * FUN_00e030f0, the deleting one (operator delete of the object; the stores
 * are dead before it). The vtable is named by ruling
 * (config/vtables.derived.base.txt, from this destructor's store) and is the
 * game's: the base stores it PC-relative, as the game module compiles a
 * vtable of its own region. */
class Object00e030d0 /* derived name */
{
  public:
    virtual ~Object00e030d0();

  private:
    unsigned char unknown8[0x58];
    void *unknown60; /* +0x60 */
    void *unknown68; /* +0x68 */
};

Object00e030d0::~Object00e030d0()
{
    unknown60 = 0;
    unknown68 = 0;
}
