/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkcdPlanarCsgOperand's type info (0x57ba260):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthkcdPlanarCsgOperand(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarCsgOperand(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkcdPlanarCsgOperand(void *object) /* derived name */
{
    static_cast<hkcdPlanarCsgOperand *>(object)->~hkcdPlanarCsgOperand();
}

extern const hkClassMember D_168f420[]; /* derived name: hkcdPlanarCsgOperand's records */

/* The address of hkcdPlanarCsgOperand's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x9c0a0, so the object is built on
 * the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhkcdPlanarCsgOperand() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkcdPlanarCsgOperand)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdPlanarCsgOperand(flag);
    return object.vtable;
}

/* This file's static initializer (0x1d2b0): hkcdPlanarCsgOperand's reflection over
 * hkReferencedObject's (version 1), its three members, then its type info. */
const hkClass D_57ba210("hkcdPlanarCsgOperand", &D_57b8640, sizeof(hkcdPlanarCsgOperand), 0, 0, 0,
                        0, D_168f420, 3, 0, 0, 0, 1);
extern const hkTypeInfo D_57ba260;
const hkTypeInfo D_57ba260("hkcdPlanarCsgOperand", "!hkcdPlanarCsgOperand",
                           finishLoadedObjecthkcdPlanarCsgOperand,
                           cleanupLoadedObjecthkcdPlanarCsgOperand, vtableOfhkcdPlanarCsgOperand(),
                           sizeof(hkcdPlanarCsgOperand));
