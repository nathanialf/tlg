/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callback kept at 0x88330), and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthkxIndexBuffer(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxIndexBuffer(flag);
}

static void cleanupLoadedObjecthkxIndexBuffer(void *object) /* derived name */
{
    static_cast<hkxIndexBuffer *>(object)->~hkxIndexBuffer();
}

/* The address of hkxIndexBuffer's vtable, read from an object finished in a
 * buffer (folded to the address point, 0x88588). */
static const void *vtableOfhkxIndexBuffer() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxIndexBuffer)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxIndexBuffer(flag);
    return object.vtable;
}

/* The IndexType enum and its five items, file-local; the rows the base's. */
static const hkClassEnum::Item D_16a1310[5] = {
#include "gen/D_16a1310.inc"
};

static const hkClassEnum D_16a1360[1] = {
#include "gen/D_16a1360.inc"
};

/* This file's static initializer (0x88350): hkxIndexBuffer's five member
 * records (in .bss, stored to directly: the file's own), built at run time
 * from the enum's pointer, then its class over
 * hkReferencedObject's and its type info with its vtable. */
static hkClassMember D_57c6b20[] = {
    {"indexType", 0, D_16dc6b8, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_INT8, 0, 0, 0xc, 0},
    {"indices16", 0, 0, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_UINT16, 0, 0, 0x10, 0},
    {"indices32", 0, 0, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_UINT32, 0, 0, 0x20, 0},
    {"vertexBaseOffset", 0, 0, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, 0x30, 0},
    {"length", 0, 0, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, 0x34, 0}};
const hkClass D_57c6aa0("hkxIndexBuffer", &D_57b8640, sizeof(hkxIndexBuffer), 0, 0, D_16a1360, 1,
                        D_57c6b20, 5, 0, 0, 0, 1);
extern const hkTypeInfo D_57c6af0;
const hkTypeInfo D_57c6af0("hkxIndexBuffer", "!hkxIndexBuffer", finishLoadedObjecthkxIndexBuffer,
                           cleanupLoadedObjecthkxIndexBuffer, vtableOfhkxIndexBuffer(),
                           sizeof(hkxIndexBuffer));
