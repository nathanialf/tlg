/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The mass distribution's finish and cleanup callbacks: the empty body the
 * linker folded (func_0003cb00.cpp, func_0003e5b0.cpp). hknpRefMassDistribution's finish callback
 * (func_00069a80.cpp) and cleanup callback (the virtual destructor, the
 * shared body 0x2d0). */
void FUN_0003b640(void *object, int finishing);
void FUN_0003b640(void *object);
void FUN_00069a80(void *object, int finishing);
void FUN_000002d0(void *object);

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
const hkTypeInfo D_57c2548("hknpMassDistribution", "!hknpMassDistribution", FUN_0003b640,
                           FUN_0003b640, 0, sizeof(hknpMassDistribution));
const hkClass D_57c2578("hknpRefMassDistribution", &D_57b8640, sizeof(hknpRefMassDistribution), 0,
                        0, 0, 0, D_169a8e0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c25c8;
const hkTypeInfo D_57c25c8("hknpRefMassDistribution", "!hknpRefMassDistribution", FUN_00069a80,
                           FUN_000002d0, vtableOfhknpRefMassDistribution(),
                           sizeof(hknpRefMassDistribution));
