/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the finishes kept
 * beside the initializer (0x3f610, 0x3f640), each a jump to the
 * out-of-line finish constructor; the cleanups folded by the linker into
 * 0x2d0. */
static void finishLoadedObjecthknpScaledConvexShape(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpScaledConvexShape(flag);
}

static void cleanupLoadedObjecthknpScaledConvexShape(void *object)
{
    static_cast<hknpScaledConvexShape *>(object)->~hknpScaledConvexShape();
}

static void finishLoadedObjecthknpScaledConvexShapeBase(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpScaledConvexShapeBase(flag);
}

static void cleanupLoadedObjecthknpScaledConvexShapeBase(void *object)
{
    static_cast<hknpScaledConvexShapeBase *>(object)->~hknpScaledConvexShapeBase();
}

/* The addresses of the two vtables, read from objects finished in a buffer
 * (their finish constructors out of line, so called). derived names. */
static const void *vtableOfhknpScaledConvexShape()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpScaledConvexShape)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpScaledConvexShape(flag);
    return object.vtable;
}

static const void *vtableOfhknpScaledConvexShapeBase()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpScaledConvexShapeBase)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpScaledConvexShapeBase(flag);
    return object.vtable;
}

extern const hkClass D_57befd0; /* derived name: hknpDecoratorShape's hkClass */
extern const hkClass D_57c2478; /* derived name: hknpShapeSignals's hkClass */
extern const hkClass D_57c0bf8;

/* hknpScaledConvexShape's member record, file-local (D17); the row is
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_1696d90[1] = {
#include "gen/D_1696d90.inc"
};
/* hknpScaledConvexShapeBase's records, another file's: its address through
 * the GOT keeps the lea group in the base's registers (cookbook 481).
 * derived name. */
extern const hkClassMember D_1696dc0[];

/* This file's static initializer (0x3f660): hknpScaledConvexShape's
 * reflection over its base's (one member) and type info, then
 * hknpScaledConvexShapeBase's over hknpDecoratorShape's (two members,
 * version 2) and type info. */
const hkClass D_57c0ba8("hknpScaledConvexShape", &D_57c0bf8, sizeof(hknpScaledConvexShape), 0, 0, 0,
                        0, D_1696d90, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0c48;
const hkTypeInfo D_57c0c48("hknpScaledConvexShape", "!hknpScaledConvexShape",
                           finishLoadedObjecthknpScaledConvexShape,
                           cleanupLoadedObjecthknpScaledConvexShape,
                           vtableOfhknpScaledConvexShape(), sizeof(hknpScaledConvexShape));
const hkClass D_57c0bf8("hknpScaledConvexShapeBase", &D_57befd0, sizeof(hknpScaledConvexShapeBase),
                        0, 0, 0, 0, D_1696dc0, 2, 0, 0, 0, 2);
extern const hkTypeInfo D_57c0c78;
const hkTypeInfo D_57c0c78("hknpScaledConvexShapeBase", "!hknpScaledConvexShapeBase",
                           finishLoadedObjecthknpScaledConvexShapeBase,
                           cleanupLoadedObjecthknpScaledConvexShapeBase,
                           vtableOfhknpScaledConvexShapeBase(), sizeof(hknpScaledConvexShapeBase));
