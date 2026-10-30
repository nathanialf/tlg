/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterProxy::FUN_001781b0(const Vec4 &direction,
                                      hknpCharacterSurfaceInfo &surface) /* derived name */
{
    D_16dc078->timerBegin("TtcheckSupport");
    hkArray<int> supports;
    supports.reserve(hkContainerHeapAllocator::get(), 20);
    surface.supportedState = FUN_00177660(direction, supports);
    if (surface.supportedState) {
        FUN_00177e00(supports, surface, direction);
    }
    D_16dc078->timerEnd("Et");
}
