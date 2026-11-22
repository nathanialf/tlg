/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jscomputecontext.h"
#include "tlg_game_object016c3be0.h"
#include "tlg_game_surface001af030.h"

/* slot 19: a subresource of a resource mapped as AsyncMap maps it, -2 for
 * a resource of no dimension: a buffer at its descriptor's address, its size
 * the stride (1 when 0) times the count; a texture's subresource (its mip
 * the remainder by the texture's mip count, 1 for the types from 14 on, its
 * slice the quotient) at the memory plus its surface's offset, with that
 * surface's width and depth. The map type and flags are not read. */
// NONMATCHING: register assignment: the base keeps the texture's descriptor address in r15 across both surface queries and reads the output pointer from its stack argument again after them (an 0x48-byte frame); here the output pointer stays in r15 and the descriptor address is spilled (0x58); slot 18, its sibling with the output in a register, is equal
int JsComputeContext::slot19(Object016c3be0 *resource, u32 subresource, u32 mapType, u32 mapFlags,
                             void *unused, JsMappedSubresource *mapped)
{
    int result = -2;
    int dim = resource->state124;
    if (dim != JS_RESOURCE_DIMENSION_UNKNOWN) {
        if (dim == JS_RESOURCE_DIMENSION_BUFFER) {
            const u32 *regs = resource->descriptor;
            mapped->pData =
                reinterpret_cast<void *>((static_cast<u64>(regs[1]) & 0xfff) << 32 | regs[0]);
            u32 stride = (regs[1] >> 16) & 0x3fff;
            mapped->RowPitch = (stride ? stride : 1) * regs[2];
            mapped->DepthPitch = 0;
        } else {
            const u32 *texture = resource->textureRegs70;
            u32 lastMip = ((texture[3] >> 16) & 0xf) + 1;
            u32 mips = (texture[3] >> 28) >= 14 ? 1 : lastMip;
            u32 mip = subresource % mips;
            u32 slice = subresource / mips;
            u64 offset;
            u64 size;
            FUN_001ae8e0(&offset, &size, texture, mip, slice);
            Surface001af030 surface;
            FUN_001ada10(&surface, texture, mip, slice);
            mapped->pData =
                reinterpret_cast<void *>(reinterpret_cast<u64>(resource->entry30) + offset);
            mapped->RowPitch = surface.width;
            mapped->DepthPitch = surface.depth;
        }
        result = 0;
    }
    return result;
}
