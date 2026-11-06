/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callback kept at 0x88e80), and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthkxAnimatedMatrix(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxAnimatedMatrix(flag);
}

static void cleanupLoadedObjecthkxAnimatedMatrix(void *object) /* derived name */
{
    static_cast<hkxAnimatedMatrix *>(object)->~hkxAnimatedMatrix();
}

/* The address of hkxAnimatedMatrix's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhkxAnimatedMatrix() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxAnimatedMatrix)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxAnimatedMatrix(flag);
    return object.vtable;
}

/* This file's static initializer (0x88ea0): hkxAnimatedMatrix's two member
 * records, built at run time from the hint's enum pointer, then its
 * reflection over hkReferencedObject's (version 2) and its type info with
 * its vtable. */
static hkClassMember D_57c6e70[] = {
    {"matrices", 0, 0, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_REAL, 0, 0, 0x10, 0},
    {"hint", 0, D_16dc6d0, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0x20, 0}};
const hkClass D_57c6df0("hkxAnimatedMatrix", &D_57b8640, sizeof(hkxAnimatedMatrix), 0, 0, 0, 0,
                        D_57c6e70, 2, 0, 0, 0, 2);
extern const hkTypeInfo D_57c6e40;
const hkTypeInfo D_57c6e40("hkxAnimatedMatrix", "!hkxAnimatedMatrix",
                           finishLoadedObjecthkxAnimatedMatrix,
                           cleanupLoadedObjecthkxAnimatedMatrix, vtableOfhkxAnimatedMatrix(),
                           sizeof(hkxAnimatedMatrix));
