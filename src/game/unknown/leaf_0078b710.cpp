/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"

/* derived names: what the object at +0x1e8 of Object016ad480 holds: an int
 * at +0x120 and six values from +0x130, copied from the body by slot 11,
 * then handed to FUN_00206df0; the rest is not traced */
struct Record0078b710 { /* derived name */
    u8 unknown0[0x120];
    int unknown120; /* +0x120 */
    u8 unknown124[0xc];
    Float4A unknown130; /* +0x130 */
    Float4A unknown140; /* +0x140 */
    Float4A unknown150; /* +0x150 */
    Float4A unknown160; /* +0x160 */
    Float4A unknown170; /* +0x170 */
    Float4A unknown180; /* +0x180 */
};

void FUN_00206df0(Record0078b710 *record); /* derived name: not traced */

/* derived names: the class whose vtable is at 0x16ad480
 * (config/vtables.derived.base.txt, stored by FUN_00783b40 FUN_007847d0),
 * derived from Object00774560; only what slot 11 reads is traced */
class Object016ad480 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016ad480();
    virtual void slot11(); /* FUN_0078b710 */

  private:
    u8 unknownfc[0xec];
    Record0078b710 *unknown1e8; /* +0x1e8 */
};

/* derived names: slot 11 of the vtable at 0x16ad480: while slot 22 says so,
 * the body's int at +0x1330 and its values at +0x1390, +0x13a0 and +0x13c0 to
 * +0x13f0 are copied to the record at +0x1e8 (the body and the record read
 * again for each), which is then handed to FUN_00206df0 */
void Object016ad480::slot11()
{
    if (slot22()) {
        unknown1e8->unknown120 = unknown68->unknown1330;
        unknown1e8->unknown130 = unknown68->unknown1390;
        unknown1e8->unknown140 = unknown68->unknown13a0;
        unknown1e8->unknown150 = unknown68->unknown13c0;
        unknown1e8->unknown160 = unknown68->unknown13d0;
        unknown1e8->unknown170 = unknown68->unknown13e0;
        unknown1e8->unknown180 = unknown68->unknown13f0;
        FUN_00206df0(unknown1e8);
    }
}
