/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Out of line (0x19be50; the binary writer's constructor 0x181b10 calls it):
 * the members empty, no contents yet, the options copied; the reflection's
 * own classes known up front, their index -1. */
hkPackfileWriter::hkPackfileWriter(const Options &options)
    : contentsIndex(-1), contentsClassIndex(-1), pointerB8(HK_NULL), int108(-1), options(options)
{
    map20.insert(reinterpret_cast<hkUlong>(&D_57b93e0), hkUlong(-1));
    map20.insert(reinterpret_cast<hkUlong>(&D_57b7d18), hkUlong(-1));
    map20.insert(reinterpret_cast<hkUlong>(&D_57b77f0), hkUlong(-1));
}

/* The destructor, out of line (0x19c150; the deleting destructor 0x19c100
 * emitted before it): the section tags the writer copied (slot 10,
 * 0x19d0d0) given back to the thread's heap, then the members destroyed. */
hkPackfileWriter::~hkPackfileWriter()
{
    for (int i = 0; i < sectionTags.getSize(); i++) {
        freeHeapString(sectionTags[i]);
    }
}
