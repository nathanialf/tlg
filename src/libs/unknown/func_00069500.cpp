/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClass D_57bf540;         /* hknpHeightFieldShape's hkClass */
extern const hkClassMember D_169a620[]; /* derived name: hknpCompressedHeightFieldShape's records */

void FUN_000694e0(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpCompressedHeightFieldShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpCompressedHeightFieldShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpCompressedHeightFieldShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x69500): hknpCompressedHeightFieldShape's reflection,
 * hknpHeightFieldShape's as the parent, five members,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c2328("hknpCompressedHeightFieldShape", &D_57bf540,
                        sizeof(hknpCompressedHeightFieldShape), 0, 0, 0, 0, D_169a620, 5, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c2378;
const hkTypeInfo D_57c2378("hknpCompressedHeightFieldShape", "!hknpCompressedHeightFieldShape",
                           FUN_000694e0, FUN_000002d0, vtableOfhknpCompressedHeightFieldShape(),
                           sizeof(hknpCompressedHeightFieldShape));
