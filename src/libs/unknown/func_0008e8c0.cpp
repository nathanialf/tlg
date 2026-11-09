/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the container and the handle constructed in place through their
 * out-of-line finish constructors (kept, at 0x8e820 and 0x8e870) and
 * destroyed through their virtual destructors (the body the linker folded,
 * 0x2d0); the external link finished and destroyed in place (folded with
 * hkxEnvironment::Variable's, 0x8d9e0 and 0x8da10). derived names. */
static void finishLoadedObjecthkMemoryResourceContainer(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryResourceContainer(flag);
}

static void cleanupLoadedObjecthkMemoryResourceContainer(void *object)
{
    static_cast<hkMemoryResourceContainer *>(object)->~hkMemoryResourceContainer();
}

static void finishLoadedObjecthkMemoryResourceHandleExternalLink(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryResourceHandleExternalLink(flag);
}

static void cleanupLoadedObjecthkMemoryResourceHandleExternalLink(void *object)
{
    static_cast<hkMemoryResourceHandleExternalLink *>(object)
        ->~hkMemoryResourceHandleExternalLink();
}

static void finishLoadedObjecthkMemoryResourceHandle(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryResourceHandle(flag);
}

static void cleanupLoadedObjecthkMemoryResourceHandle(void *object)
{
    static_cast<hkMemoryResourceHandle *>(object)->~hkMemoryResourceHandle();
}

/* The vtables' addresses, read from objects finished in a buffer on the
 * stack through the out-of-line finish constructors (0x17fb60, 0x17f110).
 * derived names. */
static const void *vtableOfhkMemoryResourceContainer()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkMemoryResourceContainer)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkMemoryResourceContainer(flag);
    return object.vtable;
}

static const void *vtableOfhkMemoryResourceHandle()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkMemoryResourceHandle)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkMemoryResourceHandle(flag);
    return object.vtable;
}

extern const hkClass D_57c84b0;
extern const hkClass D_57c8500;
extern const hkClass D_57c8550;
extern const hkClass D_57c85d0;
extern const hkClass D_57c8650;
extern const hkClass D_57c86d0;

/* The handle's three member records, another file's: its address through
 * the GOT puts the external link's lea group in the base's registers
 * (cookbook 481; defined here, 151 of 160). derived name. */
extern const hkClassMember D_16a30b0[];

/* The container's four member records, the external link's two,
 * hkResourceBase's one enum and its two items, file-local (D17); the rows
 * are written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkClassMember D_16a3010[4] = {
#include "gen/D_16a3010.inc"
};
static const hkClassMember D_16a3130[2] = {
#include "gen/D_16a3130.inc"
};
static const hkClassEnum::Item D_16a3180[2] = {
#include "gen/D_16a3180.inc"
};
static const hkClassEnum D_16a31a0[1] = {
#include "gen/D_16a31a0.inc"
};

/* This file's static initializer (0x8e8c0): the container's reflection over
 * hkResourceContainer's (four members, version 1) and type info, the
 * external link's (two members, version 1) and type info, the handle's over
 * hkResourceHandle's (three members, version 3) and type info, then the
 * three bases': hkResourceBase over hkReferencedObject's with its one enum,
 * hkResourceContainer and hkResourceHandle over hkResourceBase's. */
const hkClass D_57c84b0("hkMemoryResourceContainer", &D_57c8550, sizeof(hkMemoryResourceContainer),
                        0, 0, 0, 0, D_16a3010, 4, 0, 0, 0, 1);
extern const hkTypeInfo D_57c85a0;
const hkTypeInfo D_57c85a0("hkMemoryResourceContainer", "!hkMemoryResourceContainer",
                           finishLoadedObjecthkMemoryResourceContainer,
                           cleanupLoadedObjecthkMemoryResourceContainer,
                           vtableOfhkMemoryResourceContainer(), sizeof(hkMemoryResourceContainer));
const hkClass D_57c85d0("hkMemoryResourceHandleExternalLink", 0,
                        sizeof(hkMemoryResourceHandleExternalLink), 0, 0, 0, 0, D_16a3130, 2, 0, 0,
                        0, 1);
extern const hkTypeInfo D_57c8620;
const hkTypeInfo D_57c8620("hkMemoryResourceHandleExternalLink",
                           "!hkMemoryResourceHandle::ExternalLink",
                           finishLoadedObjecthkMemoryResourceHandleExternalLink,
                           cleanupLoadedObjecthkMemoryResourceHandleExternalLink, 0,
                           sizeof(hkMemoryResourceHandleExternalLink));
const hkClass D_57c8500("hkMemoryResourceHandle", &D_57c8650, sizeof(hkMemoryResourceHandle), 0, 0,
                        0, 0, D_16a30b0, 3, 0, 0, 0, 3);
extern const hkTypeInfo D_57c86a0;
const hkTypeInfo D_57c86a0("hkMemoryResourceHandle", "!hkMemoryResourceHandle",
                           finishLoadedObjecthkMemoryResourceHandle,
                           cleanupLoadedObjecthkMemoryResourceHandle,
                           vtableOfhkMemoryResourceHandle(), sizeof(hkMemoryResourceHandle));
const hkClass D_57c86d0("hkResourceBase", &D_57b8640, sizeof(hkResourceBase), 0, 0, D_16a31a0, 1, 0,
                        0, 0, 0, 0, 0);
const hkClass D_57c8550("hkResourceContainer", &D_57c86d0, sizeof(hkResourceContainer), 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0);
const hkClass D_57c8650("hkResourceHandle", &D_57c86d0, sizeof(hkResourceHandle), 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0);
