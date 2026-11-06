/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the level info's
 * cleanup folded by the linker into the shared empty body 0x3b640; the lod
 * shape's finish kept at 0x3de50 beside the initializer (a jump to the
 * out-of-line finish constructor), its cleanup folded into 0x2d0. */
static void cleanupLoadedObjecthknpLodShapeLevelOfDetailInfo(void *object)
{
    static_cast<hknpLodShape::LevelOfDetailInfo *>(object)->~LevelOfDetailInfo();
}

static void finishLoadedObjecthknpLodShape(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpLodShape(flag);
}

static void cleanupLoadedObjecthknpLodShape(void *object)
{
    static_cast<hknpLodShape *>(object)->~hknpLodShape();
}

/* The address of hknpLodShape's vtable, read from an object finished in a
 * buffer (its finish constructor out of line, so called). derived name. */
static const void *vtableOfhknpLodShape()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpLodShape)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpLodShape(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c04e8;
static const hkClassMember D_1696570[2] = {
#include "gen/D_1696570.inc"
};
static const hkClassMember D_16965c0[7] = {
#include "gen/D_16965c0.inc"
};

/* This file's static initializer (0x3de70): the level info's reflection (no
 * parent, two members) and type info (no finish callback, no vtable), then
 * hknpLodShape's reflection over hknpCompositeShape's (seven members,
 * version 1) and type info. */
const hkClass D_57c04e8("hknpLodShapeLevelOfDetailInfo", 0, sizeof(hknpLodShape::LevelOfDetailInfo),
                        0, 0, 0, 0, D_1696570, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0538;
const hkTypeInfo D_57c0538("hknpLodShapeLevelOfDetailInfo", "!hknpLodShape::LevelOfDetailInfo", 0,
                           cleanupLoadedObjecthknpLodShapeLevelOfDetailInfo, 0,
                           sizeof(hknpLodShape::LevelOfDetailInfo));
const hkClass D_57c0568("hknpLodShape", &D_57c2cf8, sizeof(hknpLodShape), 0, 0, 0, 0, D_16965c0, 7,
                        0, 0, 0, 1);
extern const hkTypeInfo D_57c05b8;
const hkTypeInfo D_57c05b8("hknpLodShape", "!hknpLodShape", finishLoadedObjecthknpLodShape,
                           cleanupLoadedObjecthknpLodShape, vtableOfhknpLodShape(),
                           sizeof(hknpLodShape));
