/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: the object at +0x1cb0 of FUN_00b8e610's object (called at
 * 0xb8fa29 and 0xb90b3f): two sets of four references to shared objects at
 * +0x0 and +0x20, and seven more at +0x1d0 to +0x380; the objects' classes
 * and the other fields are not traced */
class Object00bd5850 /* derived name */
{
  public:
    void releaseShared(); /* derived name */

  private:
    SharedRef00901550<Shared00901550> sharedA[4]; /* +0x0 */
    SharedRef00901550<Shared00901550> sharedB[4]; /* +0x20 */
    u8 unknown40[0x190];
    SharedRef00901550<Shared00901550> shared1d0; /* +0x1d0 */
    u8 unknown1d8[0x58];
    SharedRef00901550<Shared00901550> shared230; /* +0x230 */
    u8 unknown238[0x108];
    SharedRef00901550<Shared00901550> shared340; /* +0x340 */
    u8 unknown348[0x18];
    SharedRef00901550<Shared00901550> shared360; /* +0x360 */
    u8 unknown368[0x8];
    SharedRef00901550<Shared00901550> shared370; /* +0x370 */
    SharedRef00901550<Shared00901550> shared378; /* +0x378 */
    SharedRef00901550<Shared00901550> shared380; /* +0x380 */
};

/* FUN_00bd5850: the single references dropped up from +0x1d0, then the two
 * sets' references side by side (the loop unrolled: +0x0, +0x20, +0x8,
 * +0x28 and on) */
void Object00bd5850::releaseShared()
{
    shared1d0.reset();
    shared230.reset();
    shared340.reset();
    shared360.reset();
    shared370.reset();
    shared378.reset();
    shared380.reset();
    for (int i = 0; i < 4; ++i) {
        sharedA[i].reset();
        sharedB[i].reset();
    }
}
