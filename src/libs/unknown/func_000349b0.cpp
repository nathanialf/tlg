/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
/* The compressed mesh shape's reflection object, 0x349b0 to 0x34f50 (one
 * CIE, docs/DECISIONS.md D44), in the base's order. */
#include "tlg_lib_unknown.h"

/* hknpCompressedMeshShapeInternals::KeyMask's destructor (slot 0 of its
 * vtable): the filter given back. */
hknpCompressedMeshShapeInternals::KeyMask::~KeyMask() {}

/* derived name: slot 3 of hknpCompressedMeshShapeInternals::KeyMask's vtable
 * (0x1692ad8): a key's bit in the filter set or cleared by the shape's mesh
 * tree, the key shifted down past the shape's own bits. */
void hknpCompressedMeshShapeInternals::KeyMask::FUN_000381b0(u32 key, bool enabled)
{
    const int numBits = shape->numShapeKeyBits;
    const u32 subKey = (key >> (32 - numBits)) & ((1 << numBits) - 1);
    shape->data->meshTree.FUN_000a9410(filter, subKey, enabled);
}

/* derived name: slot 4 of hknpCompressedMeshShapeInternals::KeyMask's vtable
 * (address point 0x1692ac0): the shape's mesh tree applies the filter. */
bool hknpCompressedMeshShapeInternals::KeyMask::FUN_000381d0()
{
    return shape->data->meshTree.FUN_000a92c0(filter);
}

/* derived name: slot 5 of hknpCompressedMeshShapeInternals::KeyMask's vtable
 * (0x1692ae8): whether a key passes the filter, asked of the shape's mesh
 * tree with the key shifted down past the shape's own bits. */
bool hknpCompressedMeshShapeInternals::KeyMask::FUN_000381f0(u32 key) const
{
    const int numBits = shape->numShapeKeyBits;
    const u32 subKey = (key >> (32 - numBits)) & ((1 << numBits) - 1);
    return shape->data->meshTree.FUN_000a9550(filter, subKey);
}

/* The finish callback of hknpCompressedMeshShapeData's type info (the
 * reflection initializer passes it at 0x3500a); this file's (static,
 * docs/DECISIONS.md D39). Its destructors, the vtable's, are emitted
 * before it. derived name. */
static void finishLoadedObjecthknpCompressedMeshShapeData(void *object,
                                                          int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCompressedMeshShapeData(flag);
}

/* derived name: the finish callback of hknpCompressedMeshShapeInternals::KeyMask's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void
finishLoadedObjecthknpCompressedMeshShapeInternalsKeyMask(void *object,
                                                          int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCompressedMeshShapeInternals::KeyMask(flag);
}

/* The finish callback of hknpCompressedMeshShapeTree's type info (0x34e30;
 * the mesh tree instance's type info in the next file, 0x57be570, cites
 * the same body): the object constructed in place from a loaded image
 * through its out-of-line finish constructor. derived name. */
static void finishLoadedObjecthknpCompressedMeshShapeTree(void *object,
                                                          int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_000a9140(static_cast<hknpCompressedMeshShapeTree *>(object), flag);
}

/* Its cleanup callback (0x34e40, cited by the same type info): the tree
 * destroyed in place, its data runs, shared and packed vertices given back,
 * then the base's destructor. derived name. */
static void cleanupLoadedObjecthknpCompressedMeshShapeTree(void *object) /* derived name */
{
    static_cast<hknpCompressedMeshShapeTree *>(object)->~hknpCompressedMeshShapeTree();
}

/* The two referenced classes' cleanup callbacks: the object destroyed
 * through its virtual destructor (the linker folded the bodies with the
 * other classes', 0x2d0). derived names. */
static void cleanupLoadedObjecthknpCompressedMeshShapeData(void *object) /* derived name */
{
    static_cast<hknpCompressedMeshShapeData *>(object)->~hknpCompressedMeshShapeData();
}

static void
cleanupLoadedObjecthknpCompressedMeshShapeInternalsKeyMask(void *object) /* derived name */
{
    static_cast<hknpCompressedMeshShapeInternals::KeyMask *>(object)->~KeyMask();
}

/* The data runs' cleanup callbacks: nothing to clean up (the linker folded
 * them into the empty body 0x1c1e0). derived names. */
static void cleanupLoadedObjecthknpCompressedMeshShapeTreeDataRun(void *object) /* derived name */
{
    static_cast<hknpCompressedMeshShapeTreeDataRun *>(object)
        ->~hknpCompressedMeshShapeTreeDataRun();
}

static void
cleanupLoadedObjecthknpCompressedMeshShapeTreeDataRunData(void *object) /* derived name */
{
    static_cast<hknpCompressedMeshShapeTreeDataRunData *>(object)
        ->~hknpCompressedMeshShapeTreeDataRunData();
}

