/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: hkMonitorStreamStringMap::StringMap's finish constructor,
 * called by its finish callback FUN_00000320; the type infos of
 * hkxEnum::Item (0x57c7010) and hkxNode::AnnotationData (0x57c7780), the
 * same layout, hold it as their finish callback directly. The only member
 * to finish is the string at +8. */
void FUN_0000d520(hkMonitorStreamStringMapStringMap *self,
                  hkFinishLoadedObjectFlag flag) /* derived name */
{
    FUN_0000e5c0(&self->string, flag);
}
