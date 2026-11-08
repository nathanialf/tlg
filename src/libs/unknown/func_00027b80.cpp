/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): a bone section finished through its out-of-line finish constructor
 * (the callback kept at 0x27b80, a jump) and destroyed by its mesh's
 * release (folded into the properties entry's cleanup 0xd300); a bone set
 * and a part destroyed by nothing (folded into the empty 0x1c1e0); the
 * storage shape constructed in place through its out-of-line finish
 * constructor (kept at 0x27be0) and destroyed through its virtual
 * destructor (the folded 0x2d0). derived names. */
static void finishLoadedObjecthkSkinnedMeshShapeBoneSection(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_000add70(static_cast<hkSkinnedMeshShapeBoneSection *>(object), flag);
}

static void cleanupLoadedObjecthkSkinnedMeshShapeBoneSet(void *object)
{
    static_cast<hkSkinnedMeshShape::BoneSet *>(object)->~BoneSet();
}

static void cleanupLoadedObjecthkSkinnedMeshShapeBoneSection(void *object)
{
    static_cast<hkSkinnedMeshShape::BoneSection *>(object)->~BoneSection();
}

static void cleanupLoadedObjecthkSkinnedMeshShapePart(void *object)
{
    static_cast<hkSkinnedMeshShape::Part *>(object)->~Part();
}

static void finishLoadedObjecthkStorageSkinnedMeshShape(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkStorageSkinnedMeshShape(flag);
}

static void cleanupLoadedObjecthkStorageSkinnedMeshShape(void *object)
{
    static_cast<hkStorageSkinnedMeshShape *>(object)->~hkStorageSkinnedMeshShape();
}

/* The address of hkStorageSkinnedMeshShape's vtable, read from an object
 * finished in a buffer by the out-of-line finish constructor. */
static const void *vtableOfhkStorageSkinnedMeshShape()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkStorageSkinnedMeshShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkStorageSkinnedMeshShape(flag);
    return object.vtable;
}

extern const hkClass D_57bdb48; /* hkSkinnedMeshShape::BoneSet's hkClass */
extern const hkClass D_57bdbc8; /* hkSkinnedMeshShape::BoneSection's hkClass */
extern const hkClass D_57bdc48; /* hkSkinnedMeshShape::Part's hkClass */

/* The member records, file-local (D17); the rows are written at build time
 * from the user's executable (D18, config/data_schema.base.txt). */
static const hkClassMember D_1692230[2] = {
#include "gen/D_1692230.inc"
};
static const hkClassMember D_16923a0[3] = {
#include "gen/D_16923a0.inc"
};
static const hkClassMember D_1692280[7] = {
#include "gen/D_1692280.inc"
};
static const hkClassMember D_1692420[5] = {
#include "gen/D_1692420.inc"
};

/* This file's static initializer (0x27c00): the three nested structs'
 * classes, each with its type info, hkSkinnedMeshShape's (over
 * hkReferencedObject's, no type info) and hkStorageSkinnedMeshShape's with
 * its type info. */
const hkClass D_57bdb48("hkSkinnedMeshShapeBoneSet", 0, sizeof(hkSkinnedMeshShape::BoneSet), 0, 0,
                        0, 0, D_1692230, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57bdb98;
const hkTypeInfo D_57bdb98("hkSkinnedMeshShapeBoneSet", "!hkSkinnedMeshShape::BoneSet", 0,
                           cleanupLoadedObjecthkSkinnedMeshShapeBoneSet, 0,
                           sizeof(hkSkinnedMeshShape::BoneSet));
const hkClass D_57bdbc8("hkSkinnedMeshShapeBoneSection", 0, sizeof(hkSkinnedMeshShape::BoneSection),
                        0, 0, 0, 0, D_16923a0, 3, 0, 0, 0, 1);
extern const hkTypeInfo D_57bdc18;
const hkTypeInfo D_57bdc18("hkSkinnedMeshShapeBoneSection", "!hkSkinnedMeshShape::BoneSection",
                           finishLoadedObjecthkSkinnedMeshShapeBoneSection,
                           cleanupLoadedObjecthkSkinnedMeshShapeBoneSection, 0,
                           sizeof(hkSkinnedMeshShape::BoneSection));
const hkClass D_57bdc48("hkSkinnedMeshShapePart", 0, sizeof(hkSkinnedMeshShape::Part), 0, 0, 0, 0,
                        D_1692280, 7, 0, 0, 0, 1);
extern const hkTypeInfo D_57bdc98;
const hkTypeInfo D_57bdc98("hkSkinnedMeshShapePart", "!hkSkinnedMeshShape::Part", 0,
                           cleanupLoadedObjecthkSkinnedMeshShapePart, 0,
                           sizeof(hkSkinnedMeshShape::Part));
extern const hkClass D_57bdcc8;
const hkClass D_57bdcc8("hkSkinnedMeshShape", &D_57b8640, sizeof(hkSkinnedMeshShape), 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0);
const hkClass D_57bdd18("hkStorageSkinnedMeshShape", &D_57bdcc8, sizeof(hkStorageSkinnedMeshShape),
                        0, 0, 0, 0, D_1692420, 5, 0, 0, 0, 1);
extern const hkTypeInfo D_57bdd68;
const hkTypeInfo D_57bdd68("hkStorageSkinnedMeshShape", "!hkStorageSkinnedMeshShape",
                           finishLoadedObjecthkStorageSkinnedMeshShape,
                           cleanupLoadedObjecthkStorageSkinnedMeshShape,
                           vtableOfhkStorageSkinnedMeshShape(), sizeof(hkStorageSkinnedMeshShape));
