/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <stddef.h>

#include "tlg_hk_reflect.h"

/* hknpMotionProperties's loaded-object cleanup: nothing to clean up (the
 * linker folded it into the empty body 0x1c1e0, FUN_0001c1e0). */
void FUN_0001c1e0(void *object) {}

/* The defaults of its members (derived names): an offset into this block
 * per member, -1 for none and -2 for zero (derived reading), then the three
 * values, gravityFactor, timeFactor and solverStabilizationSpeedThreshold,
 * each one. */
struct hknpMotionPropertiesDefaults /* derived name */
{
    int defaultOffsets[20];
    float gravityFactor;
    float timeFactor;
    float solverStabilizationSpeedThreshold;
};

static const hknpMotionPropertiesDefaults D_14ba280 = {
    {-1,
     -1,
     offsetof(hknpMotionPropertiesDefaults, gravityFactor),
     offsetof(hknpMotionPropertiesDefaults, timeFactor),
     -1,
     -1,
     -2,
     -2,
     offsetof(hknpMotionPropertiesDefaults, solverStabilizationSpeedThreshold),
     -2,
     -1,
     -1,
     -1,
     -1,
     -1,
     -1,
     -1,
     -1,
     -1,
     -1},
    1.0f,
    1.0f,
    1.0f};

/* This file's static initializer (0x395e0): hknpMotionProperties's
 * reflection, no parent, its two enums, its twenty members and their
 * defaults, version 3, then its type info (the finish callback
 * FUN_000395c0, no vtable). */
const hkClass D_57bf4c0("hknpMotionProperties", 0, sizeof(hknpMotionProperties), 0, 0, D_1694c40, 2,
                        D_16948a0, 20, &D_14ba280, 0, 0, 3);
extern const hkTypeInfo D_57bf510;
const hkTypeInfo D_57bf510("hknpMotionProperties", "!hknpMotionProperties", FUN_000395c0,
                           FUN_0001c1e0, 0, sizeof(hknpMotionProperties));
