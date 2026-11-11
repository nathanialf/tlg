/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback stored at 0x5ace510 (lea at
 * 0xb8c33a): when the game's thread-local pointer at 0x16dc080 (tp offset
 * -80) holds an object, calls its slot 2 with the callback's two arguments,
 * as a tail call. The arguments' types, the object's class and the return
 * type are not traced. */
class Handler016dc080 /* derived name */
{
  public:
    virtual void slot0();                 /* derived name; not traced */
    virtual void slot1();                 /* derived name; not traced */
    virtual void slot2(void *a, void *b); /* derived name; not traced */
};

extern __thread Handler016dc080 *D_16dc080;

void FUN_00b8a440(void *a, void *b) /* derived name */
{
    if (D_16dc080)
        D_16dc080->slot2(a, b);
}
