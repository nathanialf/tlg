/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Object0000b330::FUN_0000b680(const char *what, int id, const char *description,
                                  const char *file, int line, hkBool stackTrace)
{
    char buffer[0x2000];
    if (id == 0 && file == HK_NULL) {
        FUN_00017e80(buffer, sizeof(buffer), "%s", description);
    } else if (id == 0 || id == -1) {
        FUN_00017e80(buffer, sizeof(buffer), "%s(%d): %s: %s", file, line, what, description);
    } else {
        FUN_00017e80(buffer, sizeof(buffer), "%s(%d): [0x%08X] %s: %s", file, line, id, what,
                     description);
    }
    buffer[sizeof(buffer) - 1] = 0;
    reportFunction(buffer, reportObject);
    if (stackTrace) {
        StackTracer tracer;
        hkUlong trace[128];
        const int numTrace = tracer.FUN_000042d0(trace, 128, 0);
        if (numTrace > 2) {
            reportFunction("Stack trace is:\n", reportObject);
            tracer.FUN_0000d890(trace + 2, numTrace - 2, reportFunction, reportObject);
        }
    }
}
