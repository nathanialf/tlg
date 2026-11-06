/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxVertexVectorDataChannel's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthkxVertexVectorDataChannel(void *object,
                                                         int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexVectorDataChannel(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkxVertexVectorDataChannel(void *object) /* derived name */
{
    static_cast<hkxVertexVectorDataChannel *>(object)->~hkxVertexVectorDataChannel();
}

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
                           finishLoadedObjecthkxVertexVectorDataChannel,
                           cleanupLoadedObjecthkxVertexVectorDataChannel,
                           vtableOfhkxVertexVectorDataChannel(),
                           sizeof(hkxVertexVectorDataChannel));
