/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static): the finish is kept
 * at 0x6c440 beside the initializer, the cleanup folded by the linker. */
static void finishLoadedObjecthknpExternMeshShape(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpExternMeshShape(flag);
}

static void cleanupLoadedObjecthknpExternMeshShape(void *object)
{
    static_cast<hknpExternMeshShape *>(object)->~hknpExternMeshShape();
}

extern const hkClassMember D_169abc0[]; /* derived name: hknpExternMeshShape's records */
extern const hkClassEnum D_169ac30[];   /* derived name: its one enum */

/* The address of hknpExternMeshShape's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhknpExternMeshShape() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpExternMeshShape)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpExternMeshShape(flag);
    return object.vtable;
}

/* With the callbacks external (D15's spelling) the function was 3 of 67:
 * their GOT loads lived in callee-saved registers across the hkClass
 * calls; the base forms each address with a lea right before its use, the
 * file's own static functions in their own sections (docs/DECISIONS.md
 * D39). */
/* This file's static initializer (0x6c470): hknpExternMeshShape's
 * reflection over hknpCompositeShape's (its one enum and two members,
 * version 1) and type info, then hknpExternMeshShape::Geometry's
 * reflection over hkReferencedObject's (no members; abstract, no type
 * info). */
const hkClass D_57c2898("hknpExternMeshShape", &D_57c2cf8, sizeof(hknpExternMeshShape), 0, 0,
                        D_169ac30, 1, D_169abc0, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57c28e8;
const hkTypeInfo D_57c28e8("hknpExternMeshShape", "!hknpExternMeshShape",
                           finishLoadedObjecthknpExternMeshShape,
                           cleanupLoadedObjecthknpExternMeshShape, vtableOfhknpExternMeshShape(),
                           sizeof(hknpExternMeshShape));
const hkClass D_57c2848("hknpExternMeshShapeGeometry", &D_57b8640,
                        sizeof(hknpExternMeshShape::Geometry), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
