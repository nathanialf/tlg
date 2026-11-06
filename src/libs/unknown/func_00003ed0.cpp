/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the finishes kept at 0x3e80 and 0x3eb0 beside the initializer, the
 * cleanups folded by the linker into the empty body 0x270 and the shared
 * virtual destructor call 0x2d0. */
static void finishLoadedObjecthkUuid(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkUuid(flag);
}

static void cleanupLoadedObjecthkUuid(void *object)
{
    static_cast<hkUuid *>(object)->~hkUuid();
}

static void finishLoadedObjecthkUuidObject(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkUuidObject(flag);
}

static void cleanupLoadedObjecthkUuidObject(void *object)
{
    static_cast<hkUuidObject *>(object)->~hkUuidObject();
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). hkUuidObject's cites hkUuid's class. */
extern const hkClass D_57b7a00;

static const hkClassMember D_168c920[1] = {
#include "gen/D_168c920.inc"
};

static const hkClassMember D_168c950[1] = {
#include "gen/D_168c950.inc"
};

/* The address of hkUuidObject's vtable, read from an object finished in a
 * buffer (folded to the address point). derived name. */
static const void *vtableOfhkUuidObject()
{
    union {
        void *vtable;
        char buffer[sizeof(hkUuidObject)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkUuidObject(flag);
    return object.vtable;
}

/* This file's static initializer (0x3ed0): hkUuid's reflection (no parent,
 * one member, version 1) and type info, then hkUuidObject's over
 * hkReferencedObject's (one member) and type info with its vtable. */
const hkClass D_57b7a00("hkUuid", 0, sizeof(hkUuid), 0, 0, 0, 0, D_168c920, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57b7a50;
const hkTypeInfo D_57b7a50("hkUuid", "!hkUuid", finishLoadedObjecthkUuid, cleanupLoadedObjecthkUuid,
                           0, sizeof(hkUuid));
const hkClass D_57b7a80("hkUuidObject", &D_57b8640, sizeof(hkUuidObject), 0, 0, 0, 0, D_168c950, 1,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57b7ad0;
const hkTypeInfo D_57b7ad0("hkUuidObject", "!hkUuidObject", finishLoadedObjecthkUuidObject,
                           cleanupLoadedObjecthkUuidObject, vtableOfhkUuidObject(),
                           sizeof(hkUuidObject));
