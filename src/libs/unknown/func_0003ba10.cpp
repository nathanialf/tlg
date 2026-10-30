/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpDefaultExternMeshShapeGeometry's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_0003ba10(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDefaultExternMeshShapeGeometry(flag);
}

/* hknpDefaultExternMeshShapeGeometry's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember
    D_1695a40[];                /* derived name: hknpDefaultExternMeshShapeGeometry's records */
extern const hkClass D_57c2848; /* its parent's hkClass */

/* The address of hknpDefaultExternMeshShapeGeometry's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpDefaultExternMeshShapeGeometry() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpDefaultExternMeshShapeGeometry)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpDefaultExternMeshShapeGeometry(flag);
    return object.vtable;
}

/* This file's static initializer (0x3ba30): hknpDefaultExternMeshShapeGeometry's reflection over its parent's, its one member, then its type info. */
const hkClass D_57bfc90("hknpDefaultExternMeshShapeGeometry", &D_57c2848,
                        sizeof(hknpDefaultExternMeshShapeGeometry), 0, 0, 0, 0, D_1695a40, 1, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57bfce0;
const hkTypeInfo D_57bfce0("hknpDefaultExternMeshShapeGeometry",
                           "!hknpDefaultExternMeshShapeGeometry", FUN_0003ba10, FUN_000002d0,
                           vtableOfhknpDefaultExternMeshShapeGeometry(),
                           sizeof(hknpDefaultExternMeshShapeGeometry));
