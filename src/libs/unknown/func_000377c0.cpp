/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpMaterialPalette's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_000377c0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMaterialPalette(flag);
}

/* hknpMaterialPalette's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16937f0[]; /* derived name: hknpMaterialPalette's records */

/* The address of hknpMaterialPalette's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpMaterialPalette() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpMaterialPalette)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpMaterialPalette(flag);
    return object.vtable;
}

/* This file's static initializer (0x377e0): hknpMaterialPalette's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57beba8("hknpMaterialPalette", &D_57b8640, sizeof(hknpMaterialPalette), 0, 0, 0, 0,
                        D_16937f0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57bebf8;
const hkTypeInfo D_57bebf8("hknpMaterialPalette", "!hknpMaterialPalette", FUN_000377c0,
                           FUN_000002d0, vtableOfhknpMaterialPalette(),
                           sizeof(hknpMaterialPalette));
