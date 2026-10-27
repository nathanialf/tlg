/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x1ba30, slot 1 of the vtable
 * 0x16a6af0 and of ten other 0x18-byte classes') is the one emitted with
 * it. */
OffsetOnlyStreamWriter::~OffsetOnlyStreamWriter() {}
