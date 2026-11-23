/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8fd0.h"
#include "tlg_libc.h"

/* derived names: the destructors of the classes at 0x16b8fd0 and 0x16b8828
 * (tlg_game_object016b8fd0.h), each its class's key function. */
Object016b8fd0::~Object016b8fd0()
{
    FUN_00cb33a0();
}

Object016b8828::~Object016b8828()
{
    if (D_593a938)
        FUN_00c822d0(D_593a938, this);
}

// NONMATCHING: the place of the load of +0x80 only: the base reads it after
// the three constant stores and does not merge them (`mov dword` at +0xa8,
// +0xac, +0xb0); here it is read before them (the four lanes set as one
// value); the lanes set one by one read it after them but merge +0xa8 and
// +0xac into one quadword store (248 bytes); 57/61, 253 bytes
int Object016b8fd0::slot10()
{
    if (!unknown50)
        return 0;
    const unsigned count = width * height;
    float *pair = pairs;
    u32 *cell = cells;
    memset(pair, 0, count * 2 * sizeof(float));
    for (unsigned i = 0; i < count; ++i)
        cell[i] = 0xff80ff80;
    unknowna8 = Float4(0.0f, 1.0f, 0.0f, unknown80);
    return 1;
}
