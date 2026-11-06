/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkPlatformObjectWriter::hkPlatformObjectWriter(const Layout00180ef0 &layout, Object0019a7c0 *cache_,
                                               int flags)
{
    copier = new hkObjectCopier(Layout00180ef0(D_14cb8f6), layout, flags);
    const LayoutRules00180ef0 &rules = copier->layoutOut.rules;
    if (rules.bytesInPointer == D_14cb8f6.bytesInPointer &&
        rules.littleEndian == D_14cb8f6.littleEndian &&
        rules.reusePadding == D_14cb8f6.reusePadding &&
        rules.emptyBaseOptimization == D_14cb8f6.emptyBaseOptimization) {
        cache = HK_NULL;
    } else if (cache_) {
        cache_->addReference();
        cache = cache_;
    } else {
        cache = new Object0019a7c0();
    }
}
