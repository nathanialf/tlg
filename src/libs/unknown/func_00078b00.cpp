/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkpLinearParametricCurve's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00078b00(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLinearParametricCurve(flag);
}

/* hkpLinearParametricCurve's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
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
const hkTypeInfo D_57c32b8("hkpLinearParametricCurve", "!hkpLinearParametricCurve", FUN_00078b00,
                           FUN_000002d0, vtableOfhkpLinearParametricCurve(),
                           sizeof(hkpLinearParametricCurve));
