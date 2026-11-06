/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpExternMeshShapeData's type info
 * (registered at 0x355ab): the object constructed in place from a loaded
 * image, its inline finish constructor running the simd tree's. */
static void finishLoadedObjecthknpExternMeshShapeData(void *object,
                                                      int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpExternMeshShapeData(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpExternMeshShapeData(void *object) /* derived name */
{
    static_cast<hknpExternMeshShapeData *>(object)->~hknpExternMeshShapeData();
}

extern const hkClassMember D_1692c80[]; /* derived name: hknpExternMeshShapeData's records */

/* The address of hknpExternMeshShapeData's vtable, read from an object
 * finished in a 16-byte aligned buffer: the finish constructor is inline,
 * but the simd tree's in it is out of line (0x21a20), so the object is
 * built on the stack, as in func_000224f0.cpp. */
static const void *vtableOfhknpExternMeshShapeData() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpExternMeshShapeData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpExternMeshShapeData(flag);
    return object.vtable;
}

/* This file's static initializer (0x35500): hknpExternMeshShapeData's
 * reflection over hkReferencedObject's, its three members, then its type
 * info. */
const hkClass D_57be420("hknpExternMeshShapeData", &D_57b8640, sizeof(hknpExternMeshShapeData), 0,
                        0, 0, 0, D_1692c80, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57be470;
const hkTypeInfo D_57be470("hknpExternMeshShapeData", "!hknpExternMeshShapeData",
                           finishLoadedObjecthknpExternMeshShapeData,
                           cleanupLoadedObjecthknpExternMeshShapeData,
                           vtableOfhknpExternMeshShapeData(), sizeof(hknpExternMeshShapeData));
