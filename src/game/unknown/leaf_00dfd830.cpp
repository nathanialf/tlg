/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00bd7e30.h"
#include "tlg_game_shared.h"

/* derived names: the object at +0x3d80 of FUN_00b8e610's object (called at
 * 0xb8e8d1 and 0xb905a4): references to counted objects at +0x0 and +0x8
 * and to shared objects at +0x10 to +0x30; the objects' classes are not
 * traced */
class Object00dfd830 /* derived name */
{
  public:
    void releaseShared(); /* derived name */

  private:
    Counted00bd7e30 *counted0;                  /* +0x0 */
    Counted00bd7e30 *counted8;                  /* +0x8 */
    SharedRef00901550<Shared00901550> shared10; /* +0x10 */
    SharedRef00901550<Shared00901550> shared18; /* +0x18 */
    SharedRef00901550<Shared00901550> shared20; /* +0x20 */
    SharedRef00901550<Shared00901550> shared28; /* +0x28 */
    SharedRef00901550<Shared00901550> shared30; /* +0x30 */
};

/* FUN_00dfd830: the shared references dropped up from +0x10, then the
 * counted ones, +0x8 first */
void Object00dfd830::releaseShared()
{
    shared10.reset();
    shared18.reset();
    shared20.reset();
    shared28.reset();
    shared30.reset();
    releaseAndClear(counted8);
    releaseAndClear(counted0);
}
