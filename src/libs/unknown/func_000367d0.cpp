/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the finishes kept
 * beside the initializer (0x36780, 0x367b0), each a jump to the
 * out-of-line finish constructor; the cleanups folded by the linker into
 * 0x2d0. */
static void finishLoadedObjecthknpMaskedShapeMaskWrapper(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_00038230(static_cast<hknpMaskedShape::MaskWrapper *>(object), flag);
}

static void cleanupLoadedObjecthknpMaskedShapeMaskWrapper(void *object)
{
    static_cast<hknpMaskedShape::MaskWrapper *>(object)->~MaskWrapper();
}

static void finishLoadedObjecthknpMaskedShape(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMaskedShape(flag);
}

static void cleanupLoadedObjecthknpMaskedShape(void *object)
{
    static_cast<hknpMaskedShape *>(object)->~hknpMaskedShape();
}

/* The addresses of the two vtables, read from objects finished in a buffer
 * (their finish constructors out of line, so called). derived names. */
static const void *vtableOfhknpMaskedShapeMaskWrapper()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpMaskedShape::MaskWrapper)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    FUN_00038230(reinterpret_cast<hknpMaskedShape::MaskWrapper *>(object.buffer), flag);
    return object.vtable;
}

static const void *vtableOfhknpMaskedShape()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpMaskedShape)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpMaskedShape(flag);
    return object.vtable;
}

/* The shape's post-finish function, the shared empty body (D15). */
void FUN_0001c1e0(void *object);

extern const hkClass D_57befd0; /* derived name: hknpDecoratorShape's hkClass */
extern const hkClass D_57b8b90; /* derived name: hkPostFinishAttribute's hkClass */
extern const hkClass D_57be958;
/* hknpMaskedShape's records, another file's: its address through the GOT
 * keeps the lea group in the base's registers (cookbook 481). derived
 * name. */
extern const hkClassMember D_16936b0[];

/* The mask wrapper's member record and the shape's attribute, file-local
 * (D17); the rows are written at build time from the user's executable
 * (D18, config/data_schema.base.txt). */
static const hkClassMember D_1693670[1] = {
#include "gen/D_1693670.inc"
};
static const hkPostFinishAttribute D_1693768[1] = {
#include "gen/D_1693768.inc"
};
static const hkCustomAttributes::Attribute D_1693750[1] = {
#include "gen/D_1693750.inc"
};
static const hkCustomAttributes D_1693698[1] = {
#include "gen/D_1693698.inc"
};

/* This file's static initializer (0x367d0): the mask wrapper's reflection
 * over hknpShapeKeyMask's (one member) and type info, then hknpMaskedShape's
 * over hknpDecoratorShape's (four members, its post-finish attribute) and
 * type info. */
const hkClass D_57be958("hknpMaskedShapeMaskWrapper", &D_57c1aa8,
                        sizeof(hknpMaskedShape::MaskWrapper), 0, 0, 0, 0, D_1693670, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57be9a8;
const hkTypeInfo D_57be9a8("hknpMaskedShapeMaskWrapper", "!hknpMaskedShape::MaskWrapper",
                           finishLoadedObjecthknpMaskedShapeMaskWrapper,
                           cleanupLoadedObjecthknpMaskedShapeMaskWrapper,
                           vtableOfhknpMaskedShapeMaskWrapper(),
                           sizeof(hknpMaskedShape::MaskWrapper));
const hkClass D_57be9d8("hknpMaskedShape", &D_57befd0, sizeof(hknpMaskedShape), 0, 0, 0, 0,
                        D_16936b0, 4, 0, D_1693698, 0, 0);
extern const hkTypeInfo D_57bea28;
const hkTypeInfo D_57bea28("hknpMaskedShape", "!hknpMaskedShape", finishLoadedObjecthknpMaskedShape,
                           cleanupLoadedObjecthknpMaskedShape, vtableOfhknpMaskedShape(),
                           sizeof(hknpMaskedShape));
