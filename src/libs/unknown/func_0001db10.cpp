/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The block header's cleanup and the PVS's finish: nothing to do (the
 * linker folded both into the empty body 0x1c1e0). */
void FUN_0001c1e0(void *object, int finishing) {}

void FUN_0001c1e0(void *object) {}

/* hkcdStaticPvs's cleanup callback (func_0001db00.cpp): its destructor. */
void FUN_0001db00(void *object); /* derived name */

/* This file's static initializer (0x1db10): hkcdStaticPvs::BlockHeader's
 * reflection (no parent, its two members) and type info, then
 * hkcdStaticPvs's (its six members), neither with a vtable. The type
 * infos' names are the base's strings. */
const hkClass D_57ba510("hkcdStaticPvsBlockHeader", 0, sizeof(hkcdStaticPvsBlockHeader), 0, 0, 0, 0,
                        D_168f9f0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba560;
const hkTypeInfo D_57ba560("hkcdStaticPvsBlockHeader", "!hkcdStaticPvs::BlockHeader", 0,
                           FUN_0001c1e0, 0, sizeof(hkcdStaticPvsBlockHeader));
const hkClass D_57ba590("hkcdStaticPvs", 0, sizeof(hkcdStaticPvs), 0, 0, 0, 0, D_168fa40, 6, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57ba5e0;
const hkTypeInfo D_57ba5e0("hkcdStaticPvs", "!hkcdStaticPvs", FUN_0001c1e0, FUN_0001db00, 0,
                           sizeof(hkcdStaticPvs));