/* The classes' vtables, read from an object each finish constructor builds
 * (cookbook 166). derived names. */
static const void *vtableOfhknpCompressedMeshShapeData() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpCompressedMeshShapeData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpCompressedMeshShapeData(flag);
    return object.vtable;
}

static const void *vtableOfhknpCompressedMeshShapeInternalsKeyMask() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpCompressedMeshShapeInternals::KeyMask)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpCompressedMeshShapeInternals::KeyMask(flag);
    return object.vtable;
}

extern const hkClass D_57bb390; /* derived name: hkcdSimdTree's hkClass */
extern const hkClass D_57bc290; /* derived name: the connectivity's hkClass */
extern const hkClass D_57c2678; /* derived name: hknpCompressedMeshShape's hkClass */
extern const hkClass D_57be2a0; /* derived name: the tree's hkClass, below */
extern const hkClass D_57be4a0; /* derived name: the run base instance's hkClass */
extern const hkClass D_57be520; /* derived name: the mesh tree instance's hkClass */
/* The classes' member records, file-local (D17; the extern form rotates
 * three registers of the first type info's group, cookbook 481); the rows
 * are written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_1692b40[3] = {
#include "gen/D_1692b40.inc"
};
static const hkClassMember D_1692bc0[2] = {
#include "gen/D_1692bc0.inc"
};
static const hkClassMember D_1692c10[1] = {
#include "gen/D_1692c10.inc"
};

/* This file's static initializer (0x34f50): the reflection and type info
 * of the shape data (over hkReferencedObject's, three members, version 1),
 * the key mask (two members), the tree (over the mesh tree instance's), the
 * data run (over the run base instance's) and the run data (one member),
 * the last three with no vtable. */
const hkClass D_57be1a0("hknpCompressedMeshShapeData", &D_57b8640,
                        sizeof(hknpCompressedMeshShapeData), 0, 0, 0, 0, D_1692b40, 3, 0, 0, 0, 1);
extern const hkTypeInfo D_57be1f0;
const hkTypeInfo D_57be1f0("hknpCompressedMeshShapeData", "!hknpCompressedMeshShapeData",
                           finishLoadedObjecthknpCompressedMeshShapeData,
                           cleanupLoadedObjecthknpCompressedMeshShapeData,
                           vtableOfhknpCompressedMeshShapeData(),
                           sizeof(hknpCompressedMeshShapeData));
const hkClass D_57be220("hknpCompressedMeshShapeInternalsKeyMask", &D_57c1aa8,
                        sizeof(hknpCompressedMeshShapeInternals::KeyMask), 0, 0, 0, 0, D_1692bc0, 2,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57be270;
const hkTypeInfo D_57be270("hknpCompressedMeshShapeInternalsKeyMask",
                           "!hknpCompressedMeshShapeInternals::KeyMask",
                           finishLoadedObjecthknpCompressedMeshShapeInternalsKeyMask,
                           cleanupLoadedObjecthknpCompressedMeshShapeInternalsKeyMask,
                           vtableOfhknpCompressedMeshShapeInternalsKeyMask(),
                           sizeof(hknpCompressedMeshShapeInternals::KeyMask));
const hkClass D_57be2a0("hknpCompressedMeshShapeTree", &D_57be520,
                        sizeof(hknpCompressedMeshShapeTree), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57be2f0;
const hkTypeInfo D_57be2f0("hknpCompressedMeshShapeTree", "!hknpCompressedMeshShapeTree",
                           finishLoadedObjecthknpCompressedMeshShapeTree,
                           cleanupLoadedObjecthknpCompressedMeshShapeTree, 0,
                           sizeof(hknpCompressedMeshShapeTree));
const hkClass D_57be320("hknpCompressedMeshShapeTreeDataRun", &D_57be4a0,
                        sizeof(hknpCompressedMeshShapeTreeDataRun), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57be370;
const hkTypeInfo D_57be370("hknpCompressedMeshShapeTreeDataRun",
                           "!hknpCompressedMeshShapeTreeDataRun", 0,
                           cleanupLoadedObjecthknpCompressedMeshShapeTreeDataRun, 0,
                           sizeof(hknpCompressedMeshShapeTreeDataRun));
const hkClass D_57be3a0("hknpCompressedMeshShapeTreeDataRunData", 0,
                        sizeof(hknpCompressedMeshShapeTreeDataRunData), 0, 0, 0, 0, D_1692c10, 1, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57be3f0;
const hkTypeInfo D_57be3f0("hknpCompressedMeshShapeTreeDataRunData",
                           "!hknpCompressedMeshShapeTreeDataRunData", 0,
                           cleanupLoadedObjecthknpCompressedMeshShapeTreeDataRunData, 0,
                           sizeof(hknpCompressedMeshShapeTreeDataRunData));
