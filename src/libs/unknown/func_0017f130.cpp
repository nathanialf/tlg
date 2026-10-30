/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkMemoryResourceHandle's destructor, out of line (0x17f180, slot 0 of
 * 0x16a6270): the external links destroyed from the last and their storage
 * given back, the name, then the variant's reference. Its deleting
 * destructor (0x17f130, slot 1) calls it and frees the object at its
 * recorded size. */
hkMemoryResourceHandle::~hkMemoryResourceHandle() {}
