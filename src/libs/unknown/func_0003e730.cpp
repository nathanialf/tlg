/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpTriangleShape's type info (0x57c0838):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpTriangleShape(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpTriangleShape(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpTriangleShape(void *object) /* derived name */
{
    static_cast<hknpTriangleShape *>(object)->~hknpTriangleShape();
}

/* The address of hknpTriangleShape's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x78230, so the object is built on
 * the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhknpTriangleShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpTriangleShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpTriangleShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x3e750): hknpTriangleShape's reflection over
 * hknpConvexPolytopeShape's (version 1), no members of its own, then its type info. */
const hkClass D_57c07e8("hknpTriangleShape", &D_57bf710, sizeof(hknpTriangleShape), 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 1);
extern const hkTypeInfo D_57c0838;
const hkTypeInfo D_57c0838("hknpTriangleShape", "!hknpTriangleShape",
                           finishLoadedObjecthknpTriangleShape,
                           cleanupLoadedObjecthknpTriangleShape, vtableOfhknpTriangleShape(),
                           sizeof(hknpTriangleShape));
