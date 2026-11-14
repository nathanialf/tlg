/* src/include/tlg_game_record00f4dab0.h: the record that the classes whose
 * vtables are at 0x16bf098 and 0x16c1eb8 own through +0x10 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_RECORD00F4DAB0_H
#define TLG_GAME_RECORD00F4DAB0_H

#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object0139b6b0.h"

/* derived names: the record: its destructor releases the block at +0x60,
 * then tears down the members at +0x20 and +0x8 (FUN_00f4dab0 and
 * FUN_01210a40, the same bytes, inline it before operator delete). */
struct Record00f4dab0 /* derived name */
{
    ~Record00f4dab0()
    {
        releaseBlock(block60);
    }

    u8 unknown0[8];
    Object01347230 unknown8;  /* +0x8 */
    Object0134f620 unknown20; /* +0x20 */
    u8 unknown38[0x28];
    void *block60; /* +0x60: owned block */
};

#endif
