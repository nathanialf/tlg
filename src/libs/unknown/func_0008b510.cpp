/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkxNode's finish constructor (0x8b4b0): the two strings and the uuid
 * finished, the arrays left as loaded, and the vtable set. */
hkxNode::hkxNode(hkFinishLoadedObjectFlag flag)
    : hkxAttributeHolder(flag), name(flag), uuid(flag), object(flag), keyFrames(flag),
      children(flag), annotations(flag), linearKeyFrameHints(flag), userProperties(flag)
{
}

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the annotation's finish and cleanup folded by the linker into
 * 0xd520 and 0x330 (the string at +8 finished, destroyed); the node's
 * finish, the constructor above inlined, folded into the constructor
 * itself (0x8b4b0), its cleanup into 0x2d0. */
static void finishLoadedObjecthkxNodeAnnotationData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxNode::AnnotationData(flag);
}

static void cleanupLoadedObjecthkxNodeAnnotationData(void *object)
{
    static_cast<hkxNode::AnnotationData *>(object)->~AnnotationData();
}

static void finishLoadedObjecthkxNode(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxNode(flag);
}

static void cleanupLoadedObjecthkxNode(void *object)
{
    static_cast<hkxNode *>(object)->~hkxNode();
}

/* The address of the node's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkxNode()
{
    union {
        void *vtable;
        char buffer[sizeof(hkxNode)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxNode(flag);
    return object.vtable;
}

extern const hkClass D_57b7a00; /* derived name: hkUuid's hkClass */
extern const hkClass D_57c76b0; /* hkxAttributeHolder's hkClass */
extern const hkClass D_57c7730;
extern const hkClass D_57c77b0;

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_16a1fa0[2] = {
#include "gen/D_16a1fa0.inc"
};
static const hkClassMember D_16a1ff0[10] = {
#include "gen/D_16a1ff0.inc"
};

/* This file's static initializer (0x8b510): hkxNode::AnnotationData's
 * reflection (two members) and type info, then hkxNode's over
 * hkxAttributeHolder's (ten members, version 5) and type info. */
const hkClass D_57c7730("hkxNodeAnnotationData", 0, sizeof(hkxNode::AnnotationData), 0, 0, 0, 0,
                        D_16a1fa0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c7780;
const hkTypeInfo D_57c7780("hkxNodeAnnotationData", "!hkxNode::AnnotationData",
                           finishLoadedObjecthkxNodeAnnotationData,
                           cleanupLoadedObjecthkxNodeAnnotationData, 0,
                           sizeof(hkxNode::AnnotationData));
const hkClass D_57c77b0("hkxNode", &D_57c76b0, sizeof(hkxNode), 0, 0, 0, 0, D_16a1ff0, 10, 0, 0, 0,
                        5);
extern const hkTypeInfo D_57c7800;
const hkTypeInfo D_57c7800("hkxNode", "!hkxNode", finishLoadedObjecthkxNode,
                           cleanupLoadedObjecthkxNode, vtableOfhkxNode(), sizeof(hkxNode));
