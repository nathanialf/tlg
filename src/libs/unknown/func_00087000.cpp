/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxTriangleSelectionChannel's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00087000(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxTriangleSelectionChannel(flag);
}

/* hkxTriangleSelectionChannel's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a0d80[]; /* derived name: hkxTriangleSelectionChannel's records */

/* The address of hkxTriangleSelectionChannel's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxTriangleSelectionChannel() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxTriangleSelectionChannel)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxTriangleSelectionChannel(flag);
    return object.vtable;
}

/* This file's static initializer (0x87020): hkxTriangleSelectionChannel's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57c6650("hkxTriangleSelectionChannel", &D_57b8640,
                        sizeof(hkxTriangleSelectionChannel), 0, 0, 0, 0, D_16a0d80, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c66a0;
const hkTypeInfo D_57c66a0("hkxTriangleSelectionChannel", "!hkxTriangleSelectionChannel",
                           FUN_00087000, FUN_000002d0, vtableOfhkxTriangleSelectionChannel(),
                           sizeof(hkxTriangleSelectionChannel));
