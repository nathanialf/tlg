/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the item's finish and cleanup folded by the linker into 0xd520 and
 * 0x330 (the name at +8 finished, destroyed); the enum's and the sparsely
 * animated enum's finishes kept beside the initializer (0x898f0, 0x89920),
 * their cleanups folded into 0x2d0. */
static void finishLoadedObjecthkxEnumItem(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxEnumItem(flag);
}

static void cleanupLoadedObjecthkxEnumItem(void *object)
{
    static_cast<hkxEnumItem *>(object)->~hkxEnumItem();
}

static void finishLoadedObjecthkxEnum(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxEnum(flag);
}

static void cleanupLoadedObjecthkxEnum(void *object)
{
    static_cast<hkxEnum *>(object)->~hkxEnum();
}

static void finishLoadedObjecthkxSparselyAnimatedEnum(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxSparselyAnimatedEnum(flag);
}

static void cleanupLoadedObjecthkxSparselyAnimatedEnum(void *object)
{
    static_cast<hkxSparselyAnimatedEnum *>(object)->~hkxSparselyAnimatedEnum();
}

/* The address of each class's vtable, read from an object finished in a
 * buffer (folded to the address point). derived names. */
static const void *vtableOfhkxEnum()
{
    union {
        void *vtable;
        char buffer[sizeof(hkxEnum)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxEnum(flag);
    return object.vtable;
}

static const void *vtableOfhkxSparselyAnimatedEnum()
{
    union {
        void *vtable;
        char buffer[sizeof(hkxSparselyAnimatedEnum)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxSparselyAnimatedEnum(flag);
    return object.vtable;
}

extern const hkClass D_57b8640; /* derived name: hkReferencedObject's hkClass */
extern const hkClass D_57c6c68; /* hkxSparselyAnimatedInt's hkClass */
extern const hkClass D_57c6fc0;
extern const hkClass D_57c7040;

/* The three classes' member records, file-local (D17); the rows are
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_16a1730[2] = {
#include "gen/D_16a1730.inc"
};
static const hkClassMember D_16a1780[1] = {
#include "gen/D_16a1780.inc"
};
static const hkClassMember D_16a17b0[1] = {
#include "gen/D_16a17b0.inc"
};

/* This file's static initializer (0x89940): hkxEnum::Item's reflection
 * (value and name) and type info (no vtable), hkxEnum's over
 * hkReferencedObject's (its items), then hkxSparselyAnimatedEnum's over
 * hkxSparselyAnimatedInt's (its enum, version 1), with their type infos. */
const hkClass D_57c6fc0("hkxEnumItem", 0, sizeof(hkxEnumItem), 0, 0, 0, 0, D_16a1730, 2, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c7010;
const hkTypeInfo D_57c7010("hkxEnumItem", "!hkxEnum::Item", finishLoadedObjecthkxEnumItem,
                           cleanupLoadedObjecthkxEnumItem, 0, sizeof(hkxEnumItem));
const hkClass D_57c7040("hkxEnum", &D_57b8640, sizeof(hkxEnum), 0, 0, 0, 0, D_16a1780, 1, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c7090;
const hkTypeInfo D_57c7090("hkxEnum", "!hkxEnum", finishLoadedObjecthkxEnum,
                           cleanupLoadedObjecthkxEnum, vtableOfhkxEnum(), sizeof(hkxEnum));
extern const hkClass D_57c70c0;
const hkClass D_57c70c0("hkxSparselyAnimatedEnum", &D_57c6c68, sizeof(hkxSparselyAnimatedEnum), 0,
                        0, 0, 0, D_16a17b0, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7110;
const hkTypeInfo D_57c7110("hkxSparselyAnimatedEnum", "!hkxSparselyAnimatedEnum",
                           finishLoadedObjecthkxSparselyAnimatedEnum,
                           cleanupLoadedObjecthkxSparselyAnimatedEnum,
                           vtableOfhkxSparselyAnimatedEnum(), sizeof(hkxSparselyAnimatedEnum));
