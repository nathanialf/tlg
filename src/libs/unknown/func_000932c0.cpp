/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal but for its vtable, 0x16a3550, which no row names yet
// (docs/NOTES.md, Round 32).
FiosStreamReader::~FiosStreamReader()
{
    if (handle >= 0) {
        sceFiosFHCloseSync(0, handle);
        handle = -1;
        ok = false;
    }
}
