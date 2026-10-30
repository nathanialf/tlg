/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

extern const hkClassMember D_169b520[]; /* derived name: hknpCompoundShape's records */

/* This file's static initializer (0x77e60): hknpCompoundShape's reflection
 * over hknpCompositeShape's, its four members, version 2; then its key
 * mask's over hknpShapeKeyMask's, no members. */
const hkClass D_57c2e78("hknpCompoundShape", &D_57c2cf8, sizeof(hknpCompoundShape), 0, 0, 0, 0,
                        D_169b520, 4, 0, 0, 0, 2);
const hkClass D_57c2ec8("hknpCompoundShapeKeyMask", &D_57c1aa8, sizeof(hknpCompoundShapeKeyMask), 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0);
