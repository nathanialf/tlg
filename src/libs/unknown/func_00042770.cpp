/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the filter's finish kept at 0x42750 beside the initializer, its
 * cleanup folded by the linker into the shared virtual destructor call
 * 0x2d0, the map layout's cleanup into the empty body 0x3b640. */
static void cleanupLoadedObjecthknpPairCollisionFilterMapPairFilterKeyOverrideType(void *object)
{
    static_cast<hknpPairCollisionFilter::MapPairFilterKeyOverrideType *>(object)
        ->~MapPairFilterKeyOverrideType();
}

static void finishLoadedObjecthknpPairCollisionFilter(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpPairCollisionFilter(flag);
}

static void cleanupLoadedObjecthknpPairCollisionFilter(void *object)
{
    static_cast<hknpPairCollisionFilter *>(object)->~hknpPairCollisionFilter();
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). The filter's cites the map layout's
 * class. */
extern const hkClass D_57c1090;

static const hkClassMember D_1697a20[3] = {
#include "gen/D_1697a20.inc"
};

static const hkClassMember D_1697aa0[2] = {
#include "gen/D_1697aa0.inc"
};

/* The address of hknpPairCollisionFilter's vtable, read from an object
 * finished in a buffer (folded to the address point). */
static const void *vtableOfhknpPairCollisionFilter() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpPairCollisionFilter)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpPairCollisionFilter(flag);
    return object.vtable;
}

/* This file's static initializer (0x42770): the map layout's reflection
 * (no parent, three members) and type info, then hknpPairCollisionFilter's
 * over hknpCollisionFilter's (two members) and type info with its vtable.
 * The type infos' names are the base's strings. */
const hkClass D_57c1090("hknpPairCollisionFilterMapPairFilterKeyOverrideType", 0,
                        sizeof(hknpPairCollisionFilter::MapPairFilterKeyOverrideType), 0, 0, 0, 0,
                        D_1697a20, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c10e0;
const hkTypeInfo D_57c10e0("hknpPairCollisionFilterMapPairFilterKeyOverrideType",
                           "!hknpPairCollisionFilter::MapPairFilterKeyOverrideType", 0,
                           cleanupLoadedObjecthknpPairCollisionFilterMapPairFilterKeyOverrideType,
                           0, sizeof(hknpPairCollisionFilter::MapPairFilterKeyOverrideType));
const hkClass D_57c1110("hknpPairCollisionFilter", &D_57c0cb0, sizeof(hknpPairCollisionFilter), 0,
                        0, 0, 0, D_1697aa0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1160;
const hkTypeInfo D_57c1160("hknpPairCollisionFilter", "!hknpPairCollisionFilter",
                           finishLoadedObjecthknpPairCollisionFilter,
                           cleanupLoadedObjecthknpPairCollisionFilter,
                           vtableOfhknpPairCollisionFilter(), sizeof(hknpPairCollisionFilter));
