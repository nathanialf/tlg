/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the constructor of the class whose vtable is at 0x16d7c58
 * (config/vtables.derived.base.txt): its base's constructor FUN_0148c070 (its
 * row named for it, D15) with 6, which stores the same vtable (the base's
 * and the class's identical, one copy kept by the linker); then
 * the vtable, the int at +0x64 zeroed and the 300 words at +0x70 in a loop
 * (LoopIdiom makes it a memset after TailCallElim has run, so the call is
 * not a tail call). The vtable's first two slots are not destructors.
 * The fields' meaning is not traced. */
class Object0148c070 /* derived name */
{
  public:
    Object0148c070(int kind);
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */

  private:
    u8 unknown8[0x5c];
};

class Object0148c2f0 : public Object0148c070 /* derived name */
{
  public:
    Object0148c2f0();

  private:
    int unknown64; /* +0x64 */
    u8 unknown68[8];
    u32 unknown70[300]; /* +0x70 */
};

Object0148c2f0::Object0148c2f0() : Object0148c070(6)
{
    unknown64 = 0;
    for (int i = 0; i < 300; ++i) {
        unknown70[i] = 0;
    }
}
