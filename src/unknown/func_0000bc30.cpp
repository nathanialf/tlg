/* src/unknown/: functions matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: allocate size + 16 bytes through the arena's third virtual
 * method, write a 16-byte header (owner, size) and return the payload.
 * Unknown owner. */
struct ArenaVtable {
    void *slot0;
    void *slot1;
    void *(*allocate)(void *self, int size);
};

struct Arena {
    ArenaVtable *vtable;
};

struct ArenaBlockHeader {
    Arena *owner;
    s32 size;
    s32 unknown;
};

void *FUN_0000bc30(Arena *arena, int size) /* derived name */
{
    ArenaBlockHeader *header = (ArenaBlockHeader *)arena->vtable->allocate(arena, size + 0x10);
    header->owner = arena;
    header->size = size;
    return header + 1;
}
