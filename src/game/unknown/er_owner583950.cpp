/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* The 'XAER' owner the walk handlers build below a node (FUN_00c06790,
 * FUN_00c06460): a unit of its own, as the 'XAIT' owner's
 * (frame_owner583950.cpp), so the link inlines it after the unit stage: the
 * ring walk's count is widened for its loop before the owner's field
 * addresses are hoisted (`mov r12d, r8d` above `lea r14, [rbp-0x208]` at
 * 0xc06572) (derived name) */
ErOwner00c06790::ErOwner00c06790(const DeviceOwner583950 &builder, NodeList583950 *list)
    : DeviceOwner583950(fourCharCode('X', 'A', 'E', 'R'), builder.parentCode, list,
                        builder.unknown18, builder.handlers, 0, builder.device)
{
}
