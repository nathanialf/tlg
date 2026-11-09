/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39). The key mask and the two datas are constructed in place through
 * their inline finish constructors, which store only the vtable (kept, at
 * 0x343b0, 0x343e0 and 0x34440), and destroyed through their virtual
 * destructors (the body the linker folded, 0x2d0); the two trees have
 * nothing to finish (the shared empty body, 0x1c1e0) and are destroyed in
 * place, their nodes freed (folded with the static tree storages' 0x1e170
 * and 0x1e270). derived names. */
static void finishLoadedObjecthknpCompoundShapeInternalsKeyMask(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCompoundShapeInternalsKeyMask(flag);
}

static void cleanupLoadedObjecthknpCompoundShapeInternalsKeyMask(void *object)
{
    static_cast<hknpCompoundShapeInternalsKeyMask *>(object)->~hknpCompoundShapeInternalsKeyMask();
}

static void finishLoadedObjecthknpDynamicCompoundShapeData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDynamicCompoundShapeData(flag);
}

static void cleanupLoadedObjecthknpDynamicCompoundShapeData(void *object)
{
    static_cast<hknpDynamicCompoundShapeData *>(object)->~hknpDynamicCompoundShapeData();
}

static void finishLoadedObjecthknpDynamicCompoundShapeTree(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDynamicCompoundShapeTree(flag);
}

static void cleanupLoadedObjecthknpDynamicCompoundShapeTree(void *object)
{
    static_cast<hknpDynamicCompoundShapeTree *>(object)->~hknpDynamicCompoundShapeTree();
}

static void finishLoadedObjecthknpStaticCompoundShapeData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpStaticCompoundShapeData(flag);
}

static void cleanupLoadedObjecthknpStaticCompoundShapeData(void *object)
{
    static_cast<hknpStaticCompoundShapeData *>(object)->~hknpStaticCompoundShapeData();
}

static void finishLoadedObjecthknpStaticCompoundShapeTree(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpStaticCompoundShapeTree(flag);
}

static void cleanupLoadedObjecthknpStaticCompoundShapeTree(void *object)
{
    static_cast<hknpStaticCompoundShapeTree *>(object)->~hknpStaticCompoundShapeTree();
}

/* The vtables' addresses, read from objects finished in aligned buffers
 * (the finish constructors are inline, so each folds to the address
 * point). derived names. */
static const void *vtableOfhknpCompoundShapeInternalsKeyMask()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpCompoundShapeInternalsKeyMask)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpCompoundShapeInternalsKeyMask(flag);
    return object.vtable;
}

static const void *vtableOfhknpDynamicCompoundShapeData()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpDynamicCompoundShapeData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpDynamicCompoundShapeData(flag);
    return object.vtable;
}

static const void *vtableOfhknpStaticCompoundShapeData()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpStaticCompoundShapeData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpStaticCompoundShapeData(flag);
    return object.vtable;
}

extern const hkClass D_57bba90; /* hkcdDynamicTreeDefaultTree32Storage's hkClass */
extern const hkClass D_57bab80; /* hkcdStaticTreeDefaultTreeStorage6's hkClass */
extern const hkClass D_57be020;
extern const hkClass D_57be120;

/* The key mask's three member records and the datas' one each, file-local
 * (D17); the rows are written at build time from the user's executable
 * (D18, config/data_schema.base.txt). */
static const hkClassMember D_16929d0[3] = {
#include "gen/D_16929d0.inc"
};
static const hkClassMember D_1692a50[1] = {
#include "gen/D_1692a50.inc"
};
static const hkClassMember D_1692a80[1] = {
#include "gen/D_1692a80.inc"
};

/* This file's static initializer (0x34490): the key mask's reflection over
 * hknpCompoundShapeKeyMask's (three members) and type info, the dynamic
 * data's over hkReferencedObject's (one member), the dynamic tree's over its
 * storage's, the static data's over hkReferencedObject's (one member) and
 * the static tree's over its storage's, each with its type info. */
const hkClass D_57bdf20("hknpCompoundShapeInternalsKeyMask", &D_57c2ec8,
                        sizeof(hknpCompoundShapeInternalsKeyMask), 0, 0, 0, 0, D_16929d0, 3, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57bdf70;
const hkTypeInfo D_57bdf70("hknpCompoundShapeInternalsKeyMask",
                           "!hknpCompoundShapeInternalsKeyMask",
                           finishLoadedObjecthknpCompoundShapeInternalsKeyMask,
                           cleanupLoadedObjecthknpCompoundShapeInternalsKeyMask,
                           vtableOfhknpCompoundShapeInternalsKeyMask(),
                           sizeof(hknpCompoundShapeInternalsKeyMask));
const hkClass D_57bdfa0("hknpDynamicCompoundShapeData", &D_57b8640,
                        sizeof(hknpDynamicCompoundShapeData), 0, 0, 0, 0, D_1692a50, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57bdff0;
const hkTypeInfo D_57bdff0("hknpDynamicCompoundShapeData", "!hknpDynamicCompoundShapeData",
                           finishLoadedObjecthknpDynamicCompoundShapeData,
                           cleanupLoadedObjecthknpDynamicCompoundShapeData,
                           vtableOfhknpDynamicCompoundShapeData(),
                           sizeof(hknpDynamicCompoundShapeData));
const hkClass D_57be020("hknpDynamicCompoundShapeTree", &D_57bba90,
                        sizeof(hknpDynamicCompoundShapeTree), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57be070;
const hkTypeInfo D_57be070("hknpDynamicCompoundShapeTree", "!hknpDynamicCompoundShapeTree",
                           finishLoadedObjecthknpDynamicCompoundShapeTree,
                           cleanupLoadedObjecthknpDynamicCompoundShapeTree, 0,
                           sizeof(hknpDynamicCompoundShapeTree));
const hkClass D_57be0a0("hknpStaticCompoundShapeData", &D_57b8640,
                        sizeof(hknpStaticCompoundShapeData), 0, 0, 0, 0, D_1692a80, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57be0f0;
const hkTypeInfo D_57be0f0("hknpStaticCompoundShapeData", "!hknpStaticCompoundShapeData",
                           finishLoadedObjecthknpStaticCompoundShapeData,
                           cleanupLoadedObjecthknpStaticCompoundShapeData,
                           vtableOfhknpStaticCompoundShapeData(),
                           sizeof(hknpStaticCompoundShapeData));
const hkClass D_57be120("hknpStaticCompoundShapeTree", &D_57bab80,
                        sizeof(hknpStaticCompoundShapeTree), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57be170;
const hkTypeInfo D_57be170("hknpStaticCompoundShapeTree", "!hknpStaticCompoundShapeTree",
                           finishLoadedObjecthknpStaticCompoundShapeTree,
                           cleanupLoadedObjecthknpStaticCompoundShapeTree, 0,
                           sizeof(hknpStaticCompoundShapeTree));
