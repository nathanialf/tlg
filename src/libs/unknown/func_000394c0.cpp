/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hknpCapsuleShape's type info (0x57bf490):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpCapsuleShape(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCapsuleShape(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpCapsuleShape(void *object) /* derived name */
{
    static_cast<hknpCapsuleShape *>(object)->~hknpCapsuleShape();
}

extern const hkClass D_57bf710;         /* hknpConvexPolytopeShape's hkClass */
extern const hkClassMember D_1694850[]; /* derived name: hknpCapsuleShape's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpCapsuleShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpCapsuleShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpCapsuleShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x394c0): hknpCapsuleShape's reflection,
 * hknpConvexPolytopeShape's as the parent, its two members, then its type info (its
 * finish callback, the destructor, the vtable). */
const hkClass D_57bf440("hknpCapsuleShape", &D_57bf710, sizeof(hknpCapsuleShape), 0, 0, 0, 0,
                        D_1694850, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf490;
const hkTypeInfo D_57bf490("hknpCapsuleShape", "!hknpCapsuleShape",
                           finishLoadedObjecthknpCapsuleShape, cleanupLoadedObjecthknpCapsuleShape,
                           vtableOfhknpCapsuleShape(), sizeof(hknpCapsuleShape));
