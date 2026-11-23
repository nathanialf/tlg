/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: a set of parameters, each present where its bit of the
 * mask at +0x30 is set: eight scalars, two vectors, three scalars and two
 * vectors, in bit order; used when bit 0 of +0x24 is set */
struct ParamSource00d11230 { /* derived name */
    u8 unknown0[0x24];
    u8 flags; /* +0x24 */
    u8 unknown25[0xb];
    u32 mask;         /* +0x30 */
    float scalars[8]; /* +0x34 */
    u8 unknown54[0xc];
    Vec4 vectors[2];   /* +0x60 */
    float scalars2[3]; /* +0x80 */
    u8 unknown8c[0x4];
    Vec4 vectors2[2]; /* +0x90 */
};

/* derived names: the same parameters gathered, the mask of those set at +0x0 */
struct ParamSet00d11230 { /* derived name */
    u32 mask;             /* +0x0 */
    float scalars[8];     /* +0x4 */
    u8 unknown24[0xc];
    Vec4 vectors[2];   /* +0x30 */
    float scalars2[3]; /* +0x50 */
    u8 unknown5c[0x4];
    Vec4 vectors2[2]; /* +0x60 */
};

/* derived name: copies the parameters the source sets into the set and
 * adds their bits to its mask (called by FUN_00d11480) */
void FUN_00d11230(const ParamSource00d11230 *source, ParamSet00d11230 *set) /* derived name */
{
    if (!(source->flags & 1))
        return;
    for (int i = 0; i < 8; ++i)
        if (source->mask & (1u << i))
            set->scalars[i] = source->scalars[i];
    for (int i = 0; i < 2; ++i)
        if (source->mask & (0x100u << i))
            set->vectors[i] = source->vectors[i];
    for (int i = 0; i < 3; ++i)
        if (source->mask & (0x400u << i))
            set->scalars2[i] = source->scalars2[i];
    for (int i = 0; i < 2; ++i)
        if (source->mask & (0x2000u << i))
            set->vectors2[i] = source->vectors2[i];
    set->mask |= source->mask;
}
