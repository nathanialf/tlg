/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: the 0xb0-byte object at +0x2640 of FUN_00b8e610's object
 * (called at 0xb8fa35 and 0xb90a57; before the second call the caller
 * releases the reference at +0x60 itself, +0x26a0 of its object): six
 * references to shared objects at +0x70 to +0x98, the objects' class not
 * traced. The other fields are not traced. */
class Object00dfb6c0 /* derived name */
{
  public:
    void releaseShared(); /* derived name */

  private:
    u8 unknown0[0x70];
    SharedRef00901550<Shared00901550> shared70; /* +0x70 */
    SharedRef00901550<Shared00901550> shared78; /* +0x78 */
    SharedRef00901550<Shared00901550> shared80; /* +0x80 */
    SharedRef00901550<Shared00901550> shared88; /* +0x88 */
    SharedRef00901550<Shared00901550> shared90; /* +0x90 */
    SharedRef00901550<Shared00901550> shared98; /* +0x98 */
    u8 unknowna0[0x10];
};

/* FUN_00dfb6c0: the six references dropped, +0x90 and +0x98 first, then from
 * +0x88 down (the base's order) */
void Object00dfb6c0::releaseShared()
{
    shared90.reset();
    shared98.reset();
    shared88.reset();
    shared80.reset();
    shared78.reset();
    shared70.reset();
}
