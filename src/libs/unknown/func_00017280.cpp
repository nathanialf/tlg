/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 6 of Class168e810's vtable (address point 0x168e810)
 * gives a work item its runner, the object's default one when none is
 * given, and its 16-bit value. It overrides slot 3 of the second base, so
 * its this-adjusting thunk (0x172a0, the body inlined) is emitted with it. */
void Class168e810::FUN_00017280(WorkItem00017280 *item, Runner00016350 *runner,
                                u16 value) /* derived name */
{
    item->runner = runner ? runner : &defaultRunner;
    item->value4 = value;
}
