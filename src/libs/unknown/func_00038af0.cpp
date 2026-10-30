/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpDecoratorShape's type info (0x57bf020):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_00038af0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDecoratorShape(flag);
}

/* hknpDecoratorShape's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_1694240[]; /* derived name: hknpDecoratorShape's records */

/* The address of hknpDecoratorShape's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x3b0f0, so the object is built on
 * the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhknpDecoratorShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpDecoratorShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpDecoratorShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x38b10): hknpDecoratorShape's reflection over hknpShape's
 * (version 0), its two members, then its type info. */
const hkClass D_57befd0("hknpDecoratorShape", &D_57bf1c0, sizeof(hknpDecoratorShape), 0, 0, 0, 0,
                        D_1694240, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf020;
const hkTypeInfo D_57bf020("hknpDecoratorShape", "!hknpDecoratorShape", FUN_00038af0, FUN_000002d0,
                           vtableOfhknpDecoratorShape(), sizeof(hknpDecoratorShape));
