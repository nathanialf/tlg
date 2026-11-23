/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: a 0x60-byte set of twelve references to shared objects,
 * two of them at +0x43e8 and +0x4448 of FUN_00b8e610's object (called at
 * 0xb8ebf4 and 0xb8ec00), the objects' class not traced */
class Object00df96d0 /* derived name */
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
};

/* FUN_00df96d0: the twelve references dropped in the base's order, +0x40
 * down to +0x30, +0x48 up to +0x58, +0x10 down to +0x0, +0x18 up to +0x28 */
void Object00df96d0::releaseShared()
{
    shared40.reset();
    shared38.reset();
    shared30.reset();
    shared48.reset();
    shared50.reset();
    shared58.reset();
    shared10.reset();
    shared8.reset();
    shared0.reset();
    shared18.reset();
    shared20.reset();
    shared28.reset();
}
