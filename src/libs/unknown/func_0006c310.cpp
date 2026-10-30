/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpStaticCompoundShape's type info
 * (0x57c2818): construct the object in place from a loaded image through
 * its out-of-line finish constructor. */
void FUN_0006c310(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpStaticCompoundShape(flag);
}

/* hknpStaticCompoundShape's cleanup callback: the virtual destructor (the shared body
 * 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_169ab60[];    /* derived name: hknpStaticCompoundShape's record */
extern const hkCustomAttributes D_169abb0; /* derived name: its class's attributes */

/* The address of hknpStaticCompoundShape's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x385d0, so the object is built on
 * the stack, 0xc0 bytes at -0xe0 below the guard's -0x18). */
static const void *vtableOfhknpStaticCompoundShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpStaticCompoundShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpStaticCompoundShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x6c330): hknpStaticCompoundShape's reflection over
 * hknpCompoundShape's (version 1), its one member and its attributes, then its type info. */
const hkClass D_57c27c8("hknpStaticCompoundShape", &D_57c2e78, sizeof(hknpStaticCompoundShape), 0,
                        0, 0, 0, D_169ab60, 1, 0, &D_169abb0, 0, 1);
extern const hkTypeInfo D_57c2818;
const hkTypeInfo D_57c2818("hknpStaticCompoundShape", "!hknpStaticCompoundShape", FUN_0006c310,
                           FUN_000002d0, vtableOfhknpStaticCompoundShape(),
                           sizeof(hknpStaticCompoundShape));
