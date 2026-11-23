/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: the object at +0x2790 of FUN_00b8e610's object (called at
 * 0xb8fa4d and 0xb9095b): eighteen references to shared objects at +0x70 to
 * +0xf8; the objects' classes and the other fields are not traced */
class Object00bdb5e0 /* derived name */
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
    SharedRef00901550<Shared00901550> shareda0; /* +0xa0 */
    SharedRef00901550<Shared00901550> shareda8; /* +0xa8 */
    SharedRef00901550<Shared00901550> sharedb0; /* +0xb0 */
    SharedRef00901550<Shared00901550> sharedb8; /* +0xb8 */
    SharedRef00901550<Shared00901550> sharedc0; /* +0xc0 */
    SharedRef00901550<Shared00901550> sharedc8; /* +0xc8 */
    SharedRef00901550<Shared00901550> sharedd0; /* +0xd0 */
    SharedRef00901550<Shared00901550> sharedd8; /* +0xd8 */
    SharedRef00901550<Shared00901550> sharede0; /* +0xe0 */
    SharedRef00901550<Shared00901550> sharede8; /* +0xe8 */
    SharedRef00901550<Shared00901550> sharedf0; /* +0xf0 */
    SharedRef00901550<Shared00901550> sharedf8; /* +0xf8 */
};

/* FUN_00bdb5e0: the references dropped in the base's order: +0x88 to +0x98,
 * then +0x80 down to +0x70, then each four from +0xa0, +0xc0 and +0xe0 last
 * first */
void Object00bdb5e0::releaseShared()
{
    shared88.reset();
    shared90.reset();
    shared98.reset();
    shared80.reset();
    shared78.reset();
    shared70.reset();
    sharedb8.reset();
    sharedb0.reset();
    shareda8.reset();
    shareda0.reset();
    sharedd8.reset();
    sharedd0.reset();
    sharedc8.reset();
    sharedc0.reset();
    sharedf8.reset();
    sharedf0.reset();
    sharede8.reset();
    sharede0.reset();
}
