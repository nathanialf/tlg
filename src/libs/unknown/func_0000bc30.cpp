/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: allocate size + 16 bytes through the arena's third virtual
 * method, write a 16-byte header (owner, size) and return the payload.
 * Unknown owner. */
void *FUN_0000bc30(Arena *arena, int size) /* derived name */
{
    ArenaBlockHeader *header = (ArenaBlockHeader *)arena->vtable->allocate(arena, size + 0x10);
    header->owner = arena;
    header->size = size;
    return header + 1;
}
