/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the internals'
 * finish kept at 0x33fb0 (its finish constructor inline over the static
 * compound shape's, 0x385d0), the key mask's at 0x34000; both cleanups
 * folded by the linker into 0x2d0. */
static void finishLoadedObjecthknpStaticCompoundShapeInternals(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpStaticCompoundShapeInternals(flag);
}

static void cleanupLoadedObjecthknpStaticCompoundShapeInternals(void *object)
{
    static_cast<hknpStaticCompoundShapeInternals *>(object)->~hknpStaticCompoundShapeInternals();
}

static void finishLoadedObjecthknpStaticCompoundShapeKeyMask(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpStaticCompoundShapeKeyMask(flag);
}

static void cleanupLoadedObjecthknpStaticCompoundShapeKeyMask(void *object)
{
    static_cast<hknpStaticCompoundShapeKeyMask *>(object)->~hknpStaticCompoundShapeKeyMask();
}

/* The addresses of the two vtables, each read from an object finished in a
 * buffer (the internals' through the static compound shape's out-of-line
 * finish constructor, 0x385d0). derived names. */
static const void *vtableOfhknpStaticCompoundShapeInternals()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpStaticCompoundShapeInternals)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpStaticCompoundShapeInternals(flag);
    return object.vtable;
}

static const void *vtableOfhknpStaticCompoundShapeKeyMask()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpStaticCompoundShapeKeyMask)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpStaticCompoundShapeKeyMask(flag);
    return object.vtable;
}

/* The compound shape internals' key mask's hkClass (built at 0x34508 under
 * "hknpCompoundShapeInternalsKeyMask"). */
extern const hkClass D_57bdf20;

/* This file's static initializer (0x34020): hknpStaticCompoundShapeInternals'
 * reflection over the static compound shape's (no members) and type info,
 * then hknpStaticCompoundShapeKeyMask's over the internals' key mask's and
 * type info. */
const hkClass D_57bde20("hknpStaticCompoundShapeInternals", &D_57c27c8,
                        sizeof(hknpStaticCompoundShapeInternals), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57bde70;
const hkTypeInfo D_57bde70("hknpStaticCompoundShapeInternals", "!hknpStaticCompoundShapeInternals",
                           finishLoadedObjecthknpStaticCompoundShapeInternals,
                           cleanupLoadedObjecthknpStaticCompoundShapeInternals,
                           vtableOfhknpStaticCompoundShapeInternals(),
                           sizeof(hknpStaticCompoundShapeInternals));
const hkClass D_57bdea0("hknpStaticCompoundShapeKeyMask", &D_57bdf20,
                        sizeof(hknpStaticCompoundShapeKeyMask), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57bdef0;
const hkTypeInfo D_57bdef0("hknpStaticCompoundShapeKeyMask", "!hknpStaticCompoundShapeKeyMask",
                           finishLoadedObjecthknpStaticCompoundShapeKeyMask,
                           cleanupLoadedObjecthknpStaticCompoundShapeKeyMask,
                           vtableOfhknpStaticCompoundShapeKeyMask(),
                           sizeof(hknpStaticCompoundShapeKeyMask));
