/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpBodyCinfo's members' defaults, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hknpBodyCinfoDefaults D_14b97d4[1] = {
#include "gen/D_14b97d4.inc"
};

/* This file's static initializer (0x38330): hknpBodyCinfo's reflection
 * (hkClass 0x57beda8: no parent, its nineteen members and their defaults,
 * version 4), then its type info (the finish callback 0x38250 and the
 * cleanup 0x38260, no vtable). */
const hkClass D_57beda8("hknpBodyCinfo", 0, sizeof(hknpBodyCinfo), 0, 0, 0, 0, D_1693bf0, 19,
                        D_14b97d4, 0, 0, 4);
extern const hkTypeInfo D_57bedf8;
const hkTypeInfo D_57bedf8("hknpBodyCinfo", "!hknpBodyCinfo", FUN_00038250, FUN_00038260, 0,
                           sizeof(hknpBodyCinfo));
