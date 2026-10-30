/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClassMember D_169aa40[]; /* derived name: hknpCompressedMeshShape's records */

void FUN_0006b4f0(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpCompressedMeshShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpCompressedMeshShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpCompressedMeshShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x6b510): hknpCompressedMeshShape's reflection,
 * its parent's as the parent, five members, version 5,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c2678("hknpCompressedMeshShape", &D_57c2cf8, sizeof(hknpCompressedMeshShape), 0,
                        0, 0, 0, D_169aa40, 5, 0, 0, 0, 5);
extern const hkTypeInfo D_57c26c8;
const hkTypeInfo D_57c26c8("hknpCompressedMeshShape", "!hknpCompressedMeshShape", FUN_0006b4f0,
                           FUN_000002d0, vtableOfhknpCompressedMeshShape(),
                           sizeof(hknpCompressedMeshShape));
