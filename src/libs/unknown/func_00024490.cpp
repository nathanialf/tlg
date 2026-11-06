/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type infos' own callbacks, this file's (static): the transform set's
 * finish kept at 0x24400 (a jump to the out-of-line finish constructor),
 * its cleanup folded by the linker into 0x2d0; the mapping's finish folded
 * into the shared empty body 0x1c1e0, its cleanup kept at 0x24440 (the
 * indices freed). */
static void finishLoadedObjecthkIndexedTransformSet(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkIndexedTransformSet(flag);
}

static void cleanupLoadedObjecthkIndexedTransformSet(void *object)
{
    static_cast<hkIndexedTransformSet *>(object)->~hkIndexedTransformSet();
}

static void finishLoadedObjecthkMeshBoneIndexMapping(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMeshBoneIndexMapping(flag);
}

static void cleanupLoadedObjecthkMeshBoneIndexMapping(void *object)
{
    static_cast<hkMeshBoneIndexMapping *>(object)->~hkMeshBoneIndexMapping();
}

/* The address of the transform set's vtable, read from an object finished
 * in a buffer (its finish constructor out of line, so called). derived
 * name. */
static const void *vtableOfhkIndexedTransformSet()
{
    union {
        void *vtable;
        char buffer[sizeof(hkIndexedTransformSet)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkIndexedTransformSet(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57bd388;
static const hkClassMember D_1691d10[6] = {
#include "gen/D_1691d10.inc"
};
static const hkClassMember D_1691e00[1] = {
#include "gen/D_1691e00.inc"
};

/* This file's static initializer (0x24490): hkIndexedTransformSet's
 * reflection over hkReferencedObject's (six members, version 2) and type
 * info, then hkMeshBoneIndexMapping's (one member, no vtable). */
const hkClass D_57bd308("hkIndexedTransformSet", &D_57b8640, sizeof(hkIndexedTransformSet), 0, 0, 0,
                        0, D_1691d10, 6, 0, 0, 0, 2);
extern const hkTypeInfo D_57bd358;
const hkTypeInfo D_57bd358("hkIndexedTransformSet", "!hkIndexedTransformSet",
                           finishLoadedObjecthkIndexedTransformSet,
                           cleanupLoadedObjecthkIndexedTransformSet,
                           vtableOfhkIndexedTransformSet(), sizeof(hkIndexedTransformSet));
const hkClass D_57bd388("hkMeshBoneIndexMapping", 0, sizeof(hkMeshBoneIndexMapping), 0, 0, 0, 0,
                        D_1691e00, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57bd3d8;
const hkTypeInfo D_57bd3d8("hkMeshBoneIndexMapping", "!hkMeshBoneIndexMapping",
                           finishLoadedObjecthkMeshBoneIndexMapping,
                           cleanupLoadedObjecthkMeshBoneIndexMapping, 0,
                           sizeof(hkMeshBoneIndexMapping));
