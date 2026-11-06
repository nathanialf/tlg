/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkpLinearParametricCurve's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthkpLinearParametricCurve(void *object,
                                                       int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLinearParametricCurve(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkpLinearParametricCurve(void *object) /* derived name */
{
    static_cast<hkpLinearParametricCurve *>(object)->~hkpLinearParametricCurve();
}

extern const hkClassMember D_169ba00[]; /* derived name: hkpLinearParametricCurve's records */

/* The address of hkpLinearParametricCurve's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkpLinearParametricCurve() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkpLinearParametricCurve)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkpLinearParametricCurve(flag);
    return object.vtable;
}

/* This file's static initializer (0x78b20): hkpLinearParametricCurve's reflection over hkpParametricCurve's, its 5 members, then its type info. */
const hkClass D_57c3268("hkpLinearParametricCurve", &D_57c3c68, sizeof(hkpLinearParametricCurve), 0,
                        0, 0, 0, D_169ba00, 5, 0, 0, 0, 0);
extern const hkTypeInfo D_57c32b8;
const hkTypeInfo D_57c32b8("hkpLinearParametricCurve", "!hkpLinearParametricCurve",
                           finishLoadedObjecthkpLinearParametricCurve,
                           cleanupLoadedObjecthkpLinearParametricCurve,
                           vtableOfhkpLinearParametricCurve(), sizeof(hkpLinearParametricCurve));
