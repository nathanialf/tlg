/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: two surface copies over the whole surface: refuse a null
 * record with 0x80d30000, build the region from the origin to the record's
 * width, height and depth (+0x8, +0xc, +0x10), measured in blocks when the
 * record says its format is block compressed (the byte at +0x2c, the bits
 * of an element at +0x28: 1 a block of 8 elements across, 4 and 8 a block
 * of 4 by 4, 16 one element; any other refused), and hand the region with
 * its pitch and the size of one slice to FUN_001aed80 (FUN_001af030) or
 * FUN_001af110 (FUN_001af3c0), the region by address. */
struct SurfaceRegion001af030 { /* derived name */
    u32 left;                  /* +0x0 */
    u32 top;                   /* +0x4 */
    u32 front;                 /* +0x8 */
    u32 width;                 /* +0xc */
    u32 height;                /* +0x10 */
    u32 depth;                 /* +0x14 */
};

struct Surface001af030 { /* derived name */
    u8 unknown0[0x8];
    u32 width;  /* +0x8 */
    u32 height; /* +0xc */
    u32 depth;  /* +0x10 */
    u8 unknown14[0x14];
    int bitsPerElement; /* +0x28 */
    bool compressed;    /* +0x2c */
};

int FUN_001aed80(void *destination, const void *source, const Surface001af030 *surface,
                 const SurfaceRegion001af030 *region, u32 pitch, u32 slicePitch); /* derived name */
int FUN_001af110(void *destination, const void *source, const Surface001af030 *surface,
                 const SurfaceRegion001af030 *region, u32 pitch, u32 slicePitch); /* derived name */

/* derived name: the region of the whole surface, in blocks when compressed;
 * false for an element size it does not know */
static inline bool wholeSurface(SurfaceRegion001af030 *region, const Surface001af030 *surface)
{
    region->left = region->top = region->front = 0;
    region->width = surface->width;
    region->height = surface->height;
    region->depth = surface->depth;
    if (surface->compressed) {
        switch (surface->bitsPerElement) {
        case 1:
            region->left = region->left / 8;
            region->width = (region->width + 7) / 8;
            break;
        case 4:
        case 8:
            region->left = region->left / 4;
            region->top = region->top / 4;
            region->width = (region->width + 3) / 4;
            region->height = (region->height + 3) / 4;
            break;
        case 16:
            break;
        default:
            return false;
        }
    }
    return true;
}

// NONMATCHING: block placement: the base puts the case-1 body right after its compare
// (`cmp ecx, 1; jne` falling into it) and tests 4 after the cases above 7; the build lays
// the case-1 body out last (`je` to it), in either order of the cases
int FUN_001af030(void *destination, const void *source,
                 const Surface001af030 *surface) /* derived name */
{
    if (!surface)
        return 0x80d30000;
    SurfaceRegion001af030 region;
    if (!wholeSurface(&region, surface))
        return 0x80d30000;
    return FUN_001aed80(destination, source, surface, &region, region.width,
                        region.width * region.height);
}

// NONMATCHING: block placement: the base puts the case-1 body right after its compare
// (`cmp ecx, 1; jne` falling into it) and tests 4 after the cases above 7; the build lays
// the case-1 body out last (`je` to it), in either order of the cases
int FUN_001af3c0(void *destination, const void *source,
                 const Surface001af030 *surface) /* derived name */
{
    if (!surface)
        return 0x80d30000;
    SurfaceRegion001af030 region;
    if (!wholeSurface(&region, surface))
        return 0x80d30000;
    return FUN_001af110(destination, source, surface, &region, region.width,
                        region.width * region.height);
}
