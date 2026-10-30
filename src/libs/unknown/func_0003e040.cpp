/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClassMember D_16966e0[]; /* derived name: hknpWorldSnapshot's records */

void FUN_0003e020(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpWorldSnapshot() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpWorldSnapshot)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpWorldSnapshot(flag);
    return object.vtable;
}

/* This file's static initializer (0x3e040): hknpWorldSnapshot's reflection,
 * hkReferencedObject's as the parent, five members,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c05e8("hknpWorldSnapshot", &D_57b8640, sizeof(hknpWorldSnapshot), 0, 0, 0, 0,
                        D_16966e0, 5, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0638;
const hkTypeInfo D_57c0638("hknpWorldSnapshot", "!hknpWorldSnapshot", FUN_0003e020, FUN_000002d0,
                           vtableOfhknpWorldSnapshot(), sizeof(hknpWorldSnapshot));
