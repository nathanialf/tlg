/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void finishLoadedObjecthknpShapeInstance(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpShapeInstance(flag);
}

/* derived names: the cleanup callback of hknpShapeInstance's type info:
 * destroy the instance in place, which releases its shape's reference. */
static void cleanupLoadedObjecthknpShapeInstance(void *object) /* derived name */
{
    static_cast<hknpShapeInstance *>(object)->~hknpShapeInstance();
}

/* This file's static initializer (0x3cb00): hknpShapeInstance's reflection
 * (hkClass 0x57bfe90: no parent, its one enum and six members, version 1),
 * then its type info (the cleanup callback 0x3caa0, no vtable). */
const hkClass D_57bfe90("hknpShapeInstance", 0, sizeof(hknpShapeInstance), 0, 0, D_16960b0, 1,
                        D_1695f50, 6, 0, 0, 0, 1);
extern const hkTypeInfo D_57bfee0;
const hkTypeInfo D_57bfee0("hknpShapeInstance", "!hknpShapeInstance",
                           finishLoadedObjecthknpShapeInstance,
                           cleanupLoadedObjecthknpShapeInstance, 0, sizeof(hknpShapeInstance));
