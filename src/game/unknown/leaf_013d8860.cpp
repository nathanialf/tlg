/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a class whose slot 8 gives an entry's pair of values for
 * one side (FUN_013d0300, in the vtables at 0x16d37e8, 0x16d3c58 and
 * 0x16d69b0 by its address). The other slots are not traced. */
class Links013d8860 /* derived name */
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual int pair(int index, int in, int *first, int *second); /* derived name */
};

/* derived names: a walk along the links: the current index and side, the
 * index it stops at, and the flag set when it has stopped */
struct Walk013d8860 { /* derived name */
    u8 unknown0[0x8];
    int index; /* +0x8 */
    u32 unknownc;
    Links013d8860 *links; /* +0x10 */
    int end;              /* +0x18 */
    int done;             /* +0x1c */
    int in;               /* +0x20 */
};

/* derived name: one step of the walk: to the first value of the current
 * entry's pair, on the side the second value gives, or done when there is
 * none or it is the end */
void FUN_013d8860(Walk013d8860 *self) /* derived name */
{
    int side;
    int next;
    if (!self->links->pair(self->index, self->in, &next, &side) || self->end == next) {
        self->done = 1;
    } else {
        self->index = next;
        self->in = side == 0;
    }
}
