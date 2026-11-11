/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: six wrappers that copy a whole image of a surface: each
 * builds the box from the origin to the surface's width, height and depth
 * and calls the copy that follows it (FUN_001aace0 and on: the surface, two
 * buffers passed through, the box, then the row pitch, the width, and the
 * slice pitch, width times height, as their last arguments), returning its
 * result. The three pairs read the extent at +0xc, +0x10 and +0x18 of three
 * surface records. */
struct Box001aac80 /* derived name */
{
    u32 left;   /* +0x0 */
    u32 top;    /* +0x4 */
    u32 front;  /* +0x8 */
    u32 right;  /* +0xc */
    u32 bottom; /* +0x10 */
    u32 back;   /* +0x14 */
};

struct Surface001aac80 /* derived name */
{
    u8 unknown0[0xc];
    u32 width;  /* +0xc */
    u32 height; /* +0x10 */
    u32 depth;  /* +0x14 */
};

struct Surface001aba90 /* derived name */
{
    u8 unknown0[0x10];
    u32 width;  /* +0x10 */
    u32 height; /* +0x14 */
    u32 depth;  /* +0x18 */
};

struct Surface001ad250 /* derived name */
{
    u8 unknown0[0x18];
    u32 width;  /* +0x18 */
    u32 height; /* +0x1c */
    u32 depth;  /* +0x20 */
};

int FUN_001aace0(const Surface001aac80 *surface, void *destination, const void *source,
                 const Box001aac80 *box, u32 rowPitch, u32 slicePitch); /* derived name */

int FUN_001aac80(const Surface001aac80 *surface, void *destination,
                 const void *source) /* derived name */
{
    Box001aac80 box;
    box.left = box.top = box.front = 0;
    box.right = surface->width;
    box.bottom = surface->height;
    box.back = surface->depth;
    return FUN_001aace0(surface, destination, source, &box, surface->width,
                        surface->width * surface->height);
}

int FUN_001ab100(const Surface001aac80 *surface, void *destination, const void *source,
                 const Box001aac80 *box, u32 rowPitch, u32 slicePitch); /* derived name */

int FUN_001ab0a0(const Surface001aac80 *surface, void *destination,
                 const void *source) /* derived name */
{
    Box001aac80 box;
    box.left = box.top = box.front = 0;
    box.right = surface->width;
    box.bottom = surface->height;
    box.back = surface->depth;
    return FUN_001ab100(surface, destination, source, &box, surface->width,
                        surface->width * surface->height);
}

int FUN_001abaf0(const Surface001aba90 *surface, void *destination, const void *source,
                 const Box001aac80 *box, u32 rowPitch, u32 slicePitch); /* derived name */

int FUN_001aba90(const Surface001aba90 *surface, void *destination,
                 const void *source) /* derived name */
{
    Box001aac80 box;
    box.left = box.top = box.front = 0;
    box.right = surface->width;
    box.bottom = surface->height;
    box.back = surface->depth;
    return FUN_001abaf0(surface, destination, source, &box, surface->width,
                        surface->width * surface->height);
}

int FUN_001ac1d0(const Surface001aba90 *surface, void *destination, const void *source,
                 const Box001aac80 *box, u32 rowPitch, u32 slicePitch); /* derived name */

int FUN_001ac170(const Surface001aba90 *surface, void *destination,
                 const void *source) /* derived name */
{
    Box001aac80 box;
    box.left = box.top = box.front = 0;
    box.right = surface->width;
    box.bottom = surface->height;
    box.back = surface->depth;
    return FUN_001ac1d0(surface, destination, source, &box, surface->width,
                        surface->width * surface->height);
}

int FUN_001ad2b0(const Surface001ad250 *surface, void *destination, const void *source,
                 const Box001aac80 *box, u32 rowPitch, u32 slicePitch); /* derived name */

int FUN_001ad250(const Surface001ad250 *surface, void *destination,
                 const void *source) /* derived name */
{
    Box001aac80 box;
    box.left = box.top = box.front = 0;
    box.right = surface->width;
    box.bottom = surface->height;
    box.back = surface->depth;
    return FUN_001ad2b0(surface, destination, source, &box, surface->width,
                        surface->width * surface->height);
}

int FUN_001ad690(const Surface001ad250 *surface, void *destination, const void *source,
                 const Box001aac80 *box, u32 rowPitch, u32 slicePitch); /* derived name */

int FUN_001ad630(const Surface001ad250 *surface, void *destination,
                 const void *source) /* derived name */
{
    Box001aac80 box;
    box.left = box.top = box.front = 0;
    box.right = surface->width;
    box.bottom = surface->height;
    box.back = surface->depth;
    return FUN_001ad690(surface, destination, source, &box, surface->width,
                        surface->width * surface->height);
}
