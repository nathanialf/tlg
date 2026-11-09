/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: frees the block 16 bytes before the pointer its second
 * argument holds (the allocation's header), null skipped, through the C
 * library's free (0x14b0238, as hkMallocAllocator's blockFree); the object is
 * unused; slot 6 of the vtable at 0x16b8c00 (its pointer at 0x16b8c40), the
 * vtable stored by FUN_001bd010 FUN_002212a0 FUN_00c32940 FUN_00c4fdb0
 * FUN_00cd7ee0 FUN_00eb3c90. Class and method unknown. */
#include "stdlib.h"

struct Object00ca26a0; /* derived name */

void FUN_00ca26a0(Object00ca26a0 *, void *pointer) /* derived name */
{
    if (pointer) {
        free(static_cast<u8 *>(pointer) - 16);
    }
}
