/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

extern const hkClassMember D_1694290[]; /* derived name: hknpMotionPropertiesLibrary's records */

void FUN_00038c10(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpMotionPropertiesLibrary() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpMotionPropertiesLibrary)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpMotionPropertiesLibrary(flag);
    return object.vtable;
}

/* This file's static initializer (0x38c30): hknpMotionPropertiesLibrary's
 * reflection, hkReferencedObject's as the parent, its four members, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57bf050("hknpMotionPropertiesLibrary", &D_57b8640,
                        sizeof(hknpMotionPropertiesLibrary), 0, 0, 0, 0, D_1694290, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf0a0;
const hkTypeInfo D_57bf0a0("hknpMotionPropertiesLibrary", "!hknpMotionPropertiesLibrary",
                           FUN_00038c10, FUN_000002d0, vtableOfhknpMotionPropertiesLibrary(),
                           sizeof(hknpMotionPropertiesLibrary));
