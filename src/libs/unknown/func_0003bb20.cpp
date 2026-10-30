/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClass D_57bf1c0;         /* hknpShape's hkClass */
extern const hkClassMember D_1695a70[]; /* derived name: hknpDummyShape's records */

void FUN_0003bb00(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpDummyShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpDummyShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpDummyShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x3bb20): hknpDummyShape's reflection,
 * hknpShape's as the parent, its two members, then its type info (its
 * finish callback, the destructor, the vtable). */
const hkClass D_57bfd10("hknpDummyShape", &D_57bf1c0, sizeof(hknpDummyShape), 0, 0, 0, 0, D_1695a70,
                        2, 0, 0, 0, 0);
extern const hkTypeInfo D_57bfd60;
const hkTypeInfo D_57bfd60("hknpDummyShape", "!hknpDummyShape", FUN_0003bb00, FUN_000002d0,
                           vtableOfhknpDummyShape(), sizeof(hknpDummyShape));
