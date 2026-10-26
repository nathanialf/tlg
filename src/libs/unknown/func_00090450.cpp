/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The classes are declared in tlg_hk_reflect.h. */
hkBlockStreamCommandWriter::~hkBlockStreamCommandWriter()
{
    /* The writer was finalized (or never bound) before its owner releases
     * the command writer. */
    HK_ASSERT(0, writer.blockStream == 0 || writer.currentBlock == 0); /* derived assert */
}
