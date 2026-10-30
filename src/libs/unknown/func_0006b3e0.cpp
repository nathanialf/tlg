/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClassMember D_169a9a0[]; /* derived name: hknpDestructionShapeProperties's records */

void FUN_0006b3c0(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpDestructionShapeProperties() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpDestructionShapeProperties)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpDestructionShapeProperties(flag);
    return object.vtable;
}

/* This file's static initializer (0x6b3e0): hknpDestructionShapeProperties's reflection,
 * hkReferencedObject's as the parent, four members, version 1,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c25f8("hknpDestructionShapeProperties", &D_57b8640,
                        sizeof(hknpDestructionShapeProperties), 0, 0, 0, 0, D_169a9a0, 4, 0, 0, 0,
                        1);
extern const hkTypeInfo D_57c2648;
const hkTypeInfo D_57c2648("hknpDestructionShapeProperties", "!hknpDestructionShapeProperties",
                           FUN_0006b3c0, FUN_000002d0, vtableOfhknpDestructionShapeProperties(),
                           sizeof(hknpDestructionShapeProperties));
