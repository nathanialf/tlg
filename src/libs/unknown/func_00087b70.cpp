/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callback kept at 0x87b50), and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthkxVertexFloatDataChannel(void *object,
                                                        int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexFloatDataChannel(flag);
}

static void cleanupLoadedObjecthkxVertexFloatDataChannel(void *object) /* derived name */
{
    static_cast<hkxVertexFloatDataChannel *>(object)->~hkxVertexFloatDataChannel();
}

/* The address of hkxVertexFloatDataChannel's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhkxVertexFloatDataChannel() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxVertexFloatDataChannel)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxVertexFloatDataChannel(flag);
    return object.vtable;
}

/* This file's static initializer (0x87b70): hkxVertexFloatDataChannel's two member
 * records, built at run time from the dimensions' enum pointer, then its
 * reflection over hkReferencedObject's (its one enum, version 1) and its type info with
 * its vtable. */
static hkClassMember D_57c68d0[] = {
    {"perVertexFloats", 0, 0, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_REAL, 0, 0, 0x10, 0},
    {"dimensions", 0, D_16dc6b0, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0x20,
     0}};
const hkClass D_57c6850("hkxVertexFloatDataChannel", &D_57b8640, sizeof(hkxVertexFloatDataChannel),
                        0, 0, D_16a1020, 1, D_57c68d0, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57c68a0;
const hkTypeInfo D_57c68a0("hkxVertexFloatDataChannel", "!hkxVertexFloatDataChannel",
                           finishLoadedObjecthkxVertexFloatDataChannel,
                           cleanupLoadedObjecthkxVertexFloatDataChannel,
                           vtableOfhkxVertexFloatDataChannel(), sizeof(hkxVertexFloatDataChannel));
