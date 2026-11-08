/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpMaterialLibrary::hknpMaterialLibrary(int initialCapacity)
{
    entries.grow(initialCapacity);

    /* The presets, each exclusive: the default material, then the three
     * trigger materials, the broad and narrow phase ones reporting at any
     * distance. */
    for (int i = 0; i < 4; i++) {
        hknpMaterial material;
        material.isExclusive = 1;
        switch (i) {
        case 1:
            material.name = "[Preset] Trigger (broad phase)";
            material.triggerType = hknpMaterial::TRIGGER_TYPE_BROAD_PHASE;
            material.triggerManifoldTolerance = HK_REAL_MAX;
            break;
        case 2:
            material.name = "[Preset] Trigger (narrow phase)";
            material.triggerType = hknpMaterial::TRIGGER_TYPE_NARROW_PHASE;
            material.triggerManifoldTolerance = HK_REAL_MAX;
            break;
        case 3:
            material.name = "[Preset] Trigger (contact solver)";
            material.triggerType = hknpMaterial::TRIGGER_TYPE_CONTACT_SOLVER;
            material.triggerManifoldTolerance = 0.0f;
            break;
        }
        FUN_000776a0(material);
    }
}
