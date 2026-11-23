/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: a 0x68-byte object holding twelve references to shared
 * objects at +0x0 to +0x58, four of them at +0x110, +0x178, +0x1e0 and
 * +0x248 of FUN_00dfb810's object (called at 0xdfc387 to 0xdfc3b5); the
 * objects' class and the last eight bytes are not traced */
class Object00e983b0 /* derived name */
{
  public:
    void releaseShared(); /* derived name */

  private:
    SharedRef00901550<Shared00901550> shared0;  /* +0x0 */
    SharedRef00901550<Shared00901550> shared8;  /* +0x8 */
    SharedRef00901550<Shared00901550> shared10; /* +0x10 */
    SharedRef00901550<Shared00901550> shared18; /* +0x18 */
    SharedRef00901550<Shared00901550> shared20; /* +0x20 */
    SharedRef00901550<Shared00901550> shared28; /* +0x28 */
    SharedRef00901550<Shared00901550> shared30; /* +0x30 */
    SharedRef00901550<Shared00901550> shared38; /* +0x38 */
    SharedRef00901550<Shared00901550> shared40; /* +0x40 */
    SharedRef00901550<Shared00901550> shared48; /* +0x48 */
    SharedRef00901550<Shared00901550> shared50; /* +0x50 */
    SharedRef00901550<Shared00901550> shared58; /* +0x58 */
    u8 unknown60[0x8];
};

/* FUN_00e983b0: the twelve references dropped in the base's order, the
 * first three, then the two halves' alternately from +0x38 and +0x18, the
 * last of the first half at +0x30 before +0x58 */
void Object00e983b0::releaseShared()
{
    shared0.reset();
    shared8.reset();
    shared10.reset();
    shared38.reset();
    shared18.reset();
    shared40.reset();
    shared20.reset();
    shared48.reset();
    shared28.reset();
    shared50.reset();
    shared30.reset();
    shared58.reset();
}
