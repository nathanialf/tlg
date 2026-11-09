/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): hknpShape and hknpShapeMassProperties each constructed in place
 * from a loaded image through its out-of-line finish constructor (the
 * callbacks kept at 0x38d30 and 0x38d60, jumps) and destroyed through its
 * virtual destructor (the folded 0x2d0). derived names. */
static void finishLoadedObjecthknpShape(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpShape(flag);
}

static void cleanupLoadedObjecthknpShape(void *object)
{
    static_cast<hknpShape *>(object)->~hknpShape();
}

static void finishLoadedObjecthknpShapeMassProperties(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpShapeMassProperties(flag);
}

static void cleanupLoadedObjecthknpShapeMassProperties(void *object)
{
    static_cast<hknpShapeMassProperties *>(object)->~hknpShapeMassProperties();
}

/* The classes' vtables, each read from an object its out-of-line finish
 * constructor builds on the stack (both in the one buffer, rbp-0x60).
 * derived names. */
static const void *vtableOfhknpShape()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpShape(flag);
    return object.vtable;
}

static const void *vtableOfhknpShapeMassProperties()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpShapeMassProperties)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpShapeMassProperties(flag);
    return object.vtable;
}

extern const hkClass D_57bc9e0; /* hkCompressedMassProperties's hkClass */

/* The file's tables, file-local (D17): hknpShapeMassProperties's record,
 * then hknpShape's three enums and their items; the rows are written at
 * build time from the user's executable (D18, config/data_schema.base.txt). */
static const hkClassMember D_1694330[1] = {
#include "gen/D_1694330.inc"
};
static const hkClassEnum::Item D_1694360[14] = {
#include "gen/D_1694360.inc"
};
static const hkClassEnum::Item D_1694440[2] = {
#include "gen/D_1694440.inc"
};
static const hkClassEnum::Item D_1694460[3] = {
#include "gen/D_1694460.inc"
};
static const hkClassEnum D_1694490[3] = {
#include "gen/D_1694490.inc"
};

/* The pointers of two of hknpShape's enums, globals its records read
 * (0x16dc5f0 holds the flags', 0x16dc608 the dispatch type's), so the
 * records are built when the file is initialized. derived names. */
extern const hkClassEnum *D_16dc5f0; /* FlagsEnum */
extern const hkClassEnum *D_16dc608; /* the dispatch type's */
extern const hkClass D_57b8588;      /* hkRefCountedProperties's hkClass */

/* hknpShape's records, a global of the file's own (the base reaches them
 * through the GOT, the stores relative to one register, 0x38dae). */
extern hkClassMember D_57bf0d0[6];
hkClassMember D_57bf0d0[6] = {
    {"flags",
     0,
     D_16dc5f0,
     hkClassMember::TYPE_FLAGS,
     hkClassMember::TYPE_UINT16,
     0,
     {hkClassMember::ALIGN_16},
     u16(HK_OFFSET_OF(hknpShape, flags)),
     0},
    {"numShapeKeyBits",
     0,
     0,
     hkClassMember::TYPE_UINT8,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpShape, numShapeKeyBits)),
     0},
    {"dispatchType",
     0,
     D_16dc608,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpShape, dispatchType)),
     0},
    {"convexRadius",
     0,
     0,
     hkClassMember::TYPE_REAL,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpShape, convexRadius)),
     0},
    {"userData",
     0,
     0,
     hkClassMember::TYPE_UINT64,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpShape, userData)),
     0},
    {"properties",
     &D_57b8588,
     0,
     hkClassMember::TYPE_POINTER,
     hkClassMember::TYPE_STRUCT,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpShape, properties)),
     0},
};

/* This file's static initializer (0x38d80): the records, hknpShape's
 * reflection over hkReferencedObject's (its three enums, version 2) and its
 * type info, then hknpShapeMassProperties's with its type info. */
const hkClass D_57bf1c0("hknpShape", &D_57b8640, sizeof(hknpShape), 0, 0, D_1694490, 3, D_57bf0d0,
                        6, 0, 0, 0, 2);
extern const hkTypeInfo D_57bf210;
const hkTypeInfo D_57bf210("hknpShape", "!hknpShape", finishLoadedObjecthknpShape,
                           cleanupLoadedObjecthknpShape, vtableOfhknpShape(), sizeof(hknpShape));
extern const hkClass D_57bf240;
const hkClass D_57bf240("hknpShapeMassProperties", &D_57b8640, sizeof(hknpShapeMassProperties), 0,
                        0, 0, 0, D_1694330, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf290;
const hkTypeInfo D_57bf290("hknpShapeMassProperties", "!hknpShapeMassProperties",
                           finishLoadedObjecthknpShapeMassProperties,
                           cleanupLoadedObjecthknpShapeMassProperties,
                           vtableOfhknpShapeMassProperties(), sizeof(hknpShapeMassProperties));
