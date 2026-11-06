/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpRefMassDistribution's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthknpRefMassDistribution(void *object,
                                                      int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpRefMassDistribution(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpRefMassDistribution(void *object) /* derived name */
{
    static_cast<hknpRefMassDistribution *>(object)->~hknpRefMassDistribution();
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void finishLoadedObjecthknpMassDistribution(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMassDistribution(flag);
}

static void cleanupLoadedObjecthknpMassDistribution(void *object) /* derived name */
{
    static_cast<hknpMassDistribution *>(object)->~hknpMassDistribution();
}

extern const hkClassMember D_169a860[]; /* derived name: the mass distribution's records */
extern const hkClassMember D_169a8e0[]; /* derived name: the counted one's record */

/* The address of hknpRefMassDistribution's vtable, read from an object
 * finished in a buffer (folded to the address point). */
static const void *vtableOfhknpRefMassDistribution() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpRefMassDistribution)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpRefMassDistribution(flag);
    return object.vtable;
}

/* This file's static initializer (0x69aa0): the mass distribution's
 * reflection (no parent, three members) and type info, then
 * hknpRefMassDistribution's over hkReferencedObject's (its one member) and
 * type info with its vtable. The type infos' names are the base's
 * strings. */
const hkClass D_57c24f8("hknpMassDistribution", 0, sizeof(hknpMassDistribution), 0, 0, 0, 0,
                        D_169a860, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c2548;
const hkTypeInfo D_57c2548("hknpMassDistribution", "!hknpMassDistribution",
                           finishLoadedObjecthknpMassDistribution,
                           cleanupLoadedObjecthknpMassDistribution, 0,
                           sizeof(hknpMassDistribution));
const hkClass D_57c2578("hknpRefMassDistribution", &D_57b8640, sizeof(hknpRefMassDistribution), 0,
                        0, 0, 0, D_169a8e0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c25c8;
const hkTypeInfo D_57c25c8("hknpRefMassDistribution", "!hknpRefMassDistribution",
                           finishLoadedObjecthknpRefMassDistribution,
                           cleanupLoadedObjecthknpRefMassDistribution,
                           vtableOfhknpRefMassDistribution(), sizeof(hknpRefMassDistribution));
