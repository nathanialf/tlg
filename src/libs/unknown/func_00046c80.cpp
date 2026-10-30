/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpWorldCinfo's members' defaults, file-local (D17); the rows are written
 * at build time from the user's executable (D18, config/data_schema.base.txt). */
static const hknpWorldCinfoDefaults D_14bd370[1] = {
#include "gen/D_14bd370.inc"
};

/* This file's static initializer (0x46c80): hknpWorldCinfo's reflection, no
 * parent, its one enum, its 33 members and their defaults, version 6, then
 * its type info (its finish and cleanup callbacks, no vtable). */
const hkClass D_57c1390("hknpWorldCinfo", 0, sizeof(hknpWorldCinfo), 0, 0, D_1698770, 1, D_1698190,
                        33, D_14bd370, 0, 0, 6);
extern const hkTypeInfo D_57c13e0;
const hkTypeInfo D_57c13e0("hknpWorldCinfo", "!hknpWorldCinfo", FUN_00046c60, FUN_00046c70, 0,
                           sizeof(hknpWorldCinfo));
