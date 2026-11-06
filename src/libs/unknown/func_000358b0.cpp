/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpDynamicCompoundShape's type info (0x57be690):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpDynamicCompoundShape(void *object,
                                                       int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDynamicCompoundShape(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpDynamicCompoundShape(void *object) /* derived name */
{
    static_cast<hknpDynamicCompoundShape *>(object)->~hknpDynamicCompoundShape();
}

extern const hkClassMember D_1692e50[];    /* derived name: hknpDynamicCompoundShape's record */
extern const hkCustomAttributes D_1692ea0; /* derived name: its class's attributes */

/* The address of hknpDynamicCompoundShape's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x469a0, so the object is built on
 * the stack, 0xc0 bytes at -0xe0 below the guard's -0x18). */
static const void *vtableOfhknpDynamicCompoundShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpDynamicCompoundShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpDynamicCompoundShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x358d0): hknpDynamicCompoundShape's reflection over
 * hknpCompoundShape's (version 1), its one member and its attributes, then its type info. */
const hkClass D_57be640("hknpDynamicCompoundShape", &D_57c2e78, sizeof(hknpDynamicCompoundShape), 0,
                        0, 0, 0, D_1692e50, 1, 0, &D_1692ea0, 0, 1);
extern const hkTypeInfo D_57be690;
const hkTypeInfo D_57be690("hknpDynamicCompoundShape", "!hknpDynamicCompoundShape",
                           finishLoadedObjecthknpDynamicCompoundShape,
                           cleanupLoadedObjecthknpDynamicCompoundShape,
                           vtableOfhknpDynamicCompoundShape(), sizeof(hknpDynamicCompoundShape));
