/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"
#include "tlg_game_object016c3be0.h"
#include "tlg_sce_kernel.h"

/* ~JsDeviceContext: the five entries handed back, the direct memory
 * released and cleared, the two references dropped and cleared, then the
 * base's destructor, a tail call. The destructor is the class's key
 * function, so this file emits the vtable and the deleting destructor
 * 0x130e020. */
JsDeviceContext::~JsDeviceContext()
{
    returnEntryE8(entry13090);
    returnEntry(entry13098);
    returnEntry(entry130a0);
    returnEntryE8(entry130a8);
    returnEntryE8(entry130b0);
    if (D_5adaae0)
        sceKernelReleaseDirectMemory(D_5adaae0, 0x20000);
    D_5adaae0 = 0;
    if (unknown4698)
        unknown4698->Release();
    unknown4698 = nullptr;
    if (unknown4690)
        unknown4690->Release();
    unknown4690 = nullptr;
}
