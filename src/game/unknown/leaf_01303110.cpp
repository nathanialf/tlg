/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jscomputecontext.h"
#include "tlg_sce_kernel.h"

/* derived name: the engine's debug print (format and values) */
void FUN_00f1a460(const char *format, ...);

/* StallUntilSignaled (the report's name for the function, and its message's
 * "JsComputeContext::StallUntilSignaled"): the label yielded on until the GPU
 * writes 0x10 to it; past five seconds the timeout is printed with the label
 * and the check fails, and the wait goes on. */
void JsComputeContext::StallUntilSignaled(volatile u64 *handle)
{
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 538, handle != nullptr);
    u64 start = sceKernelGetProcessTime();
    while (*handle != 0x10) {
        scePthreadYield();
        if (sceKernelGetProcessTime() - start > 5000000) {
            FUN_00f1a460("Timeout occurred in JsComputeContext::StallUntilSignaled\n");
            FUN_00f1a460("label=%x, *label=%llu\n", handle, *handle);
            ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 551, FALSE);
        }
    }
}
