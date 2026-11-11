/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: the function FUN_009f43e0 registers with __cxa_atexit for a
 * static object (lea at 0x9f464b), so the object's destructor: deletes the
 * handle it holds, when set, through sceKernelDeleteSema and then clears it. The
 * class is not traced. */
struct Holder013847b0 {   /* derived name */
    SceKernelSema handle; /* derived name */
};

void FUN_013847b0(Holder013847b0 *self) /* derived name */
{
    if (self->handle) {
        sceKernelDeleteSema(self->handle);
        self->handle = 0;
    }
}
