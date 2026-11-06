/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the vertex data's
 * finish folded by the linker into the shared empty body 0x83250, its
 * cleanup kept at 0x87e20 (a jump to the out-of-line destructor); the
 * buffer's finish kept at 0x87e40, its cleanup folded into 0x2d0. */
static void finishLoadedObjecthkxVertexBufferVertexData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexBuffer::VertexData(flag);
}

static void cleanupLoadedObjecthkxVertexBufferVertexData(void *object)
{
    static_cast<hkxVertexBuffer::VertexData *>(object)->~VertexData();
}

static void finishLoadedObjecthkxVertexBuffer(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexBuffer(flag);
}

static void cleanupLoadedObjecthkxVertexBuffer(void *object)
{
    static_cast<hkxVertexBuffer *>(object)->~hkxVertexBuffer();
}

/* The address of the buffer's vtable, read from an object finished in a
 * buffer (its finish constructor out of line, so called). derived name. */
static const void *vtableOfhkxVertexBuffer()
{
    union {
        void *vtable;
        char buffer[sizeof(hkxVertexBuffer)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxVertexBuffer(flag);
    return object.vtable;
}

/* The two classes' member records, defined elsewhere: their addresses come
 * through the GOT (the compile with the tables in this file assigns the
 * buffer's records another register, 0x87efc). */
extern const hkClassMember D_16a1050[]; /* derived name: the vertex data's records */
extern const hkClassMember D_16a1210[]; /* derived name: the buffer's records */

/* This file's static initializer (0x87e60): the vertex data's reflection
 * (no parent, eleven members, version 2) and type info (no vtable), then
 * hkxVertexBuffer's over hkReferencedObject's (two members, version 1) and
 * type info. */
const hkClass D_57c6920("hkxVertexBufferVertexData", 0, sizeof(hkxVertexBuffer::VertexData), 0, 0,
                        0, 0, D_16a1050, 11, 0, 0, 0, 2);
extern const hkTypeInfo D_57c6970;
const hkTypeInfo D_57c6970("hkxVertexBufferVertexData", "!hkxVertexBuffer::VertexData",
                           finishLoadedObjecthkxVertexBufferVertexData,
                           cleanupLoadedObjecthkxVertexBufferVertexData, 0,
                           sizeof(hkxVertexBuffer::VertexData));
const hkClass D_57c69a0("hkxVertexBuffer", &D_57b8640, sizeof(hkxVertexBuffer), 0, 0, 0, 0,
                        D_16a1210, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57c69f0;
const hkTypeInfo D_57c69f0("hkxVertexBuffer", "!hkxVertexBuffer", finishLoadedObjecthkxVertexBuffer,
                           cleanupLoadedObjecthkxVertexBuffer, vtableOfhkxVertexBuffer(),
                           sizeof(hkxVertexBuffer));
