/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

Object0000b330::Object0000b330(ReportFunction0000b330 reportFunction, void *reportObject)
    : reportFunction(reportFunction), reportObject(reportObject), minimumLevel(MESSAGE_REPORT),
      criticalSection(0)
{
}

// NONMATCHING: equal at quick_diff (117 instructions); the layout cannot place the compiler's lookup table of the kinds' names (a private .data.rel.ro.local object of four relocated pointers, all zero before relocation, which the layout looks for in the base by its bytes; the base's copy is at 0x168d630), docs/NOTES.md Round 72A
int Object0000b330::message(Message kind, int id, const char *description, const char *file,
                            int line)
{
    criticalSection.enter();
    if (id == -1 && array.getSize()) {
        id = array[array.getSize() - 1];
    }
    int stop = 0;
    if (FUN_0000b670() <= kind && FUN_0000b4a0(id)) {
        const char *what;
        hkBool stackTrace;
        switch (kind) {
        case MESSAGE_REPORT:
            what = "Report";
            stackTrace = false;
            break;
        case MESSAGE_WARNING:
            what = "Warning";
            stackTrace = false;
            break;
        case MESSAGE_ASSERT:
            what = "Assert";
            stackTrace = true;
            break;
        case MESSAGE_ERROR:
            what = "Error";
            stackTrace = true;
            break;
        default:
            what = "";
            stackTrace = false;
            break;
        }
        FUN_0000b680(what, id, description, file, line, stackTrace);
        stop = (kind == MESSAGE_ASSERT || kind == MESSAGE_ERROR);
    }
    criticalSection.leave();
    return stop;
}
