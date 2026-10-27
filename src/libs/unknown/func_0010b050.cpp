/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x10b050, slot 1 of the
 * vtables 0x16a3d90 and 0x16a3dc0) frees the processor's 0xf0 bytes. */
QueryProcessor0010b090::~QueryProcessor0010b090() {}
