/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpMotionCinfo's loaded-object cleanup: nothing to clean up (the linker
 * folded it into the shared empty body 0x3b640, FUN_0003b640). */
void FUN_0003b640(void *object) {}

/* hknpMotionCinfo's members' defaults, file-local (D17); the rows are
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hknpMotionCinfoDefaults D_14bb668[1] = {
#include "gen/D_14bb668.inc"
};

/* This file's static initializer (0x3f2b0): hknpMotionCinfo's reflection
 * (hkClass 0x57c09e8: no parent, its ten members and their defaults,
 * version 2), then its type info (no finish callback, no vtable). */
const hkClass D_57c09e8("hknpMotionCinfo", 0, sizeof(hknpMotionCinfo), 0, 0, 0, 0, D_1696b00, 10,
                        D_14bb668, 0, 0, 2);
extern const hkTypeInfo D_57c0a38;
const hkTypeInfo D_57c0a38("hknpMotionCinfo", "!hknpMotionCinfo", 0, FUN_0003b640, 0,
                           sizeof(hknpMotionCinfo));
