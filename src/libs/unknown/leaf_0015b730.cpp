/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a task of the collision step (vtable address point
 * 0x16a4ce0, a second base at +0x10 with address point 0x16a4d28; its
 * constructor FUN_0015b6c0 stores its arguments at +0x18, +0x20, +0x28,
 * +0x440 and +0x470, an inline array of 256 four-byte entries at +0x30 and
 * clears the pointer at +0x448). Slot 5, FUN_0015b7a0, runs under the timer
 * "Collide/Prepare New Pairs" and sets the flag at +0x132 of the object at
 * +0x448. This function stores that object; its one caller (0x150b2e)
 * passes a counted object it also keeps, and a third argument, 0, which the
 * body does not read. */
struct NewPairsOutput; /* derived name */

class PrepareNewPairsTask /* derived name */
{
  public:
    virtual ~PrepareNewPairsTask();

    void FUN_0015b730(NewPairsOutput *newOutput, int); /* derived name */

    u8 unknown8[0x440];
    NewPairsOutput *output; /* derived name */
};

void PrepareNewPairsTask::FUN_0015b730(NewPairsOutput *newOutput, int) /* derived name */
{
    output = newOutput;
}
