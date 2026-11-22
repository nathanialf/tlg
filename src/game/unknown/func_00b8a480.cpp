/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_sce_kernel.h"

/* The render device's source file, as the reports name it (0x15cc515). */
#define JS_DEVICE_CPP /* derived name */                                                           \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsDevice.cpp"

/* derived names: the memory the device is created with (the asserts at
 * 0xb8a799 and 0xb8a848 name the two sizes; the four words are filled from
 * 0x5946da0, 0x5946db0, 0x5946d98 and 0x5946da8, then copied whole into the
 * JsDevice at +0x60) */
struct JsDeviceDesc00b8a480 /* derived name */
{
    u64 garlicMemoryBase; /* derived name; not traced */
    u64 m_garlicMemorySize;
    u64 onionMemoryBase; /* derived name; not traced */
    u64 m_onionMemorySize;
};

/* derived names: the renderer CreateDevice makes (0x18a20 bytes, built by
 * FUN_00b8c400) and returns; the fields are those this function writes */
class Renderer00b8a480 /* derived name */
{
  public:
    Renderer00b8a480(); /* FUN_00b8c400 */

    u8 unknown0[0x2d0];
    void *swapChain;  /* +0x2d0, derived name: the 0x2320-byte object of FUN_012ffc30 */
    void *backBuffer; /* +0x2d8, derived name: its entry at +0x40 by the index at +0x38 */
    u8 unknown2e0[0x40];
    u32 width;  /* +0x320, derived name: the low half of 0x5948904 */
    u32 height; /* +0x324, derived name: the high half */
    u8 unknown328[8];
    u32 unknown330; /* 0x1c */
    u8 unknown334[0x34];
    JsDeviceDesc00b8a480 desc; /* +0x368 */
    void (*callback)(void *);  /* +0x388, derived name: FUN_00b98790 */
    u8 unknown390[8];
    u32 priority; /* +0x398, derived name: 0x100 */
    u8 unknown39c[4];
    void *owner; /* +0x3a0, derived name: &D_5835fc0 */
    u8 unknown3a8[0x18a20 - 0x3a8];
};

extern u64 D_5946da0, D_5946db0, D_5946d98, D_5946da8;
extern u32 D_5948904;
extern void (*D_5adac90)(void *);
extern u8 D_5835fc0[], D_5835fd0[];
void FUN_00b98790(void *);          /* derived name */
void *FUN_00b98890(void *argument); /* derived name: the render thread's entry */
void FUN_00bbc0d0(Renderer00b8a480 *renderer);
void FUN_00bc1c90(Renderer00b8a480 *renderer);

/* CreateDevice (the name its own reports give, at 0xb8a7ae and 0xb8a85d):
 * makes the renderer, the render device and its queues, the swap chain, sets
 * the assertion handler and starts the render thread "ps4render".
 *
 * NONMATCHING: a partial reconstruction, kept so the module holds the one
 * store of the assertion handler (0xb8c34f; tools/module_boundary.py,
 * once-stored pointers). What is written follows the base's order; what is
 * not written is marked where it falls:
 *   - 0xb8a4bf..0xb8a6eb: the video-out handle 0x179f2a4 opened once
 *     (sceVideoOutOpen(0xff, 0, 0, 0)) and its resolution read; nine or three
 *     24-byte mode records appended to the table at 0x5948900 (count
 *     0x59488fc) from 0x16ba348.. or 0x16ba300.., by whether the height is
 *     above 1080 and the flag at +0x210 of 0x5938c40.
 *   - 0xb8a8ca..0xb8c1cd: the JsDevice (0x302e0 bytes, vtable 0x16c3978 over
 *     JsUnknown's 0x16c3c68, its serial from 0x179f2a8) and its Initialize
 *     inlined: JsDeviceChild::m_pDevice (0x5adaaa8) checked null and set, the
 *     owner registered ("JsDevice"), the Garlic and Onion heaps
 *     (FUN_0131da70), the device mutex ("JsDeviceMutex", util/mutex.h's
 *     Create), the compute queue (sceGnmMapComputeQueue, JsComputeQueue's
 *     "map"), the contexts (FUN_012ffc30, FUN_01305e90, FUN_01306470), the
 *     46 FUN_01303ee0 resources, the private data (DeallocatePrivateData,
 *     misc.h's SetPointer), and the swap chain (JsSwapChain.cpp's Initialize:
 *     sceVideoOutOpen, sceKernelIsNeoMode, sceVideoOutSetFlipRate, its back
 *     buffers).
 *   - 0xb8c1cd..0xb8c2f5: the swap chain's launch: the thread
 *     "ps4render_submitDone" (entry 0x149a2e0, argument 0x5adac98, stack
 *     0x8000, affinity 0xf), checked `result == 0` (JsSwapChain.cpp:95).
 *   - the import F+yfmduIBB8 (unnamed, config/imports.base.txt) called with
 *     the attributes and 0x5835fd0 before the affinity is set, at 0xb8c399
 *     and 0xb8c24b. */
Renderer00b8a480 *CreateDevice()
{
    Renderer00b8a480 *renderer = new Renderer00b8a480;

    /* not written: the video-out mode table (above) */

    renderer->width = D_5948904 & 0xffff;
    renderer->height = D_5948904 >> 16;
    renderer->unknown330 = 0x1c;
    renderer->desc.garlicMemoryBase = D_5946da0;
    renderer->desc.m_garlicMemorySize = D_5946db0;
    renderer->desc.onionMemoryBase = D_5946d98;
    renderer->desc.m_onionMemorySize = D_5946da8;
    renderer->callback = FUN_00b98790;
    renderer->priority = 0x100;
    renderer->owner = D_5835fc0;
    D_5adac90 = FUN_00b98790;

    JsDeviceDesc00b8a480 desc = renderer->desc;
    ANZU_ASSERT(JS_DEVICE_CPP, 111, desc.m_garlicMemorySize > 0);
    ANZU_ASSERT(JS_DEVICE_CPP, 112, desc.m_onionMemorySize > 0);

    /* not written: the JsDevice, its Initialize and the swap chain (above) */

    FUN_00bbc0d0(renderer);
    FUN_00bc1c90(renderer);

    D_5ace510 = FUN_00b8a440;

    pthread_attr_t attr;
    SceKernelSchedParam param;
    param.sched_priority = 0x100;
    scePthreadAttrInit(&attr);
    scePthreadAttrSetdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    scePthreadAttrSetinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    scePthreadAttrSetschedparam(&attr, &param);
    scePthreadAttrSetstacksize(&attr, 0x80000);
    /* not written: F+yfmduIBB8(&attr, D_5835fd0) (above) */
    scePthreadAttrSetaffinity(&attr, 1);
    pthread_t thread;
    scePthreadCreate(&thread, &attr, FUN_00b98890, D_5835fd0, "ps4render");
    scePthreadAttrDestroy(&attr);
    return renderer;
}
