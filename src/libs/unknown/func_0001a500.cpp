/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the triangle's cleanup folded by the linker into the empty body
 * 0xe5c0, the geometry's finish kept at 0x1a4e0 beside the initializer and
 * its cleanup folded into the shared virtual destructor call 0x2d0. */
static void cleanupLoadedObjecthkGeometryTriangle(void *object)
{
    static_cast<hkGeometry::Triangle *>(object)->~Triangle();
}

static void finishLoadedObjecthkGeometry(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkGeometry(flag);
}

static void cleanupLoadedObjecthkGeometry(void *object)
{
    static_cast<hkGeometry *>(object)->~hkGeometry();
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). The geometry's cites the triangle's
 * class. */
extern const hkClass D_57b9a70;

static const hkClassMember D_168e950[4] = {
#include "gen/D_168e950.inc"
};

static const hkClassMember D_168ea40[2] = {
#include "gen/D_168ea40.inc"
};

/* hkGeometry's one enum, file-local likewise; its items the base's. */
extern const hkClassEnum::Item D_168e9f0; /* the first of its two items */

static const hkClassEnum D_168ea10[1] = {
#include "gen/D_168ea10.inc"
};

/* The address of hkGeometry's vtable, read from an object finished in a
 * buffer (folded to the address point). derived name. */
static const void *vtableOfhkGeometry()
{
    union {
        void *vtable;
        char buffer[sizeof(hkGeometry)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkGeometry(flag);
    return object.vtable;
}

/* This file's static initializer (0x1a500): hkGeometry::Triangle's
 * reflection (no parent, four members) and type info, then hkGeometry's
 * over hkReferencedObject's (its one enum, two members, version 1) and type
 * info with its vtable. The type infos' names are the base's strings. */
const hkClass D_57b9a70("hkGeometryTriangle", 0, sizeof(hkGeometry::Triangle), 0, 0, 0, 0,
                        D_168e950, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57b9ac0;
const hkTypeInfo D_57b9ac0("hkGeometryTriangle", "!hkGeometry::Triangle", 0,
                           cleanupLoadedObjecthkGeometryTriangle, 0, sizeof(hkGeometry::Triangle));
const hkClass D_57b9af0("hkGeometry", &D_57b8640, sizeof(hkGeometry), 0, 0, D_168ea10, 1, D_168ea40,
                        2, 0, 0, 0, 1);
extern const hkTypeInfo D_57b9b40;
const hkTypeInfo D_57b9b40("hkGeometry", "!hkGeometry", finishLoadedObjecthkGeometry,
                           cleanupLoadedObjecthkGeometry, vtableOfhkGeometry(), sizeof(hkGeometry));
