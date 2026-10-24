/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the size recorded in the header of a block FUN_0000bc30
 * allocated, widened to 64 bits. The one direct caller (0x19bb80) passes the
 * arena at +0x58 of the thread's block and a payload. */
u64 FUN_0000bc60(Arena *arena, const void *payload) /* derived name */
{
    return (static_cast<const ArenaBlockHeader *>(payload) - 1)->size;
}
