/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0xd990, slot 1 of the vtable
 * 0x168d860) is the one emitted with it, the body every vtable of a 32-byte
 * reference-counted class with an empty destructor cites (D15). */
hkUuidObject::~hkUuidObject() {}
