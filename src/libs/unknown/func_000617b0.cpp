/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClass D_57bf1c0;         /* hknpShape's hkClass */
extern const hkClassMember D_1699720[]; /* derived name: hknpConvexShape's records */

void FUN_00061790(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpConvexShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpConvexShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpConvexShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x617b0): hknpConvexShape's reflection,
 * hknpShape's as the parent, its one member, then its type info (its
 * finish callback, the destructor, the vtable). */
const hkClass D_57c1908("hknpConvexShape", &D_57bf1c0, sizeof(hknpConvexShape), 0, 0, 0, 0,
                        D_1699720, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1958;
const hkTypeInfo D_57c1958("hknpConvexShape", "!hknpConvexShape", FUN_00061790, FUN_000002d0,
                           vtableOfhknpConvexShape(), sizeof(hknpConvexShape));
