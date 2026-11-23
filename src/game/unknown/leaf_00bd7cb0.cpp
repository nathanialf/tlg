/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00bd7e30.h"
#include "tlg_game_shared.h"

/* derived names: the object at +0x80 of the object FUN_00dfb810's object
 * holds at +0x48 (called at 0xdfc434 and 0xdfc9c9): references to shared
 * objects at +0x0, +0x8 and +0x60 to +0x78 and to counted objects at +0x10
 * and +0x18; the objects' classes and the other fields are not traced */
class Object00bd7cb0 /* derived name */
{
  public:
    void releaseShared(); /* derived name */

  private:
    SharedRef00901550<Shared00901550> shared0; /* +0x0 */
    SharedRef00901550<Shared00901550> shared8; /* +0x8 */
    Counted00bd7e30 *counted10;                /* +0x10 */
    Counted00bd7e30 *counted18;                /* +0x18 */
    u8 unknown20[0x40];
    SharedRef00901550<Shared00901550> shared60; /* +0x60 */
    SharedRef00901550<Shared00901550> shared68; /* +0x68 */
    SharedRef00901550<Shared00901550> shared70; /* +0x70 */
    SharedRef00901550<Shared00901550> shared78; /* +0x78 */
};

/* FUN_00bd7cb0: the counted references dropped first, then the shared ones
 * up from +0x0 */
void Object00bd7cb0::releaseShared()
{
    releaseAndClear(counted10);
    releaseAndClear(counted18);
    shared0.reset();
    shared8.reset();
    shared60.reset();
    shared68.reset();
    shared70.reset();
    shared78.reset();
}
