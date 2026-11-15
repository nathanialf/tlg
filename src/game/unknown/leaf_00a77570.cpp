/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b2388.h"

/* derived name: the constructor (FUN_00a773b0, C1; called by the creator
 * FUN_00a73ff0): the base built from the name, the vptr, the names empty,
 * the arrays empty (each lock word stored apart); then the body: the 25
 * words from +0x30 cleared, the three names released (each reloaded: the
 * arrays' lock words are atomic stores), the ints and the aligned value
 * after them cleared */
Object016b2388::Object016b2388(const Name &name) : Object016b9108(name)
{
    memset(unknown30, 0, sizeof(unknown30));
    name94.release();
    name98.release();
    name9c.release();
    unknowna0 = 0;
    unknowna4 = 0;
    unknowna8 = 0;
    unknownac = 0;
    unknownb0 = 0;
    unknownb4 = 0;
    unknownb8 = 0;
    unknownbc = 0;
    unknownc0 = 0;
    unknownd0.set(0.0f, 0.0f, 0.0f, 0.0f);
    unknowne0 = 0;
    unknownf0 = 0;
    unknownf4 = 0;
    unknownf8 = 0;
    unknownfc = 0;
    unknown100 = 0;
    unknown104 = 0;
    unknown108 = 0;
    unknown10c = 0;
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00a77730, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b2388::~Object016b2388() {}
