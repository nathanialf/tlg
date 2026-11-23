/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_object05adaaa8.h"

/* The render device's source file, as the report names it (0x15cc515). */
#define JS_DEVICE_CPP /* derived name */                                                           \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsDevice.cpp"

void *FUN_0131e0c0(Target0131e2d0 *heap, u64 size, u64 alignment); /* derived name */
void FUN_012fdf60(Target0131e2d0 *heap, int value);                /* derived name */

/* AllocateOnionMemory (the report's name for the function): a block of the
 * onion heap at +0x100e8, the allocations counted atomically at +0x100a8;
 * when the heap has none, both heaps are dumped (FUN_012fdf60 with 1, the
 * garlic one at +0x100b8 first, each after its banner) and the check
 * fails. */
void *JsDevice::AllocateOnionMemory(u32 size, u32 alignment, u32 label)
{
    void *p = FUN_0131e0c0(unknown100e8, size, alignment);
    __sync_fetch_and_add(&onionAllocations, 1);
    if (p == nullptr) {
        puts("########## garlic ##########");
        FUN_012fdf60(unknown100b8, 1);
        puts("########## onion ##########");
        FUN_012fdf60(unknown100e8, 1);
    }
    ANZU_ASSERT(JS_DEVICE_CPP, 697, p != nullptr);
    return p;
}
