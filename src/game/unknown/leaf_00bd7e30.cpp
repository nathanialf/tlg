/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00bd7e30.h"
#include "tlg_game_shared.h"

/* derived names: the object at +0x300 of FUN_00dfb810's object (called at
 * 0xdfc377 and 0xdfc89d): references to shared objects at +0x1150 and
 * +0x1180 to +0x11a0, and four to counted objects at +0x1160 to +0x1178;
 * the objects' classes and the other fields are not traced */
class Object00bd7e30 /* derived name */
{
  public:
    void releaseShared(); /* derived name */

  private:
    u8 unknown0[0x1150];
    SharedRef00901550<Shared00901550> shared1150; /* +0x1150 */
    u8 unknown1158[0x8];
    Counted00bd7e30 *counted1160;                 /* +0x1160 */
    Counted00bd7e30 *counted1168;                 /* +0x1168 */
    Counted00bd7e30 *counted1170;                 /* +0x1170 */
    Counted00bd7e30 *counted1178;                 /* +0x1178 */
    SharedRef00901550<Shared00901550> shared1180; /* +0x1180 */
    SharedRef00901550<Shared00901550> shared1188; /* +0x1188 */
    SharedRef00901550<Shared00901550> shared1190; /* +0x1190 */
    SharedRef00901550<Shared00901550> shared1198; /* +0x1198 */
    SharedRef00901550<Shared00901550> shared11a0; /* +0x11a0 */
};

/* FUN_00bd7e30: the references dropped in the base's order, +0x1178 first,
 * then +0x1150, the other counted ones up from +0x1160, the shared ones up
 * from +0x1180 */
void Object00bd7e30::releaseShared()
{
    releaseAndClear(counted1178);
    shared1150.reset();
    releaseAndClear(counted1160);
    releaseAndClear(counted1168);
    releaseAndClear(counted1170);
    shared1180.reset();
    shared1188.reset();
    shared1190.reset();
    shared1198.reset();
    shared11a0.reset();
}
