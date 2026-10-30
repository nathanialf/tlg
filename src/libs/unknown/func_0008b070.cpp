/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkxMaterialShaderSet's type info (0x57c7680):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
void FUN_0008b070(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMaterialShaderSet(flag);
}

/* hkxMaterialShaderSet's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a1f00[]; /* derived name: hkxMaterialShaderSet's records */

/* The address of hkxMaterialShaderSet's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x8b370, so the object is built on
 * the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhkxMaterialShaderSet() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxMaterialShaderSet)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxMaterialShaderSet(flag);
    return object.vtable;
}

/* This file's static initializer (0x8b090): hkxMaterialShaderSet's reflection over
 * hkReferencedObject's (version 1), its one member, then its type info. */
const hkClass D_57c7630("hkxMaterialShaderSet", &D_57b8640, sizeof(hkxMaterialShaderSet), 0, 0, 0,
                        0, D_16a1f00, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7680;
const hkTypeInfo D_57c7680("hkxMaterialShaderSet", "!hkxMaterialShaderSet", FUN_0008b070,
                           FUN_000002d0, vtableOfhkxMaterialShaderSet(),
                           sizeof(hkxMaterialShaderSet));
