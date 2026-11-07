/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the point's finish and cleanup folded by the linker into the empty
 * body 0x3b640; the info's and the wheel's finishes kept beside the
 * initializer (0x42a20, 0x42a50), their cleanups folded into 0x2d0. */
static void finishLoadedObjecthknpTyremarkPoint(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpTyremarkPoint(flag);
}

static void cleanupLoadedObjecthknpTyremarkPoint(void *object)
{
    static_cast<hknpTyremarkPoint *>(object)->~hknpTyremarkPoint();
}

static void finishLoadedObjecthknpTyremarksInfo(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpTyremarksInfo(flag);
}

static void cleanupLoadedObjecthknpTyremarksInfo(void *object)
{
    static_cast<hknpTyremarksInfo *>(object)->~hknpTyremarksInfo();
}

static void finishLoadedObjecthknpTyremarksWheel(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpTyremarksWheel(flag);
}

static void cleanupLoadedObjecthknpTyremarksWheel(void *object)
{
    static_cast<hknpTyremarksWheel *>(object)->~hknpTyremarksWheel();
}

/* The address of each class's vtable, read from an object finished in a
 * buffer (folded to the address point). derived names. */
static const void *vtableOfhknpTyremarksInfo()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpTyremarksInfo)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpTyremarksInfo(flag);
    return object.vtable;
}

static const void *vtableOfhknpTyremarksWheel()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpTyremarksWheel)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpTyremarksWheel(flag);
    return object.vtable;
}

extern const hkClass D_57b8640; /* derived name: hkReferencedObject's hkClass */
extern const hkClass D_57c1190;
extern const hkClass D_57c1290;

/* The three classes' member records, file-local (D17); the rows are
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_1697b30[2] = {
#include "gen/D_1697b30.inc"
};
static const hkClassMember D_1697b80[3] = {
#include "gen/D_1697b80.inc"
};
static const hkClassMember D_1697c00[3] = {
#include "gen/D_1697c00.inc"
};

/* This file's static initializer (0x42a70): the tyremark point's
 * reflection (its two points) and type info (no vtable), then the info's
 * and the wheel's over hkReferencedObject's, with their type infos. */
const hkClass D_57c1190("hknpTyremarkPoint", 0, sizeof(hknpTyremarkPoint), 0, 0, 0, 0, D_1697b30, 2,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57c11e0;
const hkTypeInfo D_57c11e0("hknpTyremarkPoint", "!hknpTyremarkPoint",
                           finishLoadedObjecthknpTyremarkPoint,
                           cleanupLoadedObjecthknpTyremarkPoint, 0, sizeof(hknpTyremarkPoint));
extern const hkClass D_57c1210;
const hkClass D_57c1210("hknpTyremarksInfo", &D_57b8640, sizeof(hknpTyremarksInfo), 0, 0, 0, 0,
                        D_1697b80, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1260;
const hkTypeInfo D_57c1260("hknpTyremarksInfo", "!hknpTyremarksInfo",
                           finishLoadedObjecthknpTyremarksInfo,
                           cleanupLoadedObjecthknpTyremarksInfo, vtableOfhknpTyremarksInfo(),
                           sizeof(hknpTyremarksInfo));
const hkClass D_57c1290("hknpTyremarksWheel", &D_57b8640, sizeof(hknpTyremarksWheel), 0, 0, 0, 0,
                        D_1697c00, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c12e0;
const hkTypeInfo D_57c12e0("hknpTyremarksWheel", "!hknpTyremarksWheel",
                           finishLoadedObjecthknpTyremarksWheel,
                           cleanupLoadedObjecthknpTyremarksWheel, vtableOfhknpTyremarksWheel(),
                           sizeof(hknpTyremarksWheel));
