/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxEdgeSelectionChannel's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00088cb0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxEdgeSelectionChannel(flag);
}

/* hkxEdgeSelectionChannel's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a1520[]; /* derived name: hkxEdgeSelectionChannel's records */

/* The address of hkxEdgeSelectionChannel's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxEdgeSelectionChannel() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxEdgeSelectionChannel)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxEdgeSelectionChannel(flag);
    return object.vtable;
}

/* This file's static initializer (0x88cd0): hkxEdgeSelectionChannel's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57c6d68("hkxEdgeSelectionChannel", &D_57b8640, sizeof(hkxEdgeSelectionChannel), 0,
                        0, 0, 0, D_16a1520, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c6db8;
const hkTypeInfo D_57c6db8("hkxEdgeSelectionChannel", "!hkxEdgeSelectionChannel", FUN_00088cb0,
                           FUN_000002d0, vtableOfhkxEdgeSelectionChannel(),
                           sizeof(hkxEdgeSelectionChannel));
