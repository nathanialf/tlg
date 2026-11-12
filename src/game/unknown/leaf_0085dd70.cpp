/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets one of eight inputs of an object by index (0 to 7, the
 * jump table 0x1558884), each a flag with a pointer: 0 and 1 the pair at
 * +0x68 (pointers at +0x90), both cleared while the int at +0x64 is set, the
 * pair's or at +0x70; 2 the or at +0x70 itself (0 while +0x64 is set); 3 the
 * pointer at +0x88 (null unless the flag is set and +0x64 is not); 4 to 7 the
 * four flags at +0xb8 (pointers at +0xe0), their or at +0xc8. What the
 * inputs and the object are is not traced. */
struct Object0085dd70 { /* derived name */
    u8 unknown0[0x64];
    int disabled; /* +0x64 */
    int pair[2];  /* +0x68 */
    int pairAny;  /* +0x70 */
    u8 unknown74[0x14];
    void *single;         /* +0x88 */
    void *pairTargets[2]; /* +0x90 */
    u8 unknowna0[0x18];
    int values[4]; /* +0xb8 */
    int any;       /* +0xc8 */
    u8 unknowncc[0x14];
    void *targets[4]; /* +0xe0 */

    void setPair(int index, int flag, void *target) /* derived name */
    {
        if (disabled) {
            flag = 0;
            target = nullptr;
        }
        pair[index] = flag;
        pairTargets[index] = target;
        pairAny = pair[0] | pair[1];
    }

    void setValue(int index, int flag, void *target) /* derived name */
    {
        values[index] = flag;
        targets[index] = target;
        any = values[0] | values[1] | values[2] | values[3];
    }
};

// NONMATCHING: two stores in two arms where the build sinks one (inputs 2 and 3: the base
// stores the flag or 0, the pointer or null, in each arm and returns from each)
void FUN_0085dd70(Object0085dd70 *self, int input, int flag, void *target) /* derived name */
{
    switch (input) {
    case 0:
        self->setPair(0, flag, target);
        break;
    case 1:
        self->setPair(1, flag, target);
        break;
    case 2:
        if (self->disabled)
            self->pairAny = 0;
        else
            self->pairAny = flag;
        break;
    case 3:
        if (flag && !self->disabled)
            self->single = target;
        else
            self->single = nullptr;
        break;
    case 4:
        self->setValue(0, flag, target);
        break;
    case 5:
        self->setValue(1, flag, target);
        break;
    case 6:
        self->setValue(2, flag, target);
        break;
    case 7:
        self->setValue(3, flag, target);
        break;
    }
}
