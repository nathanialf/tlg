/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: equal but the vtable: hkOstream's 0x168d100 has no row (the
// name is a fact; a ruling for the supervisor).
hkOstream::hkOstream(hkStreamWriter *writer)
{
    if (writer) {
        writer->addReference();
    }
    this->writer = writer;
}
