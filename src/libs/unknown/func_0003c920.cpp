/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The two enumerations' loaded-object cleanups: nothing to clean up in
 * either class. Each registration passes its class's own callback; the
 * linker folded both into the empty body 0x3b640, so the first is spelled
 * under the address's own name (D15's round 57 addendum) and the second
 * under that name with its class appended (D15's round 68A addendum). */
void FUN_0003b640(void *object) {}

void FUN_0003b640_hknpShapeType(void *object) {}

/* This file's static initializer (0x3c920): hknpCollisionDispatchType's
 * reflection (no parent, its one enum, no members) and type info, then
 * hknpShapeType's, neither with a finish callback or a vtable. The type
 * infos' names are the base's strings. */
const hkClass D_57bfd90("hknpCollisionDispatchType", 0, sizeof(hknpCollisionDispatchType), 0, 0,
                        D_1695f20, 1, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57bfde0;
const hkTypeInfo D_57bfde0("hknpCollisionDispatchType", "!hknpCollisionDispatchType", 0,
                           FUN_0003b640, 0, sizeof(hknpCollisionDispatchType));
const hkClass D_57bfe10("hknpShapeType", 0, sizeof(hknpShapeType), 0, 0, D_1695e90, 1, 0, 0, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57bfe60;
const hkTypeInfo D_57bfe60("hknpShapeType", "!hknpShapeType", 0, FUN_0003b640_hknpShapeType, 0,
                           sizeof(hknpShapeType));
