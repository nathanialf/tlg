/* src/game/unknown/: game-region data (0x1a3e00 and up; docs/TARGETS.md) whose translation unit is not known. */
#include <float.h>

#include "tlg_math.h"

/* derived names: the constants of tlg_math.h, constant-initialised. No
 * function of the executable reads them: every copy was folded at the link,
 * and no copy of them is placed. */
const Float4Data FLOAT4_POINT_MIN = {-FLT_MAX, -FLT_MAX, -FLT_MAX, 1.0f};
const Float4Data FLOAT4_POINT_MAX = {FLT_MAX, FLT_MAX, FLT_MAX, 1.0f};
const Float4Data FLOAT4_POINT_ORIGIN = {0.0f, 0.0f, 0.0f, 1.0f};
const Float4Data FLOAT4_ONE = {1.0f, 1.0f, 1.0f, 1.0f};
const float FLOAT_ONE = 1.0f;
const Float4Data FLOAT4_X = {1.0f, 0.0f, 0.0f, 0.0f};
