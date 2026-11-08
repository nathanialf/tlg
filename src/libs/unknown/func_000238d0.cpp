/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the buffer constructed in place through its out-of-line finish
 * constructor (the finish callback kept at 0x238d0) and destroyed through
 * its virtual destructor (the folded 0x2d0); a vertex buffer info finished
 * by nothing and destroyed by its reference's release (both folded, into
 * the empty 0x1c1e0 and the properties entry's cleanup 0xd300); the
 * element infos destroyed by nothing. derived names. */
static void finishLoadedObjecthkMultipleVertexBufferVertexBufferInfo(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMultipleVertexBuffer::VertexBufferInfo(flag);
}

static void cleanupLoadedObjecthkMultipleVertexBufferVertexBufferInfo(void *object)
{
    static_cast<hkMultipleVertexBuffer::VertexBufferInfo *>(object)->~VertexBufferInfo();
}

static void cleanupLoadedObjecthkMultipleVertexBufferElementInfo(void *object)
{
    static_cast<hkMultipleVertexBuffer::ElementInfo *>(object)->~ElementInfo();
}

static void cleanupLoadedObjecthkMultipleVertexBufferLockedElement(void *object)
{
    static_cast<hkMultipleVertexBuffer::LockedElement *>(object)->~LockedElement();
}

static void finishLoadedObjecthkMultipleVertexBuffer(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_00024fa0(static_cast<hkMultipleVertexBuffer *>(object), flag);
}

static void cleanupLoadedObjecthkMultipleVertexBuffer(void *object)
{
    static_cast<hkMultipleVertexBuffer *>(object)->~hkMultipleVertexBuffer();
}

/* The address of hkMultipleVertexBuffer's vtable, read from an object
 * finished in a buffer by the out-of-line finish constructor. */
static const void *vtableOfhkMultipleVertexBuffer()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkMultipleVertexBuffer)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    FUN_00024fa0(reinterpret_cast<hkMultipleVertexBuffer *>(object.buffer), flag);
    return object.vtable;
}

extern const hkClass D_57bca60; /* hkMeshVertexBuffer's hkClass */

extern const hkClass D_57bcb30; /* hkVertexFormat's hkClass */
extern const hkClass D_57bdd98; /* the locked buffer's class */
extern const hkClass D_57bcda0;
extern const hkClass D_57bce20;
extern const hkClass D_57bcea0;

/* The member records, file-local (D17); the rows are written at build time
 * from the user's executable (D18, config/data_schema.base.txt). */
static const hkClassMember D_16917a0[3] = {
#include "gen/D_16917a0.inc"
};
static const hkClassMember D_16919e0[2] = {
#include "gen/D_16919e0.inc"
};
static const hkClassMember D_1691a30[7] = {
#include "gen/D_1691a30.inc"
};
static const hkClassMember D_1691820[11] = {
#include "gen/D_1691820.inc"
};

/* This file's static initializer (0x238f0): the three nested structs' and
 * hkMultipleVertexBuffer's classes (over hkMeshVertexBuffer's), each with
 * its type info. */
const hkClass D_57bcda0("hkMultipleVertexBufferVertexBufferInfo", 0,
                        sizeof(hkMultipleVertexBuffer::VertexBufferInfo), 0, 0, 0, 0, D_16917a0, 3,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57bcdf0;
const hkTypeInfo D_57bcdf0("hkMultipleVertexBufferVertexBufferInfo",
                           "!hkMultipleVertexBuffer::VertexBufferInfo",
                           finishLoadedObjecthkMultipleVertexBufferVertexBufferInfo,
                           cleanupLoadedObjecthkMultipleVertexBufferVertexBufferInfo, 0,
                           sizeof(hkMultipleVertexBuffer::VertexBufferInfo));
const hkClass D_57bce20("hkMultipleVertexBufferElementInfo", 0,
                        sizeof(hkMultipleVertexBuffer::ElementInfo), 0, 0, 0, 0, D_16919e0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57bce70;
const hkTypeInfo D_57bce70("hkMultipleVertexBufferElementInfo",
                           "!hkMultipleVertexBuffer::ElementInfo", 0,
                           cleanupLoadedObjecthkMultipleVertexBufferElementInfo, 0,
                           sizeof(hkMultipleVertexBuffer::ElementInfo));
const hkClass D_57bcea0("hkMultipleVertexBufferLockedElement", 0,
                        sizeof(hkMultipleVertexBuffer::LockedElement), 0, 0, 0, 0, D_1691a30, 7, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57bcef0;
const hkTypeInfo D_57bcef0("hkMultipleVertexBufferLockedElement",
                           "!hkMultipleVertexBuffer::LockedElement", 0,
                           cleanupLoadedObjecthkMultipleVertexBufferLockedElement, 0,
                           sizeof(hkMultipleVertexBuffer::LockedElement));
const hkClass D_57bcf20("hkMultipleVertexBuffer", &D_57bca60, sizeof(hkMultipleVertexBuffer), 0, 0,
                        0, 0, D_1691820, 11, 0, 0, 0, 0);
extern const hkTypeInfo D_57bcf70;
const hkTypeInfo D_57bcf70("hkMultipleVertexBuffer", "!hkMultipleVertexBuffer",
                           finishLoadedObjecthkMultipleVertexBuffer,
                           cleanupLoadedObjecthkMultipleVertexBuffer,
                           vtableOfhkMultipleVertexBuffer(), sizeof(hkMultipleVertexBuffer));
