/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the finishes are
 * kept at 0x3a3b0 and 0x3a3d0 beside the initializer, the cleanups folded
 * by the linker into the shared virtual destructor call 0x2d0. */
static void finishLoadedObjecthknpGroupCollisionFilter(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpGroupCollisionFilter(flag);
}

static void cleanupLoadedObjecthknpGroupCollisionFilter(void *object)
{
    static_cast<hknpGroupCollisionFilter *>(object)->~hknpGroupCollisionFilter();
}

static void finishLoadedObjecthknpGroupCollisionFilterBase(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516(flag);
}

static void cleanupLoadedObjecthknpGroupCollisionFilterBase(void *object)
{
    static_cast<hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516 *>(object)
        ->~hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516();
}

/* The address of each class's vtable, read from an object finished in a
 * buffer (folded to the address point). derived names. */
static const void *vtableOfhknpGroupCollisionFilter()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpGroupCollisionFilter)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpGroupCollisionFilter(flag);
    return object.vtable;
}

static const void *vtableOfhknpGroupCollisionFilterBase()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516)]
            __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516(flag);
    return object.vtable;
}

extern const hkClassMember D_1695300[]; /* derived name: the filter base's records */

/* This file's static initializer (0x3a3f0): hknpGroupCollisionFilter's
 * reflection over its base's (no members, version 2) and type info, then
 * the base's reflection over hknpCollisionFilter's (two members) and type
 * info. */
extern const hkClass D_57bf9a0;
const hkClass D_57bf950("hknpGroupCollisionFilter", &D_57bf9a0, sizeof(hknpGroupCollisionFilter), 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 2);
extern const hkTypeInfo D_57bf9f0;
const hkTypeInfo D_57bf9f0("hknpGroupCollisionFilter", "!hknpGroupCollisionFilter",
                           finishLoadedObjecthknpGroupCollisionFilter,
                           cleanupLoadedObjecthknpGroupCollisionFilter,
                           vtableOfhknpGroupCollisionFilter(), sizeof(hknpGroupCollisionFilter));
const hkClass
    D_57bf9a0("hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516", &D_57c0cb0,
              sizeof(hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516), 0, 0, 0,
              0, D_1695300, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57bfa20;
const hkTypeInfo
    D_57bfa20("hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516",
              "!hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516_typename",
              finishLoadedObjecthknpGroupCollisionFilterBase,
              cleanupLoadedObjecthknpGroupCollisionFilterBase,
              vtableOfhknpGroupCollisionFilterBase(),
              sizeof(hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516));
