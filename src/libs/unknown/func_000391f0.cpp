/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the finishes kept beside the initializer (0x39190, a jump to the
 * scene data's out-of-line finish constructor; 0x391c0, the world info's
 * finish constructor inline); the cleanups folded by the linker into 0x2d0. */
static void finishLoadedObjecthknpPhysicsSceneData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpPhysicsSceneData(flag);
}

static void cleanupLoadedObjecthknpPhysicsSceneData(void *object)
{
    static_cast<hknpPhysicsSceneData *>(object)->~hknpPhysicsSceneData();
}

static void finishLoadedObjecthknpRefWorldCinfo(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpRefWorldCinfo(flag);
}

static void cleanupLoadedObjecthknpRefWorldCinfo(void *object)
{
    static_cast<hknpRefWorldCinfo *>(object)->~hknpRefWorldCinfo();
}

extern const hkClass D_57c0148; /* derived name: hknpPhysicsSystemData's hkClass */
extern const hkClass D_57c1390; /* derived name: hknpWorldCinfo's hkClass */
extern const hkClass D_57bf2c0;

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_1694550[2] = {
#include "gen/D_1694550.inc"
};
static const hkClassMember D_16945a0[1] = {
#include "gen/D_16945a0.inc"
};

/* The addresses of the two vtables, read from objects finished in a buffer
 * (the scene data's finish constructor out of line, so called; the world
 * info's inline). derived names. */
static const void *vtableOfhknpPhysicsSceneData()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpPhysicsSceneData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpPhysicsSceneData(flag);
    return object.vtable;
}

static const void *vtableOfhknpRefWorldCinfo()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpRefWorldCinfo)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpRefWorldCinfo(flag);
    return object.vtable;
}

/* This file's static initializer (0x391f0): hknpPhysicsSceneData's
 * reflection over hkReferencedObject's (two members, version 1) and type
 * info, then hknpRefWorldCinfo's (one member) and type info. */
const hkClass D_57bf310("hknpPhysicsSceneData", &D_57b8640, sizeof(hknpPhysicsSceneData), 0, 0, 0,
                        0, D_1694550, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57bf360;
const hkTypeInfo D_57bf360("hknpPhysicsSceneData", "!hknpPhysicsSceneData",
                           finishLoadedObjecthknpPhysicsSceneData,
                           cleanupLoadedObjecthknpPhysicsSceneData, vtableOfhknpPhysicsSceneData(),
                           sizeof(hknpPhysicsSceneData));
const hkClass D_57bf2c0("hknpRefWorldCinfo", &D_57b8640, sizeof(hknpRefWorldCinfo), 0, 0, 0, 0,
                        D_16945a0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf390;
const hkTypeInfo D_57bf390("hknpRefWorldCinfo", "!hknpRefWorldCinfo",
                           finishLoadedObjecthknpRefWorldCinfo,
                           cleanupLoadedObjecthknpRefWorldCinfo, vtableOfhknpRefWorldCinfo(),
                           sizeof(hknpRefWorldCinfo));
