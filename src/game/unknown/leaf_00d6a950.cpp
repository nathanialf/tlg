/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: a virtual method (its address at 0x16b9dd0 and 0x16c8248 in
 * .data.rel.ro): signals the semaphore at +0x1a8 once for each of the
 * unsigned count at +0x128 (both read again on each pass), waking that many
 * waiters. Class and method unknown. */
struct Object00d6a950 { /* derived name */
    u8 unknown0[0x128];
    u32 unknown128; /* +0x128: the waiters */
    u8 unknown12c[0x1a8 - 0x12c];
    SceKernelSema semaphore; /* +0x1a8, derived name */
};

void FUN_00d6a950(Object00d6a950 *self) /* derived name */
{
    for (u32 i = 0; i < self->unknown128; i++)
        sceKernelSignalSema(self->semaphore, 1);
}
