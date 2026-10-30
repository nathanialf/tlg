/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxVertexIntDataChannel's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_000880f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexIntDataChannel(flag);
}

/* hkxVertexIntDataChannel's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a12a0[]; /* derived name: hkxVertexIntDataChannel's records */

/* The address of hkxVertexIntDataChannel's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxVertexIntDataChannel() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxVertexIntDataChannel)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxVertexIntDataChannel(flag);
    return object.vtable;
}

/* This file's static initializer (0x88110): hkxVertexIntDataChannel's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57c6a20("hkxVertexIntDataChannel", &D_57b8640, sizeof(hkxVertexIntDataChannel), 0,
                        0, 0, 0, D_16a12a0, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c6a70;
const hkTypeInfo D_57c6a70("hkxVertexIntDataChannel", "!hkxVertexIntDataChannel", FUN_000880f0,
                           FUN_000002d0, vtableOfhkxVertexIntDataChannel(),
                           sizeof(hkxVertexIntDataChannel));
