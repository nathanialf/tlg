/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: a class over the root class whose slot 9 maps the value at
 * +0x40 to its next one and whose slot 5 follows it; the other slots and
 * fields are not traced */
class Object0137ea70 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5(); /* derived name */
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9(int value); /* derived name */

    u8 unknown24[0x1c];
    int unknown40; /* +0x40 */
};

extern Type00503fb0 *D_58218a8; /* derived name: the class's type */

/* derived name: for an object of the type D_58218a8 points to (or one derived
 * from it), its value at +0x40 replaced by slot 9's result, then slot 5 */
void FUN_0137ea70(void *, Object016b9108 *object) /* derived name */
{
    if (object && object->isKindOf(D_58218a8)) {
        Object0137ea70 *self = static_cast<Object0137ea70 *>(object);
        self->unknown40 = self->slot9(self->unknown40);
        self->slot5();
    }
}
