/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpShapeInstance's finish callback: nothing to finish (the linker folded
 * it into the shared empty body 0x3b640, FUN_0003b640). */
void FUN_0003b640(void *object, int finishing) {}

/* This file's static initializer (0x3cb00): hknpShapeInstance's reflection
 * (hkClass 0x57bfe90: no parent, its one enum and six members, version 1),
 * then its type info (the cleanup callback 0x3caa0, no vtable). */
const hkClass D_57bfe90("hknpShapeInstance", 0, sizeof(hknpShapeInstance), 0, 0, D_16960b0, 1,
                        D_1695f50, 6, 0, 0, 0, 1);
extern const hkTypeInfo D_57bfee0;
const hkTypeInfo D_57bfee0("hknpShapeInstance", "!hknpShapeInstance", FUN_0003b640,
                           hknpShapeInstance::FUN_0003caa0, 0, sizeof(hknpShapeInstance));
