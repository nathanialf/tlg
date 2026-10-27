/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: one byte written to the stream; a byte needs no swap. */
void hkOArchive::FUN_0000a420(char c)
{
    writer->write(&c, 1);
}
