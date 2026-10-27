/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x4060, slot 1 of the vtable
 * 0x168c980) is the one emitted with it. */
Crc32StreamWriter::~Crc32StreamWriter() {}
