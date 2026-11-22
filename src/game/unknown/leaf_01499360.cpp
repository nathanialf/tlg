/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_jsdevicecontext.h"
#include "tlg_game_object05adaaa8.h"

/* JsVolatileMemory::AllocateInArc (leaf_01305ce0.cpp, a draft): called by
 * its address until it has a row */
u64 FUN_01305ce0(JsVolatileMemory *memory, u32 size, u32 alignment);

/* derived names: the table at 0x1525560 of alignments, one int for each
 * index (declared; its content not claimed) */
extern const int D_1525560[];

/* derived name: an allocation from the device's volatile memory, its
 * alignment the table's at the index the second argument gives (unsigned:
 * zero-extended), a tail call. The context itself is not read. */
u64 JsDeviceContext::allocateVolatile(u32 size, unsigned alignment)
{
    int value = D_1525560[alignment];
    return FUN_01305ce0(D_5adaaa8->volatileMemory, size, value);
}
