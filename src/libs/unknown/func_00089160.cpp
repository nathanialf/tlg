/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the finishes kept
 * beside the initializer (0x890e0, its strings' finish constructors called;
 * 0x89140, a jump to the out-of-line finish constructor); the cleanups
 * folded by the linker into 0x2d0. */
static void finishLoadedObjecthkxMeshUserChannelInfo(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMesh::UserChannelInfo(flag);
}

static void cleanupLoadedObjecthkxMeshUserChannelInfo(void *object)
{
    static_cast<hkxMesh::UserChannelInfo *>(object)->~UserChannelInfo();
}

static void finishLoadedObjecthkxMesh(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMesh(flag);
}

static void cleanupLoadedObjecthkxMesh(void *object)
{
    static_cast<hkxMesh *>(object)->~hkxMesh();
}

/* The addresses of the two vtables, read from objects finished in a buffer
 * (the channel's finish constructor inline, so its vtable is the constant
 * it stores; the mesh's out of line, so called). derived names. */
static const void *vtableOfhkxMeshUserChannelInfo()
{
    union {
        void *vtable;
        char buffer[sizeof(hkxMesh::UserChannelInfo)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxMesh::UserChannelInfo(flag);
    return object.vtable;
}

static const void *vtableOfhkxMesh()
{
    union {
        void *vtable;
        char buffer[sizeof(hkxMesh)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxMesh(flag);
    return object.vtable;
}

extern const hkClass D_57b8640; /* derived name: hkReferencedObject's hkClass */
extern const hkClass D_57c76b0; /* derived name: hkxAttributeHolder's hkClass */
extern const hkClass D_57c81b0; /* derived name: hkxMeshSection's hkClass */
extern const hkClass D_57c6ec0;

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_16a15d0[2] = {
#include "gen/D_16a15d0.inc"
};
static const hkClassMember D_16a1620[2] = {
#include "gen/D_16a1620.inc"
};

/* This file's static initializer (0x89160): the user channel's reflection
 * over hkxAttributeHolder's (two members) and type info, then hkxMesh's
 * over hkReferencedObject's (two members, version 1) and type info. */
const hkClass D_57c6ec0("hkxMeshUserChannelInfo", &D_57c76b0, sizeof(hkxMesh::UserChannelInfo), 0,
                        0, 0, 0, D_16a15d0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c6f10;
const hkTypeInfo D_57c6f10("hkxMeshUserChannelInfo", "!hkxMesh::UserChannelInfo",
                           finishLoadedObjecthkxMeshUserChannelInfo,
                           cleanupLoadedObjecthkxMeshUserChannelInfo,
                           vtableOfhkxMeshUserChannelInfo(), sizeof(hkxMesh::UserChannelInfo));
const hkClass D_57c6f40("hkxMesh", &D_57b8640, sizeof(hkxMesh), 0, 0, 0, 0, D_16a1620, 2, 0, 0, 0,
                        1);
extern const hkTypeInfo D_57c6f90;
const hkTypeInfo D_57c6f90("hkxMesh", "!hkxMesh", finishLoadedObjecthkxMesh,
                           cleanupLoadedObjecthkxMesh, vtableOfhkxMesh(), sizeof(hkxMesh));
