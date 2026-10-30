/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpCompositeShape's type info
 * (stored at 0x71777): construct the shape in place from a loaded image
 * through its inline finish constructor. */
void FUN_00071690(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCompositeShape(flag);
}

/* hknpCompositeShape's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_169b1d0[]; /* derived name: hknpCompositeShape's records */

/* The address of hknpCompositeShape's vtable, read from an object finished in a 16-byte
 * aligned buffer: the finish constructor is inline, so the vtable folds to its address, but
 * hknpShape's out-of-line finish constructor (0x6fa90) still runs on the stack. */
static const void *vtableOfhknpCompositeShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpCompositeShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpCompositeShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x716d0): hknpCompositeShape's reflection over hknpShape's
 * (version 0), its two members, then its type info. */
const hkClass D_57c2cf8("hknpCompositeShape", &D_57bf1c0, sizeof(hknpCompositeShape), 0, 0, 0, 0,
                        D_169b1d0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c2d48;
const hkTypeInfo D_57c2d48("hknpCompositeShape", "!hknpCompositeShape", FUN_00071690, FUN_000002d0,
                           vtableOfhknpCompositeShape(), sizeof(hknpCompositeShape));
