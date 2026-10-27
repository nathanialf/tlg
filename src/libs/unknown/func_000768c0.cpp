/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

Elements000768c0::Elements000768c0(void *simulationContext, void *threadContext, void *allocator260,
                                   void *allocator250)
    : Elements000760c0(simulationContext, allocator260, allocator250, 1, 1, 1),
      simulationContext(simulationContext)
{
}
