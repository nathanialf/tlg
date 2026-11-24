/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* FUN_00afd2e0: the camera's reference is reached through camera(index): the
 * index is extended in its body, after the global and its cameras are
 * loaded (a subscript emits its index first), which gives the base's rax for
 * the cameras and rcx for the index. */
#include "tlg_game_object016c7d08.h"

Object016c7d08::Object016c7d08(const Name &name, int index)
    : Object016b9108(name), cameras28(0), index30(index), unknown34(2), entries48(0), unknown50(0),
      unknown58(-1), unknown5c(1)
{
    D_57c9390->cameras40->camera(index).set(this);
    cameras28 = D_57c9390->cameras40;
    unknown38 = 0;
}

/* the complete destructor; FUN_00afd6a0, slot 1, is the deleting one */
Object016c7d08::~Object016c7d08()
{
    freeEntries();
    if (D_57c9390 && D_57c9390->cameras40)
        D_57c9390->cameras40->camera(index30).clear();
}

/* the 0xb0-byte entries at +0x48 (an array new's count 8 bytes before the
 * first, the block 16 before: the entry is aligned to 16; each entry's
 * counted reference at +0x98 dropped, last entry first), then the array at
 * +0x50, whose elements have no destructor */
void Object016c7d08::freeEntries()
{
    if (entries48) {
        delete[] entries48;
        entries48 = 0;
    }
    if (unknown50) {
        delete[] unknown50;
        unknown50 = 0;
    }
}
