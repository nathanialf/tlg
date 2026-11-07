/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the layer's cleanup folded by the linker into the empty body
 * 0x3b640; the default configuration's finish kept beside the initializer
 * (0x3d1d0, a jump to the out-of-line finish constructor) and its cleanup
 * folded into 0x2d0. */
static void cleanupLoadedObjecthknpBroadPhaseConfigLayer(void *object)
{
    static_cast<hknpBroadPhaseConfig::Layer *>(object)->~Layer();
}

static void finishLoadedObjecthknpDefaultBroadPhaseConfig(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDefaultBroadPhaseConfig(flag);
}

static void cleanupLoadedObjecthknpDefaultBroadPhaseConfig(void *object)
{
    static_cast<hknpDefaultBroadPhaseConfig *>(object)->~hknpDefaultBroadPhaseConfig();
}

/* The address of hknpDefaultBroadPhaseConfig's vtable, read from an object
 * finished in a buffer (its finish constructor out of line, so called).
 * derived name. */
static const void *vtableOfhknpDefaultBroadPhaseConfig()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpDefaultBroadPhaseConfig)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpDefaultBroadPhaseConfig(flag);
    return object.vtable;
}

extern const hkClass D_57b8640; /* derived name: hkReferencedObject's hkClass */
extern const hkClass D_57c01c8;

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_1696450[2] = {
#include "gen/D_1696450.inc"
};
static const hkClassMember D_16964a0[1] = {
#include "gen/D_16964a0.inc"
};

/* This file's static initializer (0x3d1f0): the layer's reflection (two
 * members) and type info (no finish callback, no vtable), the abstract
 * configuration's reflection over hkReferencedObject's, then the default
 * configuration's (its layers) and type info. */
const hkClass D_57c01c8("hknpBroadPhaseConfigLayer", 0, sizeof(hknpBroadPhaseConfig::Layer), 0, 0,
                        0, 0, D_1696450, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0218;
const hkTypeInfo D_57c0218("hknpBroadPhaseConfigLayer", "!hknpBroadPhaseConfig::Layer", 0,
                           cleanupLoadedObjecthknpBroadPhaseConfigLayer, 0,
                           sizeof(hknpBroadPhaseConfig::Layer));
extern const hkClass D_57c0248;
const hkClass D_57c0248("hknpBroadPhaseConfig", &D_57b8640, sizeof(hknpBroadPhaseConfig), 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0);
extern const hkClass D_57c0298;
const hkClass D_57c0298("hknpDefaultBroadPhaseConfig", &D_57c0248,
                        sizeof(hknpDefaultBroadPhaseConfig), 0, 0, 0, 0, D_16964a0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c02e8;
const hkTypeInfo D_57c02e8("hknpDefaultBroadPhaseConfig", "!hknpDefaultBroadPhaseConfig",
                           finishLoadedObjecthknpDefaultBroadPhaseConfig,
                           cleanupLoadedObjecthknpDefaultBroadPhaseConfig,
                           vtableOfhknpDefaultBroadPhaseConfig(),
                           sizeof(hknpDefaultBroadPhaseConfig));
