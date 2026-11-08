/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type infos' callbacks, this file's (static, docs/DECISIONS.md D39).
 * Face and Connectivity::Edge have nothing to destroy (the empty body the
 * linker folded, 0x396a0) and no finish callback. */
static void cleanupLoadedObjecthknpConvexPolytopeShapeFace(void *object) /* derived name */ {}

static void
cleanupLoadedObjecthknpConvexPolytopeShapeConnectivityEdge(void *object) /* derived name */
{
}

/* Connectivity's finish callback (0x39ae0): construct the object in place
 * from a loaded image through its inline finish constructor, which has
 * nothing to fix up but the vtable. Its complete and deleting destructors
 * (0x39950, 0x399d0) are emitted here with the vtable. */
static void finishLoadedObjecthknpConvexPolytopeShapeConnectivity(void *object,
                                                                  int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpConvexPolytopeShape::Connectivity(flag);
}

/* Its cleanup: the object destroyed in place through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void cleanupLoadedObjecthknpConvexPolytopeShapeConnectivity(void *object) /* derived name */
{
    static_cast<hknpConvexPolytopeShape::Connectivity *>(object)->~Connectivity();
}

/* The shape's finish callback (0x39b10): its out-of-line finish
 * constructor run in place. */
static void finishLoadedObjecthknpConvexPolytopeShape(void *object,
                                                      int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpConvexPolytopeShape(flag);
}

static void cleanupLoadedObjecthknpConvexPolytopeShape(void *object) /* derived name */
{
    static_cast<hknpConvexPolytopeShape *>(object)->~hknpConvexPolytopeShape();
}

/* The addresses of the two vtables, read from an object finished in a
 * buffer: Connectivity's folded to the address point (its constructor
 * inline), the shape's read back after the out-of-line constructor. */
static const void *vtableOfhknpConvexPolytopeShapeConnectivity() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpConvexPolytopeShape::Connectivity)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpConvexPolytopeShape::Connectivity(flag);
    return object.vtable;
}

static const void *vtableOfhknpConvexPolytopeShape() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpConvexPolytopeShape)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpConvexPolytopeShape(flag);
    return object.vtable;
}

extern const hkClass D_57bf590; /* hknpConvexPolytopeShape::Face's hkClass */
extern const hkClass D_57bf610; /* hknpConvexPolytopeShape::Connectivity::Edge's hkClass */
extern const hkClass D_57bf690; /* hknpConvexPolytopeShape::Connectivity's hkClass */

/* Face's, Edge's and Connectivity's member records, file-local (D17); the
 * rows are written at build time from the user's executable (D18). */
static const hkClassMember D_1694e60[3] = {
#include "gen/D_1694e60.inc"
};
static const hkClassMember D_1694ee0[2] = {
#include "gen/D_1694ee0.inc"
};
static const hkClassMember D_1694f30[2] = {
#include "gen/D_1694f30.inc"
};
/* The shape's records, another file's: its address through the GOT keeps
 * the lea group in the base's registers (cookbook 481). derived name. */
extern const hkClassMember D_1694f80[];

/* This file's static initializer (0x39b30): the reflection and type info
 * of hknpConvexPolytopeShape::Face, Connectivity::Edge, Connectivity (over
 * hkReferencedObject's) and the shape itself (over hknpConvexShape's,
 * version 3). */
const hkClass D_57bf590("hknpConvexPolytopeShapeFace", 0, sizeof(hknpConvexPolytopeShape::Face), 0,
                        0, 0, 0, D_1694e60, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf5e0;
const hkTypeInfo D_57bf5e0("hknpConvexPolytopeShapeFace", "!hknpConvexPolytopeShape::Face", 0,
                           cleanupLoadedObjecthknpConvexPolytopeShapeFace, 0,
                           sizeof(hknpConvexPolytopeShape::Face));
const hkClass D_57bf610("hknpConvexPolytopeShapeConnectivityEdge", 0,
                        sizeof(hknpConvexPolytopeShape::Connectivity::Edge), 0, 0, 0, 0, D_1694ee0,
                        2, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf660;
const hkTypeInfo D_57bf660("hknpConvexPolytopeShapeConnectivityEdge",
                           "!hknpConvexPolytopeShape::Connectivity::Edge", 0,
                           cleanupLoadedObjecthknpConvexPolytopeShapeConnectivityEdge, 0,
                           sizeof(hknpConvexPolytopeShape::Connectivity::Edge));
const hkClass D_57bf690("hknpConvexPolytopeShapeConnectivity", &D_57b8640,
                        sizeof(hknpConvexPolytopeShape::Connectivity), 0, 0, 0, 0, D_1694f30, 2, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57bf6e0;
const hkTypeInfo D_57bf6e0("hknpConvexPolytopeShapeConnectivity",
                           "!hknpConvexPolytopeShape::Connectivity",
                           finishLoadedObjecthknpConvexPolytopeShapeConnectivity,
                           cleanupLoadedObjecthknpConvexPolytopeShapeConnectivity,
                           vtableOfhknpConvexPolytopeShapeConnectivity(),
                           sizeof(hknpConvexPolytopeShape::Connectivity));
const hkClass D_57bf710("hknpConvexPolytopeShape", &D_57c1908, sizeof(hknpConvexPolytopeShape), 0,
                        0, 0, 0, D_1694f80, 4, 0, 0, 0, 3);
extern const hkTypeInfo D_57bf760;
const hkTypeInfo D_57bf760("hknpConvexPolytopeShape", "!hknpConvexPolytopeShape",
                           finishLoadedObjecthknpConvexPolytopeShape,
                           cleanupLoadedObjecthknpConvexPolytopeShape,
                           vtableOfhknpConvexPolytopeShape(), sizeof(hknpConvexPolytopeShape));
