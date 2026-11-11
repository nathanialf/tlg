/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 50 of the vtable of Object00534610 (its pointer at
 * 0x16ab728), written as a free function: when the thread-local int at
 * 0x16dc060 (tp offset -112) is set and bit 5 of the byte at +0x30 of its
 * second argument is clear, calls slot 7 of that object. The first argument
 * is not read; the object's class is not traced. */
class Object0057d2f0 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void unknown4();
    virtual void unknown5();
    virtual void unknown6();
    virtual void unknown7();

    u8 unknown8[0x28];
    u8 unknown30; /* +0x30 */
};

struct Object00534610; /* derived name */

extern __thread int D_16dc060;

void FUN_0057d2f0(Object00534610 *, Object0057d2f0 *object) /* derived name */
{
    if (D_16dc060 != 0 && !(object->unknown30 & 0x20))
        object->unknown7();
}
