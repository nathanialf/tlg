/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: prints a stack trace, of which this platform has none (the
 * error report at 0xb79e passes the frames past its own two). */
void StackTracer::FUN_0000d890(const hkUlong *trace, int numTrace, PrintFunction print,
                               void *context) const /* derived name */
{
    print("No stack trace available", context);
}
