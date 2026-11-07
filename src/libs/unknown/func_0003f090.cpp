/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

typedef hkFreeListArray<hknpMaterial, hknpMaterialId, 8, hknpMaterialFreeListArrayOperations>
    MaterialFreeListArray; /* derived name */
typedef hkFreeListArray<hknpMotionProperties, hknpMotionPropertiesId, 8,
                        hknpMotionPropertiesFreeListArrayOperations>
    MotionPropertiesFreeListArray; /* derived name */
typedef hkFreeListArray<hknpShapeInstance, hknpShapeInstanceId, 8, hknpShapeInstance>
    ShapeInstanceFreeListArray; /* derived name */

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the finishes folded by the linker into the empty body 0x3b640; the
 * materials' cleanup kept at 0x3eef0 (each material in use losing its
 * name), the motion properties' folded into 0x1f650, the instances' kept
 * at 0x3efb0. */
static void finishLoadedObjectMaterialFreeListArray(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) MaterialFreeListArray(flag);
}

static void cleanupLoadedObjectMaterialFreeListArray(void *object)
{
    static_cast<MaterialFreeListArray *>(object)->~MaterialFreeListArray();
}

static void finishLoadedObjectMotionPropertiesFreeListArray(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) MotionPropertiesFreeListArray(flag);
}

static void cleanupLoadedObjectMotionPropertiesFreeListArray(void *object)
{
    static_cast<MotionPropertiesFreeListArray *>(object)->~MotionPropertiesFreeListArray();
}

static void finishLoadedObjectShapeInstanceFreeListArray(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) ShapeInstanceFreeListArray(flag);
}

static void cleanupLoadedObjectShapeInstanceFreeListArray(void *object)
{
    static_cast<ShapeInstanceFreeListArray *>(object)->~ShapeInstanceFreeListArray();
}

extern const hkClass D_57c1ef0; /* derived name: hknpMaterial's hkClass */
extern const hkClass D_57bf4c0; /* derived name: hknpMotionProperties' hkClass */
extern const hkClass D_57bfe90; /* derived name: hknpShapeInstance's hkClass */

/* The three arrays' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_1696a10[2] = {
#include "gen/D_1696a10.inc"
};
static const hkClassMember D_1696a60[2] = {
#include "gen/D_1696a60.inc"
};
static const hkClassMember D_1696ab0[2] = {
#include "gen/D_1696ab0.inc"
};

/* This file's static initializer (0x3f090): each free-list array's
 * reflection (elements and firstFree) and type info (no vtable), the
 * names the scoped template spellings of the executable. */
const hkClass
    D_57c0868("hkFreeListArrayhknpMaterialhknpMaterialId8hknpMaterialFreeListArrayOperations", 0,
              sizeof(MaterialFreeListArray), 0, 0, 0, 0, D_1696a10, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c08b8;
const hkTypeInfo D_57c08b8(
    "hkFreeListArrayhknpMaterialhknpMaterialId8hknpMaterialFreeListArrayOperations",
    "!hkFreeListArrayhknpMaterialhknpMaterialId8hknpMaterialFreeListArrayOperations_typename",
    finishLoadedObjectMaterialFreeListArray, cleanupLoadedObjectMaterialFreeListArray, 0,
    sizeof(MaterialFreeListArray));
const hkClass D_57c08e8("hkFreeListArrayhknpMotionPropertieshknpMotionPropertiesId8"
                        "hknpMotionPropertiesFreeListArrayOperations",
                        0, sizeof(MotionPropertiesFreeListArray), 0, 0, 0, 0, D_1696a60, 2, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c0938;
const hkTypeInfo D_57c0938("hkFreeListArrayhknpMotionPropertieshknpMotionPropertiesId8"
                           "hknpMotionPropertiesFreeListArrayOperations",
                           "!hkFreeListArrayhknpMotionPropertieshknpMotionPropertiesId8"
                           "hknpMotionPropertiesFreeListArrayOperations_typename",
                           finishLoadedObjectMotionPropertiesFreeListArray,
                           cleanupLoadedObjectMotionPropertiesFreeListArray, 0,
                           sizeof(MotionPropertiesFreeListArray));
const hkClass D_57c0968("hkFreeListArrayhknpShapeInstancehkHandleshort32767"
                        "hknpShapeInstanceIdDiscriminant8hknpShapeInstance",
                        0, sizeof(ShapeInstanceFreeListArray), 0, 0, 0, 0, D_1696ab0, 2, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c09b8;
const hkTypeInfo D_57c09b8("hkFreeListArrayhknpShapeInstancehkHandleshort32767"
                           "hknpShapeInstanceIdDiscriminant8hknpShapeInstance",
                           "!hkFreeListArrayhknpShapeInstancehkHandleshort32767"
                           "hknpShapeInstanceIdDiscriminant8hknpShapeInstance_typename",
                           finishLoadedObjectShapeInstanceFreeListArray,
                           cleanupLoadedObjectShapeInstanceFreeListArray, 0,
                           sizeof(ShapeInstanceFreeListArray));
