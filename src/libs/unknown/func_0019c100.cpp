/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The destructor, out of line (0x19c150; the deleting destructor 0x19c100
 * emitted before it): the section tags the writer copied (slot 10,
 * 0x19d0d0) given back to the thread's heap, then the members destroyed. */
hkPackfileWriter::~hkPackfileWriter()
{
    for (int i = 0; i < sectionTags.getSize(); i++) {
        freeHeapString(sectionTags[i]);
    }
}
