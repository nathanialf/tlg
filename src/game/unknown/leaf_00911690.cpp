/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: for a size that is not 0, returns what slot 4 of the object
 * the pointer at 0x58200b0 holds gives for the size, the alignment 16 and 1, a
 * tail call; else null. FUN_001db8b0 stores it beside the free function
 * FUN_00911660 at 0x17ac6a0 (lea at 0x1dda3d). The object's class and the
 * slot's other parameters are not traced. */
class Object058200b0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void *slot4(unsigned size, unsigned alignment,
                        int value); /* derived name; not traced */
};

extern Object058200b0 *D_58200b0;

void *FUN_00911690(unsigned size) /* derived name */
{
    if (size == 0)
        return 0;
    return D_58200b0->slot4(size, 16, 1);
}
