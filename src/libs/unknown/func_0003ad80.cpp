/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

extern const hkClass D_57b8640; /* derived name: hkReferencedObject's hkClass */

/* The action's enum with its items and the four classes' member records,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). */
static const hkClassEnum::Item D_16957c0[2] = {
#include "gen/D_16957c0.inc"
};
static const hkClassEnum D_16957e0[1] = {
#include "gen/D_16957e0.inc"
};
static const hkClassMember D_16956e0[1] = {
#include "gen/D_16956e0.inc"
};
static const hkClassMember D_1695710[1] = {
#include "gen/D_1695710.inc"
};
static const hkClassMember D_1695740[2] = {
#include "gen/D_1695740.inc"
};
static const hkClassMember D_1695790[1] = {
#include "gen/D_1695790.inc"
};

/* This file's static initializer (0x3ad80): the reflection of hknpAction
 * (its Result enum, userData) over hkReferencedObject's, then of the array,
 * binary and unary actions over it. */
const hkClass D_57bfad0("hknpAction", &D_57b8640, sizeof(hknpAction), 0, 0, D_16957e0, 1, D_16956e0,
                        1, 0, 0, 0, 0);
const hkClass D_57bfb20("hknpArrayAction", &D_57bfad0, sizeof(hknpArrayAction), 0, 0, 0, 0,
                        D_1695710, 1, 0, 0, 0, 0);
const hkClass D_57bfb70("hknpBinaryAction", &D_57bfad0, sizeof(hknpBinaryAction), 0, 0, 0, 0,
                        D_1695740, 2, 0, 0, 0, 1);
const hkClass D_57bfbc0("hknpUnaryAction", &D_57bfad0, sizeof(hknpUnaryAction), 0, 0, 0, 0,
                        D_1695790, 1, 0, 0, 0, 1);
