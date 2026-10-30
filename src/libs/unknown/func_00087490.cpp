/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxVertexVectorDataChannel's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00087490(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexVectorDataChannel(flag);
}

/* hkxVertexVectorDataChannel's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a0e30[]; /* derived name: hkxVertexVectorDataChannel's records */

/* The address of hkxVertexVectorDataChannel's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxVertexVectorDataChannel() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxVertexVectorDataChannel)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxVertexVectorDataChannel(flag);
    return object.vtable;
}

/* This file's static initializer (0x874b0): hkxVertexVectorDataChannel's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57c66d0("hkxVertexVectorDataChannel", &D_57b8640,
                        sizeof(hkxVertexVectorDataChannel), 0, 0, 0, 0, D_16a0e30, 1, 0, 0, 0, 2);
extern const hkTypeInfo D_57c6720;
const hkTypeInfo D_57c6720("hkxVertexVectorDataChannel", "!hkxVertexVectorDataChannel",
                           FUN_00087490, FUN_000002d0, vtableOfhkxVertexVectorDataChannel(),
                           sizeof(hkxVertexVectorDataChannel));
