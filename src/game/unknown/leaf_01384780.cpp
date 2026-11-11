/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: the function FUN_009f43e0 registers with __cxa_atexit for a
 * static object (lea at 0x9f45ef), so the object's destructor: deletes the
 * handle it holds, when set, through sceKernelDeleteEventFlag and then clears it. The
 * class is not traced. */
struct Holder01384780 {        /* derived name */
    SceKernelEventFlag handle; /* derived name */
};

void FUN_01384780(Holder01384780 *self) /* derived name */
{
    if (self->handle) {
        sceKernelDeleteEventFlag(self->handle);
        self->handle = 0;
    }
}
