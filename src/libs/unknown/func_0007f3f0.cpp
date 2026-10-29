/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The defaults of its members: userData's offset -2, a default of zero
 * (derived reading). */
static const int D_14c0b68[1] = {-2};

/* hkpConstraintData's reflection (this file's static initializer,
 * 0x7f3f0): hkReferencedObject's as the parent, its one enum, its one
 * member and its defaults, the object's size. */
const hkClass D_57c45a8("hkpConstraintData", &D_57b8640, sizeof(hkpConstraintData), 0, 0, D_169d860,
                        1, D_169d660, 1, D_14c0b68, 0, 0, 0);
