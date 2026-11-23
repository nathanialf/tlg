/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: FUN_00b8e610's object (called at 0xb8eedb with the object
 * itself, and by FUN_00b91750 at 0xb91ad6): ten references to shared
 * objects at +0x3b70 to +0x3bb8, the objects' class not traced. The other
 * fields are not traced. */
class Object00bc1a50 /* derived name */
{
  public:
    void releaseShared(); /* derived name */

  private:
    u8 unknown0[0x3b70];
    SharedRef00901550<Shared00901550> shared3b70; /* +0x3b70 */
    SharedRef00901550<Shared00901550> shared3b78; /* +0x3b78 */
    SharedRef00901550<Shared00901550> shared3b80; /* +0x3b80 */
    SharedRef00901550<Shared00901550> shared3b88; /* +0x3b88 */
    SharedRef00901550<Shared00901550> shared3b90; /* +0x3b90 */
    SharedRef00901550<Shared00901550> shared3b98; /* +0x3b98 */
    SharedRef00901550<Shared00901550> shared3ba0; /* +0x3ba0 */
    SharedRef00901550<Shared00901550> shared3ba8; /* +0x3ba8 */
    SharedRef00901550<Shared00901550> shared3bb0; /* +0x3bb0 */
    SharedRef00901550<Shared00901550> shared3bb8; /* +0x3bb8 */
};

/* FUN_00bc1a50: the ten references dropped in order */
void Object00bc1a50::releaseShared()
{
    shared3b70.reset();
    shared3b78.reset();
    shared3b80.reset();
    shared3b88.reset();
    shared3b90.reset();
    shared3b98.reset();
    shared3ba0.reset();
    shared3ba8.reset();
    shared3bb0.reset();
    shared3bb8.reset();
}
