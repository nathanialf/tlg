/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the size of a surface's level and of n of them: refuses a
 * null record with 0x80d30000, fills a 0x30-byte parameter block from the
 * record and the level (FUN_001adf20), clears a 0x38-byte result, refuses a
 * level past the last one (bits 13 to 23 of +0x20), measures the surface
 * (FUN_001a44e0, its result not read) and stores the level count times the
 * size (+0x10 of the result) and the size; returns 0. FUN_001aecb0
 * is the same over FUN_001ae0b0's record, FUN_001aeb10 over FUN_001add40's
 * with the levels at +0xc. */
struct SurfaceParams001aebe0 { /* derived name: twelve words, not traced */
    u32 unknown0;
    u32 unknown4;
    u32 unknown8;
    u32 unknownc;
    u32 unknown10;
    u32 unknown14;
    u32 unknown18;
    u32 unknown1c;
    u32 unknown20;
    u32 unknown24;
    u32 unknown28;
    u32 unknown2c;
};

struct SurfaceInfo001aebe0 { /* derived name */
    u8 unknown0[0x10];
    u64 size; /* +0x10 */
    u8 unknown18[0x20];
};

struct Surface001aebe0 { /* derived name */
    u8 unknown0[0x20];
    u32 unknown20; /* +0x20: the last level in bits 13 to 23 */
};

int FUN_001adf20(SurfaceParams001aebe0 *params, const Surface001aebe0 *surface,
                 u32 level);                                                      /* derived name */
int FUN_001a44e0(SurfaceInfo001aebe0 *info, const SurfaceParams001aebe0 *params); /* derived name */

int FUN_001aebe0(u64 *total, u64 *size, const Surface001aebe0 *surface,
                 u32 level) /* derived name */
{
    if (!surface)
        return 0x80d30000;
    SurfaceParams001aebe0 params;
    FUN_001adf20(&params, surface, level);
    SurfaceInfo001aebe0 info = {};
    if (level >= ((surface->unknown20 >> 13) & 0x7ff) + 1)
        return 0x80d30000;
    FUN_001a44e0(&info, &params);
    u64 levelSize = info.size;
    if (total)
        *total = (u64)level * levelSize;
    if (size)
        *size = levelSize;
    return 0;
}

struct Surface001aecb0 { /* derived name */
    u8 unknown0[0x20];
    u32 unknown20; /* +0x20: the last level in bits 13 to 23 */
};

struct Surface001aeb10 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc; /* +0xc: the last level in bits 13 to 23 */
};

int FUN_001ae0b0(SurfaceParams001aebe0 *params, const Surface001aecb0 *surface,
                 u32 level); /* derived name */
int FUN_001add40(SurfaceParams001aebe0 *params, const Surface001aeb10 *surface,
                 u32 level); /* derived name */

int FUN_001aecb0(u64 *total, u64 *size, const Surface001aecb0 *surface,
                 u32 level) /* derived name */
{
    if (!surface)
        return 0x80d30000;
    SurfaceParams001aebe0 params;
    FUN_001ae0b0(&params, surface, level);
    SurfaceInfo001aebe0 info = {};
    if (level >= ((surface->unknown20 >> 13) & 0x7ff) + 1)
        return 0x80d30000;
    FUN_001a44e0(&info, &params);
    u64 levelSize = info.size;
    if (total)
        *total = (u64)level * levelSize;
    if (size)
        *size = levelSize;
    return 0;
}

int FUN_001aeb10(u64 *total, u64 *size, const Surface001aeb10 *surface,
                 u32 level) /* derived name */
{
    if (!surface)
        return 0x80d30000;
    SurfaceParams001aebe0 params;
    FUN_001add40(&params, surface, level);
    SurfaceInfo001aebe0 info = {};
    if (level >= ((surface->unknownc >> 13) & 0x7ff) + 1)
        return 0x80d30000;
    FUN_001a44e0(&info, &params);
    u64 levelSize = info.size;
    if (total)
        *total = (u64)level * levelSize;
    if (size)
        *size = levelSize;
    return 0;
}
