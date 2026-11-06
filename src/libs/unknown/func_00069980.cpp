/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hknpShapeSignals's type info
 * (0x57c24c8): destroys the struct in place, its signals in the reverse of
 * their order through their out-of-line destructor. */
static void cleanupLoadedObjecthknpShapeSignals(void *object) /* derived name */
{
    static_cast<hknpShapeSignals *>(object)->~hknpShapeSignals();
}

/* This file's static initializer (0x69980): hknpShapeSignals's reflection
 * (hkClass 0x57c2478: no parent, its one enum and two members), then its
 * type info (the cleanup callback 0x69960, no finish callback, no vtable). */
const hkClass D_57c2478("hknpShapeSignals", 0, sizeof(hknpShapeSignals), 0, 0, D_169a7f0, 1,
                        D_169a770, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c24c8;
const hkTypeInfo D_57c24c8("hknpShapeSignals", "!hknpShapeSignals", 0,
                           cleanupLoadedObjecthknpShapeSignals, 0, sizeof(hknpShapeSignals));
