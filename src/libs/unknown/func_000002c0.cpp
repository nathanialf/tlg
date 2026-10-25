/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkMonitorStreamColorTable's type
 * info (0x57af3d0): construct the table in place from a loaded image through
 * its inline finish constructor, which has nothing to fix up but the
 * vtable. */
// NONMATCHING: equal in quick_diff (4 instructions, 15 bytes); the gate cannot place the
// vtable relocation _ZTV25hkMonitorStreamColorTable (base 0x168c1b0), docs/NOTES.md round 15
void FUN_000002c0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMonitorStreamColorTable(flag);
}
