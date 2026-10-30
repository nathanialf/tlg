/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxScene's type info (the
 * reflection initializer passes it at 0x8b802): construct the object in place
 * from a loaded image. */
void FUN_0008b6f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxScene(flag);
}

/* hkxScene's loaded-object cleanup: the virtual destructor (the linker
 * folded it with the other classes' identical body, 0x2d0, FUN_000002d0). */
void FUN_000002d0(void *object)
{
    static_cast<hkxScene *>(object)->~hkxScene();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166, 261). derived name. */
static const void *vtableOfhkxScene() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxScene)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxScene(flag);
    return object.vtable;
}

/* hkxScene's defaults, file-local (D17); the rows are written at build time
 * from the user's executable (D18, config/data_schema.base.txt). */
static const hkxSceneDefaults D_14c3474[1] = {
#include "gen/D_14c3474.inc"
};

/* This file's static initializer (0x8b740): hkxScene's reflection,
 * hkReferencedObject's as the parent, its fifteen members and their
 * defaults, version 2, then its type info (its finish callback, the
 * destructor, the vtable). */
const hkClass D_57c7830("hkxScene", &D_57b8640, sizeof(hkxScene), 0, 0, 0, 0, D_16a2180, 15,
                        D_14c3474, 0, 0, 2);
extern const hkTypeInfo D_57c7880;
const hkTypeInfo D_57c7880("hkxScene", "!hkxScene", FUN_0008b6f0, FUN_000002d0, vtableOfhkxScene(),
                           sizeof(hkxScene));
