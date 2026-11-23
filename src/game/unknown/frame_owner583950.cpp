/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* The 'XAIT' owner the walk handlers build again below a node
 * (FUN_00c020e0, FUN_00c01cc0, FUN_0058c560): a unit of its own, so the
 * link inlines it after the unit stage and the copies are vectorised in the
 * caller only after its stores are compared (derived name) */
FrameOwnerBase583950::FrameOwnerBase583950(const FrameOwnerBase583950 &builder,
                                           NodeList583950 *list, void *unknown100_)
    : Owner583950(builder.code, builder.parentCode, list ? list : builder.cursor.list,
                  builder.unknown18, builder.handlers, builder.unknown28),
      unknownf0(builder.unknownf0), unknownf4(builder.unknownf4), unknownf8(builder.unknownf8),
      unknown100(unknown100_ ? unknown100_ : builder.unknown100), unknown108(builder.unknown108),
      frame(builder.frame), unknown118(builder.unknown118), unknown120(builder.unknown120),
      unknown128(builder.unknown128), unknown130(builder.unknown130),
      unknown138(builder.unknown138), unknown140(builder.unknown140),
      unknown148(builder.unknown148), unknown150(builder.unknown150),
      valueHandlers(builder.valueHandlers), unknown160(builder.unknown160),
      unknown168(builder.unknown168), unknown170(builder.unknown170),
      unknown178(builder.unknown178), unknown180(builder.unknown180)
{
    timeStep = builder.timeStep;
}
