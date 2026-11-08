/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the group's and the simple frame's finishes kept beside the
 * initializer (0x37b0, 0x37f0), their cleanups folded by the linker into
 * 0x2d0. */
static void finishLoadedObjecthkLocalFrameGroup(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkLocalFrameGroup(flag);
}

static void cleanupLoadedObjecthkLocalFrameGroup(void *object)
{
    static_cast<hkLocalFrameGroup *>(object)->~hkLocalFrameGroup();
}

static void finishLoadedObjecthkSimpleLocalFrame(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkSimpleLocalFrame(flag);
}

static void cleanupLoadedObjecthkSimpleLocalFrame(void *object)
{
    static_cast<hkSimpleLocalFrame *>(object)->~hkSimpleLocalFrame();
}

/* The address of each class's vtable, read from an object finished in a
 * buffer (folded to the address point). derived names. */
static const void *vtableOfhkLocalFrameGroup()
{
    union {
        void *vtable;
        char buffer[sizeof(hkLocalFrameGroup)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkLocalFrameGroup(flag);
    return object.vtable;
}

static const void *vtableOfhkSimpleLocalFrame()
{
    union {
        void *vtable;
        char buffer[sizeof(hkSimpleLocalFrame)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkSimpleLocalFrame(flag);
    return object.vtable;
}

extern const hkClass D_57b76a0;
extern const hkClass D_57b76f0;

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_168c7a0[1] = {
#include "gen/D_168c7a0.inc"
};
static const hkClassMember D_168c7d0[5] = {
#include "gen/D_168c7d0.inc"
};

/* This file's static initializer (0x3820): hkLocalFrame's reflection (no
 * members, no type info), then the group's and the simple frame's with
 * their type infos, the simple frame's over hkLocalFrame's. */
const hkClass D_57b76a0("hkLocalFrame", &D_57b8640, sizeof(hkLocalFrame), 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0);
const hkClass D_57b76f0("hkLocalFrameGroup", &D_57b8640, sizeof(hkLocalFrameGroup), 0, 0, 0, 0,
                        D_168c7a0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b7740;
const hkTypeInfo D_57b7740("hkLocalFrameGroup", "!hkLocalFrameGroup",
                           finishLoadedObjecthkLocalFrameGroup,
                           cleanupLoadedObjecthkLocalFrameGroup, vtableOfhkLocalFrameGroup(),
                           sizeof(hkLocalFrameGroup));
extern const hkClass D_57b7770;
const hkClass D_57b7770("hkSimpleLocalFrame", &D_57b76a0, sizeof(hkSimpleLocalFrame), 0, 0, 0, 0,
                        D_168c7d0, 5, 0, 0, 0, 1);
extern const hkTypeInfo D_57b77c0;
const hkTypeInfo D_57b77c0("hkSimpleLocalFrame", "!hkSimpleLocalFrame",
                           finishLoadedObjecthkSimpleLocalFrame,
                           cleanupLoadedObjecthkSimpleLocalFrame, vtableOfhkSimpleLocalFrame(),
                           sizeof(hkSimpleLocalFrame));
