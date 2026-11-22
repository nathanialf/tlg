/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jscomputecontext.h"
#include "tlg_game_object016c3be0.h"
#include "tlg_game_surface001af030.h"

/* AsyncMap (the report's name for the function): a buffer maps at its
 * descriptor's address, its size the stride (1 when 0) times the count; a
 * texture at its memory plus its surface's offset, with the surface's
 * width and depth. */
void JsComputeContext::AsyncMap(Object016c3be0 *resource, JsMappedSubresource *mapped)
{
    int dim = resource->state124;
    ANZU_ASSERT(JS_COMPUTE_CONTEXT_CPP, 651, dim != JS_RESOURCE_DIMENSION_UNKNOWN);
    if (dim == JS_RESOURCE_DIMENSION_BUFFER) {
        const u32 *regs = resource->descriptor;
        mapped->pData =
            reinterpret_cast<void *>((static_cast<u64>(regs[1]) & 0xfff) << 32 | regs[0]);
        u32 stride = (regs[1] >> 16) & 0x3fff;
        mapped->RowPitch = (stride ? stride : 1) * regs[2];
        mapped->DepthPitch = 0;
    } else {
        u64 offset;
        u64 size;
        FUN_001ae8e0(&offset, &size, resource->textureRegs70, 0, 0);
        Surface001af030 surface;
        FUN_001ada10(&surface, resource->textureRegs70, 0, 0);
        mapped->pData = reinterpret_cast<void *>(reinterpret_cast<u64>(resource->entry30) + offset);
        mapped->RowPitch = surface.width;
        mapped->DepthPitch = surface.depth;
    }
}
