/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an adaptor of the world's +0x420 table: the arguments
 * passed on to FUN_0012e7f0 without the seventh. */
void FUN_00052380(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9, void *argument10)
{
    FUN_0012e7f0(argument1, argument2, argument3, argument4, argument5, argument6, argument8,
                 argument9, argument10);
}
